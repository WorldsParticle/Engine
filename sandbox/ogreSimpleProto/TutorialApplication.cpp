/*
   -----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
___                 __    __ _ _    _
/___\__ _ _ __ ___  / / /\ \ (_) | _(_)
//  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
|___/
Tutorial Framework
http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/
#include "TutorialApplication.h"

//-------------------------------------------------------------------------------------
TutorialApplication::TutorialApplication()
    : /*mTerrainGroup(0), mTerrainGlobals(0), mInfoLabel(0),*/
    mRotate(.13), mMove(250), mCamNode(0), mDirection(Ogre::Vector3::ZERO), _terrain() {
}
//-------------------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void) {
}

//-------------------------------------------------------------------------------------
void TutorialApplication::createScene(void) {
    /* 4 heads
       mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
       Ogre::Light* light = mSceneMgr->createLight("MainLight");
       light->setPosition(20, 80, 50); //the 0,0,0 is bottom left
       mCamera->setPosition(0, 47, 222);

       Ogre::Entity* ogreEntity = mSceneMgr->createEntity("ogrehead.mesh");
       Ogre::SceneNode* ogreNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
       ogreNode->attachObject(ogreEntity);

       Ogre::Entity* ogreEntity2 = mSceneMgr->createEntity("ogrehead.mesh");
       Ogre::SceneNode* ogreNode2 = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(84, 48, 0));
       ogreNode2->attachObject(ogreEntity2);

       Ogre::Entity* ogreEntity3 = mSceneMgr->createEntity("ogrehead.mesh");
       Ogre::SceneNode* ogreNode3 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
       ogreNode3->setPosition(0, 104, 0);
       ogreNode3->setScale(2, 1.2, 1);
       ogreNode3->attachObject(ogreEntity3);

       Ogre::Entity* ogreEntity4 = mSceneMgr->createEntity("ogrehead.mesh");
       Ogre::SceneNode* ogreNode4 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
       ogreNode4->setPosition(-84, 48, 0);
       ogreNode4->roll(Ogre::Degree(-90));
       ogreNode4->attachObject(ogreEntity4);
       */

    /* lights with plane
       Ogre::Entity* ninjaEntity = mSceneMgr->createEntity("ogrehead.mesh");
       ninjaEntity->setCastShadows(true);
       mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ninjaEntity);
       Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
       Ogre::MeshManager::getSingleton().createPlane("ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane, 1500, 1500, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);
       Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
       mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
       groundEntity->setCastShadows(false);
       groundEntity->setMaterialName("Ogre");

       mSceneMgr->setAmbientLight(Ogre::ColourValue(0, 0, 0));
       mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

       Ogre::Light* spotLight = mSceneMgr->createLight("SpotLight");
       spotLight->setDiffuseColour(0, 0, 1.0);
       spotLight->setSpecularColour(0, 0, 1.0);
       spotLight->setType(Ogre::Light::LT_SPOTLIGHT);
       spotLight->setDirection(-1, -1, 0);
       spotLight->setPosition(Ogre::Vector3(200, 200, 0));
       spotLight->setSpotlightRange(Ogre::Degree(35), Ogre::Degree(50));

       Ogre::Light* directionalLight = mSceneMgr->createLight("DirectionalLight");
       directionalLight->setType(Ogre::Light::LT_DIRECTIONAL);
       directionalLight->setDiffuseColour(Ogre::ColourValue(.4, 0, 0));
       directionalLight->setSpecularColour(Ogre::ColourValue(.4, 0, 0));
       directionalLight->setDirection(Ogre::Vector3(0, -1, 1));

       Ogre::Light* pointLight = mSceneMgr->createLight("PointLight");
       pointLight->setType(Ogre::Light::LT_POINT);
       pointLight->setDiffuseColour(.3, .3, .3);
       pointLight->setSpecularColour(.3, .3, .3);
       pointLight->setPosition(Ogre::Vector3(0, 150, 250));
       */

    /* terrain */
    Ogre::Entity* tudorEntity = mSceneMgr->createEntity("tudorhouse.mesh");
    Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode(
	    "TudorNode");
    node->attachObject(tudorEntity);
    node = mSceneMgr->getRootSceneNode()->createChildSceneNode(
	    "CamNode1", Ogre::Vector3(1200, -370, 0));
    node->yaw(Ogre::Degree(90));
    mCamNode = node;
    node->attachObject(mCamera);
    node = mSceneMgr->getRootSceneNode()->createChildSceneNode(
	    "CamNode2", Ogre::Vector3(-500, -370, 1000));
    node->yaw(Ogre::Degree(-30));
    //mCamera->setPosition(Ogre::Vector3(1683, 50, 2116));
    //mCamera->lookAt(Ogre::Vector3(1963, 50, 1660));
    //mCamera->setNearClipDistance(0.1);
    //bool infiniteClip = mRoot->getRenderSystem()->getCapabilities()->hasCapability(Ogre::RSC_INFINITE_FAR_PLANE);
    //if (infiniteClip) {
    //    mCamera->setFarClipDistance(0);
    //} else {
    //    mCamera->setFarClipDistance(50000);
    //}

    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2));
    Ogre::Vector3 lightdir(0.55, -0.3, 0.75);
    lightdir.normalise();

    Ogre::Light* light = mSceneMgr->createLight("TestLight");
    light->setType(Ogre::Light::LT_DIRECTIONAL);
    light->setDirection(lightdir);
    light->setDiffuseColour(Ogre::ColourValue::White);
    light->setSpecularColour(Ogre::ColourValue(0.4, 0.4, 0.4));
    light->setPosition(Ogre::Vector3(300, 150, 0));

    Ogre::ColourValue fadeColour(0.9, 0.9, 0.9);
    mWindow->getViewport(0)->setBackgroundColour(fadeColour);

    //mSceneMgr->setFog(Ogre::FOG_LINEAR, fadeColour, 0, 600, 900);
    mSceneMgr->setFog(Ogre::FOG_EXP2, fadeColour, 0.002, 600, 900);

    _terrain.createScene(light, mSceneMgr);

    //mSceneMgr->setSkyBox(true, "I DON'TKNOW WHAT TO PUT HERE", 300, false);
    // Sky Techniques
    mSceneMgr->setSkyBox(true, "stevecube");
    //mSceneMgr->setSkyDome(true, "stevecube", 5, 8);
    // Ogre::Plane plane;
    // plane.d = 1000;
    // plane.normal = Ogre::Vector3::NEGATIVE_UNIT_Y;

    // mSceneMgr->setSkyPlane(
    //   true, plane, "Examples/SpaceSkyPlane", 1500, 40, true, 1.5, 150, 150);

}

bool TutorialApplication::keyPressed(const OIS::KeyEvent& ke) {
    switch (ke.key) {
	case OIS::KC_ESCAPE:
	    mShutDown = true;
	    break;
	case OIS::KC_1:
	    mCamera->getParentSceneNode()->detachObject(mCamera);
	    mCamNode = mSceneMgr->getSceneNode("CamNode1");
	    mCamNode->attachObject(mCamera);
	    break;

	case OIS::KC_2:
	    mCamera->getParentSceneNode()->detachObject(mCamera);
	    mCamNode = mSceneMgr->getSceneNode("CamNode2");
	    mCamNode->attachObject(mCamera);
	    break;
	case OIS::KC_UP:
	case OIS::KC_W:
	    mDirection.z = -mMove;
	    break;

	case OIS::KC_DOWN:
	case OIS::KC_S:
	    mDirection.z = mMove;
	    break;

	case OIS::KC_LEFT:
	case OIS::KC_A:
	    mDirection.x = -mMove;
	    break;

	case OIS::KC_RIGHT:
	case OIS::KC_D:
	    mDirection.x = mMove;
	    break;

	case OIS::KC_PGDOWN:
	case OIS::KC_E:
	    mDirection.y = -mMove;
	    break;

	case OIS::KC_PGUP:
	case OIS::KC_Q:
	    mDirection.y = mMove;
	    break;
	default:
	    break;
    }
    return true;
}

bool TutorialApplication::keyReleased(const OIS::KeyEvent& ke) {
    switch (ke.key)
    {
	case OIS::KC_UP:
	case OIS::KC_W:
	    mDirection.z = 0;
	    break;

	case OIS::KC_DOWN:
	case OIS::KC_S:
	    mDirection.z = 0;
	    break;

	case OIS::KC_LEFT:
	case OIS::KC_A:
	    mDirection.x = 0;
	    break;

	case OIS::KC_RIGHT:
	case OIS::KC_D:
	    mDirection.x = 0;
	    break;

	case OIS::KC_PGDOWN:
	case OIS::KC_E:
	    mDirection.y = 0;
	    break;

	case OIS::KC_PGUP:
	case OIS::KC_Q:
	    mDirection.y = 0;
	    break;

	default:
	    break;
    }
    return true;
}

bool TutorialApplication::mouseMoved(const OIS::MouseEvent& me) {
    if (me.state.buttonDown(OIS::MB_Right))
    {
	mCamNode->yaw(Ogre::Degree(-mRotate * me.state.X.rel), Ogre::Node::TS_WORLD);
	mCamNode->pitch(Ogre::Degree(-mRotate * me.state.Y.rel), Ogre::Node::TS_LOCAL);
    }
    return true;
}

bool TutorialApplication::mousePressed(const OIS::MouseEvent& me, OIS::MouseButtonID id) {
    switch (id)
    {
	case OIS::MB_Left:
	    mSceneMgr->getLight("TestLight")->setVisible(!mSceneMgr->getLight("TestLight")->isVisible());
	    break;

	default:
	    break;
    }
    return true;
}

bool TutorialApplication::mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id) {
    return true;
}
/*
void TutorialApplication::createCamera() {
    mCamera = mSceneMgr->createCamera("PlayerCam");
    mCamera->setPosition(Ogre::Vector3(0, 300, 500));
    mCamera->lookAt(Ogre::Vector3(0, 0, 0));
    mCamera->setNearClipDistance(5);
    mCameraMan = new OgreBites::SdkCameraMan(mCamera);
}

void TutorialApplication::createViewports() {
    Ogre::Viewport* vp = mWindow->addViewport(mCamera);
    vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0));
    mCamera->setAspectRatio(Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
}*/

void TutorialApplication::createFrameListener() {
    BaseApplication::createFrameListener();
    _terrain.createFrameListener(mTrayMgr);
}

void TutorialApplication::destroyScene() {
    _terrain.destroyScene();
}

bool TutorialApplication::frameRenderingQueued(const Ogre::FrameEvent& fe) {
    bool ret = BaseApplication::frameRenderingQueued(fe);

    mCamNode->translate(mDirection * fe.timeSinceLastFrame, Ogre::Node::TS_LOCAL);
    _terrain.frameRenderingQueued(mTrayMgr);
    return ret;
}

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
# define WIN32_LEAN_AND_MEAN
# include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
	int main(int argc, char *argv[])
#endif
	{
	    // Create application object
	    TutorialApplication app;

	    try {
		app.go();
	    } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
		MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
		std::cerr << "An exception has occured: " <<
		    e.getFullDescription().c_str() << std::endl;
#endif
	    }
	    return 0;
	}

#ifdef __cplusplus
}
#endif
