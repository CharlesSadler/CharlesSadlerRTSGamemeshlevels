#ifndef __MENU_h_
#define __MENU_h_

#include <Terrain/OgreTerrain.h>
#include <Terrain/OgreTerrainGroup.h>
#include <OgreRectangle2D.h>
#include "OgreApplication.h"

#include "myCEGUI.h"

#include <Ogre.h>
#include <CEGUI.h>
#include <RendererModules/Ogre/CEGUIOgreRenderer.h>

//Ogre::Real = Ogre::SceneManager.getCurrentViewport()->getTarget()->getAverageFPS();

class Menu{
public:
	static void createBackground();
	static CEGUI::Window* startGame();
	static CEGUI::Window* exitGame();
	static CEGUI::Window* stage2();
	static CEGUI::Window* FPS();
};
#endif