#include "myCEGUI.h"
#include "UsefulTool.h"

void myCEGUI::implimentingCEGUI()
{
	/*
	static bool init = 0;
	if (init != 0) return;
	init = 1;
	*/

	CEGUI::SchemeManager::getSingleton().create( "TaharezLook.scheme" );
	// Set the defaults
	CEGUI::System::getSingleton().setDefaultFont( "DejaVuSans-10" );
	CEGUI::System::getSingleton().setDefaultMouseCursor( "TaharezLook", "MouseArrow" );
	
	CEGUI::Imageset::setDefaultResourceGroup("Imagesets");
	CEGUI::Font::setDefaultResourceGroup("Fonts");
	CEGUI::Scheme::setDefaultResourceGroup("Schemes");
	CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
	CEGUI::WindowManager::setDefaultResourceGroup("Layouts");
	// selects skin
	CEGUI::SchemeManager::getSingleton().create("TaharezLook.scheme");
	//default mouse cursor
	CEGUI::System::getSingleton().setDefaultMouseCursor("TaharezLook", "MouseMoveCursor");

	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
	CEGUI::Window *sheet = wmgr.createWindow("DefaultWindow", "CEGUIDemo/Sheet");
}

CEGUI::Window* myCEGUI::createButton()
{
	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
	CEGUI::Window *sheet = wmgr.getWindow("CEGUIDemo/Sheet");

	CEGUI::Window *quit = wmgr.createWindow("TaharezLook/Button", "CEGUIDemo/QuitButton");
	quit->setText("Exit");
	quit->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
	quit->setPosition(CEGUI::UVector2(CEGUI::UDim(0, 0), CEGUI::UDim(0, 0)));

	sheet->addChildWindow(quit);
	CEGUI::System::getSingleton().setGUISheet(sheet);
	
	return quit;
}

CEGUI::Window* myCEGUI::createMenuButton()
{
	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
	CEGUI::Window *sheet = wmgr.getWindow("CEGUIDemo/Sheet");

	CEGUI::Window *menu = wmgr.createWindow("TaharezLook/Button", "CEGUIDemo/MenuButton");
	menu->setText("Menu");
	menu->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
	menu->setPosition(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0, 0)));

	sheet->addChildWindow(menu);
	CEGUI::System::getSingleton().setGUISheet(sheet);
	
	return menu;

}
