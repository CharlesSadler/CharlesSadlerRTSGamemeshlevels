/*
-----------------------------------------------------------------------------
Filename:    Game.cpp
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

#include "Game.h"
//#include <sstream>
OgreMasterTimer m_Timer;
OgreMasterTimer& timer = m_Timer;
int state = 1;
//-------------------------------------------------------------------------------------

CEGUI::MouseButton convertButton(OIS::MouseButtonID buttonID)
{
	switch (buttonID)
	{
	case OIS::MB_Left:
		return CEGUI::LeftButton;

	case OIS::MB_Right:
		return CEGUI::RightButton;

	case OIS::MB_Middle:
		return CEGUI::MiddleButton;

	default:
		return CEGUI::LeftButton;
	}
}

//-------------------------------------------------------------------------------------
Game::Game(void)
{
	mTerrainGlobals = NULL;
	mTerrainGroup = NULL;
	_fpsCounter = 0;
	AudioManager::getInstance()->addSound("AudioFiles/Song.wav", "SONG");
	AudioManager::getInstance()->addSound("AudioFiles/Fx.wav", "FX");
}
//-------------------------------------------------------------------------------------
Game::~Game(void)
{
}
void Game::createScene(void)
{	
	switch (state)
	{
	case 1:
		{

			Menu::createBackground();
			AudioManager::getInstance()->playSound("FX");
			myCEGUI::implimentingCEGUI();
			Menu::startGame()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Game::start, this));
			Menu::exitGame()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Game::quit, this));
			Menu::stage2()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Game::stage2, this));
			//Menu::FPS();
			float avFPS;
			avFPS = 0;//mWindow->getAverageFPS();
			
			//avFPS = mSceneMgr->getCurrentViewport()->getTarget()->getAverageFPS();

			CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
			CEGUI::Window *sheet = wmgr.getWindow("CEGUIDemo/Sheet");
	
			FPS = wmgr.createWindow("TaharezLook/Button", "CEGUIDemo/FPS");
			char fps[20];
			sprintf(fps, "FPS: %d", avFPS);
			FPS->setText(fps);
			FPS->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
			FPS->setPosition(CEGUI::UVector2(CEGUI::UDim(0.85, 0), CEGUI::UDim(0.0, 0)));

			sheet->addChildWindow(FPS);
			CEGUI::System::getSingleton().setGUISheet(sheet);

			

			break;
		}
	case 2:
		{
			myCEGUI::implimentingCEGUI();
			myCEGUI::createButton()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Game::quit, this));
			myCEGUI::createMenuButton()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Game::menu, this));
			AudioManager::getInstance()->playSound("SONG");

			MeshLevel2::createLevel();

			break;
				}
	case 3:
		{
			myCEGUI::implimentingCEGUI();
			myCEGUI::createButton()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Game::quit, this));
			myCEGUI::createMenuButton()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Game::menu, this));

			MeshLevel1::createLevel();			
		break;
		}
	}
}

void Game::destroyScene(void)
{
	AudioManager::getInstance()->stopSound();
	OGRE_DELETE mTerrainGroup;
	OGRE_DELETE mTerrainGlobals;

	CEGUI::System::getSingleton().getGUISheet()->destroy();
	
	mSceneMgr->clearScene();

}
//-------------------------------------------------------------------------------------

void Game::createFrameListener(void)
{
	Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
	OIS::ParamList pl;
	size_t windowHnd = 0;
	std::ostringstream windowHndStr;

	mWindow->getCustomAttribute("WINDOW", &windowHnd);
	windowHndStr << windowHnd;
	pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

	mInputManager = OIS::InputManager::createInputSystem( pl );

	mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, true ));
	mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, true ));

	mMouse->setEventCallback(this);
	mKeyboard->setEventCallback(this);

	//Set initial mouse clipping size
	windowResized(mWindow);

	//Register as a Window listener
	Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);

	mRoot->addFrameListener(this);
	OgreApplication::createFrameListener();
	// mInfoLabel = mTrayMgr->createLabel(OgreBites::TL_TOP, "TInfo", "", 350);
}
//-------------------------------------------------------------------------------------
bool Game::nextLocation(void)
{
	return true;
}


//-------------------------------------------------------------------------------------
bool Game::keyPressed(const OIS::KeyEvent &arg)
{
	CEGUI::System &sys = CEGUI::System::getSingleton();
	sys.injectKeyDown(arg.key);
	sys.injectChar(arg.text);

	mCameraMan->injectKeyDown(arg);
	return true;
}
//-------------------------------------------------------------------------------------

bool Game::keyReleased(const OIS::KeyEvent &arg)
{
	CEGUI::System::getSingleton().injectKeyUp(arg.key);
	mCameraMan->injectKeyUp(arg);

	return true;
}

//-------------------------------------------------------------------------------------

bool Game::mouseMoved(const OIS::MouseEvent &arg)
{
	CEGUI::System &sys = CEGUI::System::getSingleton();
	sys.injectMouseMove(arg.state.X.rel, arg.state.Y.rel);
	// Scroll wheel.
	if (arg.state.Z.rel)
		sys.injectMouseWheelChange(arg.state.Z.rel / 120.0f);

	mCameraMan->injectMouseMove(arg);


	return true;
}
//-------------------------------------------------------------------------------------

bool Game::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	CEGUI::System::getSingleton().injectMouseButtonDown(convertButton(id));

	mCameraMan->injectMouseDown(arg, id);
	return true;
}
//-------------------------------------------------------------------------------------

bool Game::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	CEGUI::System::getSingleton().injectMouseButtonUp(convertButton(id));

	mCameraMan->injectMouseUp(arg, id);

	return true;
}
//-------------------------------------------------------------------------------------
bool Game::menu(const CEGUI::EventArgs &e)
{
	state = 1;
	destroyScene();
	m_Timer.reset();
	createScene();
	return state;
}
bool Game::start(const CEGUI::EventArgs &e)
{
	state = 2;
	destroyScene();	
	m_Timer.reset();
	createScene();
	return state;
}

bool Game::quit(const CEGUI::EventArgs &e)
{
	mShutDown = true;
	return true;
}
/*
bool Game::fps(const CEGUI::EventArgs &e)
{
	return FPS;
}
*/
bool Game::stage2(const CEGUI::EventArgs &e)
{
	state = 3;
	destroyScene();
	m_Timer.reset();
	createScene();
	return state;
}
//-------------------------------------------------------------------------------------

bool Game::upDate(void)
{
	float dt = m_Timer.getDelta();

	_fpsCounter =+ 1.0f;

	if(mWindow->isClosed())
		return false;

	if(mShutDown)
		return false;

	//Need to capture/update each device
	mKeyboard->capture();
	mMouse->capture();

	/*ostringstream buffer;
	buffer<<_fpsCounter;
	string fps = buffer.str();
	FPS->setText(fps);*/
	//FPS->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
	//FPS->setPosition(CEGUI::UVector2(CEGUI::UDim(0.85, 0), CEGUI::UDim(0.0, 0)));


	Ogre::FrameEvent evt;
	evt.timeSinceLastFrame = dt;//0.016; 
	mCameraMan->frameRenderingQueued(evt);

	//Need to inject timestamps to CEGUI System.
	CEGUI::System::getSingleton().injectTimePulse(evt.timeSinceLastFrame);

	return true;
}

//-------------------------------------------------------------------------------------
