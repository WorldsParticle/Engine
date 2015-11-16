#ifndef IRRLICHTWIDGET_HPP
#define IRRLICHTWIDGET_HPP

#ifdef USING_IRRLICHT

#include <QWidget>
#include <irrlicht.h>

class IrrlichtWidget : public QWidget
{
	Q_OBJECT

public:
	explicit IrrlichtWidget(QWidget *parent = 0);
	~IrrlichtWidget();

	irr::IrrlichtDevice *getIrrlichtDevice() const;
	irr::video::IVideoDriver *getVideoDriver() const;
	irr::scene::ISceneManager *getSceneManager() const;

	void init();

signals:
	void onInit(IrrlichtWidget *irrWidget);
	void updateIrrlichtQuery(IrrlichtWidget *irrWidget);

	public slots:
	void updateIrrlicht(IrrlichtWidget *irrWidget);

protected:
	virtual void paintEvent(QPaintEvent *ev);
	virtual void timerEvent(QTimerEvent *ev);
	virtual void resizeEvent(QResizeEvent *ev);

private:
	irr::IrrlichtDevice *device;
	irr::scene::ICameraSceneNode *camera;
};

#endif // USING_IRRLICHT

#endif // QIRRLICHTWIDGET_HPP
