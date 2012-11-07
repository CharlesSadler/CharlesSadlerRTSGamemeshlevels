#ifndef __Game_h_
#define __Game_h_

#include "TerrainLevel.h"
#include "meshLevel2.h"
#include "UsefulTool.h"
#include "OgreApplication.h"
#include "myCEGUI.h"
#include "Menu.h"
#include "meshLevels.h"

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

};

#endif