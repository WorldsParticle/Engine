#ifdef USING_IRRLICHT

#include <QTimerEvent>
#include <QResizeEvent>
#include "IrrlichtWidget.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;

IrrlichtWidget::IrrlichtWidget(QWidget *parent) :
QWidget(parent),
device(NULL)
{
	// on écrit directement dans la mémoire vidéo du widget
	setAttribute(Qt::WA_PaintOnScreen);
	setAttribute(Qt::WA_OpaquePaintEvent);
	setFocusPolicy(Qt::StrongFocus);
	setAutoFillBackground(false);
}

IrrlichtWidget::~IrrlichtWidget()
{
	if (device)
	{
		device->closeDevice();
		device->drop();
	}
}

IrrlichtDevice *IrrlichtWidget::getIrrlichtDevice() const
{
	return device;
}

IVideoDriver* IrrlichtWidget::getVideoDriver() const
{
	return device->getVideoDriver();
}

ISceneManager* IrrlichtWidget::getSceneManager() const
{
	return device->getSceneManager();
}

void IrrlichtWidget::init()
{
	SIrrlichtCreationParameters params;

	// on utilise OpenGL, et on lui donne l'identifiant de la fenêtre de notre widget
	params.DriverType = EDT_OPENGL;
	params.WindowId = reinterpret_cast<void*> (winId());

	// ainsi que la taille de notre widget
	params.WindowSize.Width = width();
	params.WindowSize.Height = height();

	params.AntiAlias = true;
	params.Bits = 16;
	params.HighPrecisionFPU = false;
	params.Stencilbuffer = true;
	params.Vsync = true;

	// enfin, on initialise notre moteur de rendu
	//device = createDeviceEx(params); => a dé-commenter quand compilation via qt (sur visual sutio ca plante il ne trouve pas l'implementation

	/* une fois initialisé, on émet le signal onInit, c'est la que nous
	* ajouterons nos modèles et nos textures.
	*/
	emit onInit(this);

	if (device)
	{
		// on créé une caméra pour visualiser la scène
		camera = getSceneManager()->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));
	}

	/* puis on connecte notre slot updateIrrlicht (), qui s'occupe du rendu
	* à notre signal updateIrrlichtQuery ()
	*/
    connect(this, SIGNAL(updateIrrlichtQuery(IrrlichtWidget*)), this, SLOT(updateIrrlicht(IrrlichtWidget*)));

	// et on lance notre timer
	startTimer(0);
}

void IrrlichtWidget::updateIrrlicht(IrrlichtWidget *irrWidget)
{
	if (device)
	{
		// le rendu est donc fait ici même

		device->getTimer()->tick();

		SColor color(255, 100, 100, 140);

		getVideoDriver()->beginScene(true, true, color);
		getSceneManager()->drawAll();
		getVideoDriver()->endScene();
	}
}

void IrrlichtWidget::paintEvent(QPaintEvent *ev)
{
	if (device)
	{
		/* lorsque le widget demande a être affiché, on emet le signal updateIrrlichtQuery (),
		* ainsi, notre slot updateIrrlicht () sera appelé.
		*/
		emit updateIrrlichtQuery(this);
	}
}

void IrrlichtWidget::timerEvent(QTimerEvent *ev)
{
	if (device)
	{
		// pareil que pour la méthode paintEvent ()
		emit updateIrrlichtQuery(this);
	}

	ev->accept();
}

void IrrlichtWidget::resizeEvent(QResizeEvent *ev)
{
	if (device)
	{
		// lors d'un redimensionnement, on récupe la nouvelle taille du widget
		dimension2d<u32> widgetSize;

		widgetSize.Width = ev->size().width();
		widgetSize.Height = ev->size().height();

		// et on précise à Irrlicht la nouvelle taille.
		getVideoDriver()->OnResize(widgetSize);
	}

	QWidget::resizeEvent(ev);
}

#endif // USING_IRRLICHT
