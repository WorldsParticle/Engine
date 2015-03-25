#include <irrlicht.h>
#include "RealisticWater.h"

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#pragma comment(lib, "Irrlicht.lib")

int main()
{
	/*	Change
	**	IrrlichtDevice *device =
	**		createDevice(EDT_DIRECT3D9, dimension2d<u32>(1900, 1000), 16,
	**		false, false, false, 0);
	**	To the following to have anti aliasing:
	*/

	SIrrlichtCreationParameters params = SIrrlichtCreationParameters();
	params.AntiAlias = true;
#ifdef WIN64
	params.DriverType = video::EDT_DIRECT3D9;
#else
	params.DriverType = video::EDT_OPENGL;
#endif
	params.WindowSize = core::dimension2d<u32>(1900, 1000);
	IrrlichtDevice *device = createDeviceEx(params);

	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();

	driver->setTextureCreationFlag(video::ETCF_OPTIMIZED_FOR_QUALITY, true);

	// add camera
	scene::ICameraSceneNode* camera =
		smgr->addCameraSceneNodeFPS(0, 100.0f, 0.5f);
		//smgr->addCameraSceneNodeMaya();
	camera->setPosition(core::vector3df(-100, 200, -100));
	//camera->setPosition(core::vector3df(1000 * 2, 400 * 2, 4000 * 2));
	camera->setTarget(core::vector3df(2500 * 2, 350 * 2, 3000 * 2));
	camera->setFarValue(20000.0f);

	// disable mouse cursor
	device->getCursorControl()->setVisible(false);

	// create skybox
	driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);
	smgr->addSkyBoxSceneNode(
		driver->getTexture("../media/irrlicht2_up.jpg"),
		driver->getTexture("../media/irrlicht2_dn.jpg"),
		driver->getTexture("../media/irrlicht2_lf.jpg"),
		driver->getTexture("../media/irrlicht2_rt.jpg"),
		driver->getTexture("../media/irrlicht2_ft.jpg"),
		driver->getTexture("../media/irrlicht2_bk.jpg"));

	// add water to scene
	RealisticWaterSceneNode* water = new RealisticWaterSceneNode(smgr, 8000.0f, 8000.0f, "../RealisticWaterSceneNode-master");
	water->setMaterialFlag(video::EMF_FOG_ENABLE, true);
	smgr->getRootSceneNode()->addChild(water);

	/*// add goblin mesh
	IAnimatedMesh* mesh = smgr->getMesh("../media/Mixamo_Goblin.obj");
	IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh);
	node->setMaterialFlag(EMF_LIGHTING, false);
	node->setMD2Animation(scene::EMAT_STAND);
	node->setMaterialTexture(0, driver->getTexture("../media/goblin_diffuse.tga"));*/

	// add terrain scene node
	scene::ITerrainSceneNode* terrain = smgr->addTerrainSceneNode(
	"../media/terrain-heightmap.bmp");

	terrain->setPosition(core::vector3df(-4800, -200, -4800));

	terrain->setScale(core::vector3df(40, 4.4f, 40));
	terrain->setMaterialFlag(video::EMF_LIGHTING, false);

	terrain->setMaterialTexture(0, driver->getTexture("../media/terrain-texture.jpg"));
	terrain->setMaterialTexture(1, driver->getTexture("../media/detailmap3.jpg"));

	terrain->setMaterialType(video::EMT_DETAIL_MAP);
	terrain->scaleTexture(1.0f, 20.0f);

	// create triangle selector for the terrain
	scene::ITriangleSelector* selector =
	smgr->createTerrainTriangleSelector(terrain, 0);
	terrain->setTriangleSelector(selector);

	// create collision response animator and attach it to the camera
	scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
	selector, camera, core::vector3df(30, 50, 30),
	core::vector3df(0, -10, 0),
	core::vector3df(0, 30, 0));
	selector->drop();
	camera->addAnimator(anim);
	anim->drop();

	driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);

	int lastFPS = -1;

	while (device->run())
	if (device->isWindowActive())
	{
		driver->beginScene(true, true, 0);

		smgr->drawAll();
		guienv->drawAll();
		water->render();

		driver->endScene();

		// display frames per second in window title
		int fps = driver->getFPS();

		if (lastFPS != fps)
		{
			core::stringw str = L"Terrain Renderer - Irrlicht Engine [";
			str += driver->getName();
			str += "] FPS:";
			str += fps;
			device->setWindowCaption(str.c_str());
			lastFPS = fps;
		}
	}

	device->drop();

	return 0;
}
