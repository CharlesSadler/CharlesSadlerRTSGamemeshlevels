#include"Menu.h"

void Menu::createBackground()
{
			using namespace Ogre;
			// Create background material
			MaterialPtr material = MaterialManager::getSingleton().create("Background", "General");
			material->getTechnique(0)->getPass(0)->createTextureUnitState("Oncomingstorm2.tga");
			material->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
			material->getTechnique(0)->getPass(0)->setDepthWriteEnabled(false);
			material->getTechnique(0)->getPass(0)->setLightingEnabled(false);
 
			// Create background rectangle covering the whole screen
			Rectangle2D* rect = new Rectangle2D(true);
			rect->setCorners(-1.0, 1.0, 1.0, -1.0);
			rect->setMaterial("Background");
 
			// Render the background before everything else
			rect->setRenderQueueGroup(RENDER_QUEUE_BACKGROUND);
 
			// Hacky, but we need to set the bounding box to something big
			// NOTE: If you are using Eihort (v1.4), please see the note below on setting the bounding box
			rect->setBoundingBox(AxisAlignedBox(-100000.0*Vector3::UNIT_SCALE, 100000.0*Vector3::UNIT_SCALE));

			Ogre::SceneManager* mSceneMgr = (Ogre::SceneManager*)Storage::GetSingleton().GetItem("Ogre_SceneMgr");
 
			// Attach background to the scene
			SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Background");
			node->attachObject(rect);
 
			// Example of background scrolling
			//material->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setScrollAnimation(-0.25, 0.0);
}

CEGUI::Window* Menu::startGame()
{
	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
	CEGUI::Window *sheet = wmgr.getWindow("CEGUIDemo/Sheet");

	CEGUI::Window *start = wmgr.createWindow("TaharezLook/Button", "StartGameButton");
	start->setText("Start Game");
	start->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
	start->setPosition(CEGUI::UVector2(CEGUI::UDim(0.40, 0), CEGUI::UDim(0.40, 0)));

	sheet->addChildWindow(start);
	CEGUI::System::getSingleton().setGUISheet(sheet);
	
	return start;
}

CEGUI::Window* Menu::exitGame()
{
	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
	CEGUI::Window *sheet = wmgr.getWindow("CEGUIDemo/Sheet");

	CEGUI::Window *exit = wmgr.createWindow("TaharezLook/Button", "CEGUIDemo/ExitButton");
	exit->setText("Exit");
	exit->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
	exit->setPosition(CEGUI::UVector2(CEGUI::UDim(0.40, 0), CEGUI::UDim(0.52, 0)));

	sheet->addChildWindow(exit);
	CEGUI::System::getSingleton().setGUISheet(sheet);
	
	return exit;
}
CEGUI::Window* Menu::stage2()
{
	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
	CEGUI::Window *sheet = wmgr.getWindow("CEGUIDemo/Sheet");

	CEGUI::Window *stage2 = wmgr.createWindow("TaharezLook/Button", "CEGUIDemo/Stage2Button");
	stage2->setText("Stage2");
	stage2->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
	stage2->setPosition(CEGUI::UVector2(CEGUI::UDim(0.40, 0), CEGUI::UDim(0.46, 0)));

	sheet->addChildWindow(stage2);
	CEGUI::System::getSingleton().setGUISheet(sheet);
	
	return stage2;

}/*
CEGUI::Window* Menu::FPS()
{
	// Average FPS
	Ogre::SceneManager* mSceneMgr = (Ogre::SceneManager*)Storage::GetSingleton().GetItem("Ogre_SceneMgr");
	Ogre::Real avFPS = mSceneMgr->getCurrentViewport()->getTarget()->getAverageFPS();


	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
	CEGUI::Window *sheet = wmgr.getWindow("CEGUIDemo/Sheet");

	CEGUI::Window *FPS = wmgr.createWindow("TaharezLook/Button", "CEGUIDemo/FPS");
	std::string fps;
	fps = ("FPS: %d", avFPS);
	FPS->setText(fps);
	FPS->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
	FPS->setPosition(CEGUI::UVector2(CEGUI::UDim(0.85, 0), CEGUI::UDim(0.0, 0)));

	sheet->addChildWindow(FPS);
	CEGUI::System::getSingleton().setGUISheet(sheet);
	
	return FPS;

}*/