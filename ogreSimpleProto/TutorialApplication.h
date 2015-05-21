/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.h
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
#ifndef __TutorialApplication_h_
# define __TutorialApplication_h_

# include <Terrain/OgreTerrain.h>
# include <Terrain/OgreTerrainGroup.h>
# include "BaseApplication.h"

class TutorialApplication : public BaseApplication
{
    private:
	void defineTerrain(long x, long y);
	void initBlendMaps(Ogre::Terrain* terrain);
	void configureTerrainDefaults(Ogre::Light* light);
	bool mTerrainsImported;
	Ogre::TerrainGroup* mTerrainGroup;
	Ogre::TerrainGlobalOptions* mTerrainGlobals;
	OgreBites::Label* mInfoLabel;

	virtual bool keyPressed(const OIS::KeyEvent& ke);
	virtual bool keyReleased(const OIS::KeyEvent& ke);
	virtual bool mouseMoved(const OIS::MouseEvent& me);
	virtual bool mousePressed(const OIS::MouseEvent& me, OIS::MouseButtonID id);
	virtual bool mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id);

	Ogre::Real mRotate;
	Ogre::Real mMove;
	Ogre::SceneNode* mCamNode;
	Ogre::Vector3 mDirection;
    protected:
        virtual void createScene(void);
        //virtual void createCamera();
        //virtual void createViewports();

	virtual void createFrameListener();
	virtual void destroyScene();
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);
    public:
        TutorialApplication(void);
        virtual ~TutorialApplication(void);
};

#endif // #ifndef __TutorialApplication_h_
