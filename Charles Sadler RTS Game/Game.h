#ifndef __Game_h_
#define __Game_h_


#include <stdlib.h>
#include <iostream>

using namespace std;

#include "sdl.h"
#include "sdl_mixer.h"

#include "audiomanager.h"
#include "TerrainLevel.h"
#include "meshLevel2.h"
#include "UsefulTool.h"
#include "OgreApplication.h"
#include "myCEGUI.h"
#include "Menu.h"
#include "meshLevels.h"

#include <deque>

class Game : public OgreApplication
{
private:
    Ogre::TerrainGlobalOptions* mTerrainGlobals;
    Ogre::TerrainGroup* mTerrainGroup;
	CEGUI::Window *FPS;
	float _fpsCounter;

public:
    Game(void);
    virtual ~Game(void);
	virtual bool upDate(void);

protected:
    virtual void createScene(void);
	virtual void createFrameListener(void);
    virtual void destroyScene(void);
	virtual bool nextLocation(void);
 	bool setup(void)
	{
		if (!OgreApplication::setup())
			return false;

		Storage::GetSingleton().AddItem( "Ogre_SceneMgr", (void*)mSceneMgr );
		Storage::GetSingleton().AddItem( "Ogre_mCamera", (void*)mCamera );
		Storage::GetSingleton().AddItem( "Ogre_mRoot", (void*)mRoot );
		Storage::GetSingleton().AddItem( "Ogre_mWindow", (void*)mWindow );

		return true;
	}
    
	// OIS::KeyListener
    virtual bool keyPressed( const OIS::KeyEvent &arg );
    virtual bool keyReleased( const OIS::KeyEvent &arg );
    // OIS::MouseListener
    virtual bool mouseMoved( const OIS::MouseEvent &arg );
    virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
    virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
 
    bool quit(const CEGUI::EventArgs &e);
	bool menu(const CEGUI::EventArgs &e);
	bool start(const CEGUI::EventArgs &e);
	bool stage2(const CEGUI::EventArgs &e);
	bool fps(const CEGUI::EventArgs &e);

	Ogre::Real mDistance;                  // The distance the object has left to travel
    Ogre::Vector3 mDirection;              // The direction the object is moving
    Ogre::Vector3 mDestination;            // The destination the object is moving towards
 
    Ogre::AnimationState *mAnimationState; // The current animation state of the object
 
    Ogre::Entity *mEntity;                 // The Entity we are animating
    Ogre::SceneNode *mNode;                // The SceneNode that the Entity is attached to
    std::deque<Ogre::Vector3> mWalkList;   // The list of points we are walking to
 
    Ogre::Real mWalkSpeed;                 // The speed at which the object is moving

};

#endif