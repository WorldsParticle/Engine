#ifndef GENERATETERRAIN_H_
# define GENERATETERRAIN_H_

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include <SdkTrays.h>
#include <SdkCameraMan.h>
# include <Terrain/OgreTerrain.h>
# include <Terrain/OgreTerrainGroup.h>

class GenerateTerrain {
    private:
	void defineTerrain(long x, long y);
	void initBlendMaps(Ogre::Terrain* terrain);
	void configureTerrainDefaults(Ogre::Light* light, Ogre::SceneManager* mSceneMgr);
	bool mTerrainsImported;
	Ogre::TerrainGroup* mTerrainGroup;
	Ogre::TerrainGlobalOptions* mTerrainGlobals;
	OgreBites::Label* mInfoLabel;
    public:
        void createScene(Ogre::Light *light, Ogre::SceneManager* mSceneMgr);
	void createFrameListener(OgreBites::SdkTrayManager* mTrayMgr);
	void destroyScene();
	bool frameRenderingQueued(OgreBites::SdkTrayManager* mTrayMgr);
	GenerateTerrain();
	~GenerateTerrain();
};

#endif /* !GENERATETERRAIN_H_ */
