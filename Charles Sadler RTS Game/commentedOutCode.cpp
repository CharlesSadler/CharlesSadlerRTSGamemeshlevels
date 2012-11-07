//from Game.cpp create scene

	//adding stuff 
	/*	
	Ogre::TexturePtr tex = mRoot->getTextureManager()->createManual("RTT",
	Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, Ogre::TEX_TYPE_2D, 512, 512, 0, Ogre::PF_R8G8B8, Ogre::TU_RENDERTARGET);
	Ogre::RenderTexture *rtex = tex->getBuffer()->getRenderTarget();

	Ogre::Camera *cam = mSceneMgr->createCamera("RTTCam");
	cam->setPosition(1683, 50, 2116);
	cam->lookAt(-1963, 50, 1660);
	Ogre::Viewport *v = rtex->addViewport(cam);
	v->setOverlaysEnabled(false);
	v->setClearEveryFrame(true);
	v->setBackgroundColour(Ogre::ColourValue::Blue);

	CEGUI::Texture &guiTex = mRenderer->createTexture(tex);

	CEGUI::Imageset &imageSet =
	CEGUI::ImagesetManager::getSingleton().create("RTTImageset", guiTex);
	imageSet.defineImage("RTTImage", CEGUI::Point(0.0f, 0.0f), CEGUI::Size(guiTex.getSize().d_width, guiTex.getSize().d_height), CEGUI::Point(0.0f, 0.0f));

	CEGUI::Window *si = CEGUI::WindowManager::getSingleton().createWindow("TaharezLook/StaticImage", "RTTWindow");
	si->setSize(CEGUI::UVector2(CEGUI::UDim(0.3f, 0), CEGUI::UDim(0.3f, 0)));
	si->setPosition(CEGUI::UVector2(CEGUI::UDim(0.0f, 0), CEGUI::UDim(0.7f, 0)));

	si->setProperty("Image", CEGUI::PropertyHelper::imageToString(&imageSet.getImage("RTTImage")));

	sheet->addChildWindow(si);
	*/
	//finish adding stuff


//from Game.cpp

/*
bool Game::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
bool ret = BaseApplication::frameRenderingQueued(evt);

if (mTerrainGroup->isDerivedDataUpdateInProgress())
{
//mTrayMgr->moveWidgetToTray(mInfoLabel, OgreBites::TL_TOP, 0);
//mInfoLabel->show();
if (mTerrainsImported)
{
//mInfoLabel->setCaption("Building terrain, please wait...");
}
else
{
// mInfoLabel->setCaption("Updating textures, patience...");
}
}
else
{
//mTrayMgr->removeWidgetFromTray(mInfoLabel);
//mInfoLabel->hide();
if (mTerrainsImported)
{
mTerrainGroup->saveAllTerrains(true);
mTerrainsImported = false;
}
}

return ret;
}
*/


//from myCEGUI.cpp


/*
void myCEGUI::createWindow()
{
	Ogre::Root* mRoot = (Ogre::Root*)Storage::GetSingleton().GetItem("OgreRoot");

	Ogre::TexturePtr tex = mRoot->getTextureManager()->createManual("RTT",
    Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, Ogre::TEX_TYPE_2D, 512, 512, 0, Ogre::PF_R8G8B8, Ogre::TU_RENDERTARGET);
	Ogre::RenderTexture *rtex = tex->getBuffer()->getRenderTarget();

	Ogre::SceneManager* mSceneMgr;
	Ogre::Camera *cam = mSceneMgr->createCamera("RTTCam");
	cam->setPosition(1683, 50, 2116);
	cam->lookAt(-1963, 50, 1660);
	Ogre::Viewport *v = rtex->addViewport(cam);
	v->setOverlaysEnabled(false);
	v->setClearEveryFrame(true);
	v->setBackgroundColour(Ogre::ColourValue::Blue);

	CEGUI::OgreRenderer* mRenderer = &CEGUI::OgreRenderer::bootstrapSystem();
	CEGUI::Texture &guiTex = mRenderer->createTexture(tex);

	CEGUI::Imageset &imageSet =
	CEGUI::ImagesetManager::getSingleton().create("RTTImageset", guiTex);
	imageSet.defineImage("RTTImage", CEGUI::Point(0.0f, 0.0f), CEGUI::Size(guiTex.getSize().d_width, guiTex.getSize().d_height), CEGUI::Point(0.0f, 0.0f));

	CEGUI::Window *si = CEGUI::WindowManager::getSingleton().createWindow("TaharezLook/StaticImage", "RTTWindow");
	si->setSize(CEGUI::UVector2(CEGUI::UDim(0.3f, 0), CEGUI::UDim(0.3f, 0)));
	si->setPosition(CEGUI::UVector2(CEGUI::UDim(0.0f, 0), CEGUI::UDim(0.7f, 0)));

	si->setProperty("Image", CEGUI::PropertyHelper::imageToString(&imageSet.getImage("RTTImage")));

	sheet->addChildWindow(si);
}
*/