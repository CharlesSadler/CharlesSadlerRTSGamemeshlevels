#ifndef __myCEGUI_h_
#define __myCEGUI_h_

#include <Terrain/OgreTerrain.h>
#include <Terrain/OgreTerrainGroup.h>

#include <Ogre.h>
#include <CEGUI.h>
#include <RendererModules/Ogre/CEGUIOgreRenderer.h>

typedef bool(*FunctionPtr)(const CEGUI::EventArgs);
 
class myCEGUI
{
public:
	static void implimentingCEGUI();
	static CEGUI::Window* createButton();
	static void createWindow();
	static CEGUI::Window* createMenuButton();
};
#endif