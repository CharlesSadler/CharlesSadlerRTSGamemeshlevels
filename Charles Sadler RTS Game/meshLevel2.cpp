#include "meshLevel2.h"

MeshLevel2::MeshLevel2()
{
}
MeshLevel2::~MeshLevel2()
{

}
void MeshLevel2::createLevel()
{
	
	Ogre::SceneManager* mSceneMgr = (Ogre::SceneManager*)Storage::GetSingleton().GetItem("Ogre_SceneMgr");

	Ogre::Camera* mCamera = (Ogre::Camera*)Storage::GetSingleton().GetItem("Ogre_mCamera");
	mCamera->setPosition(150, 50, 150);
	mCamera->lookAt(0, 0, 0);

    mSceneMgr->setAmbientLight(Ogre::ColourValue(0, 0, 0));
    mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
 
    Ogre::Entity* entNinja = mSceneMgr->createEntity("Ninja", "ninja.mesh");
    entNinja->setCastShadows(true);
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entNinja);
 
    Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
 
    Ogre::MeshManager::getSingleton().createPlane("ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane, 1500, 1500, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);
 
    Ogre::Entity* entGround = mSceneMgr->createEntity("GroundEntity", "ground");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entGround);
 
    entGround->setMaterialName("Examples/Rockwall");
    entGround->setCastShadows(false);
 
    Ogre::Light* pointLight = mSceneMgr->createLight("pointLight");
    pointLight->setType(Ogre::Light::LT_POINT);
    pointLight->setPosition(Ogre::Vector3(0, 150, 250));
 
    pointLight->setDiffuseColour(1.0, 0.0, 0.0);
    pointLight->setSpecularColour(1.0, 0.0, 0.0);
 
    Ogre::Light* directionalLight = mSceneMgr->createLight("directionalLight");
    directionalLight->setType(Ogre::Light::LT_DIRECTIONAL);
    directionalLight->setDiffuseColour(Ogre::ColourValue(.25, .25, 0));
    directionalLight->setSpecularColour(Ogre::ColourValue(.25, .25, 0));
 
    directionalLight->setDirection(Ogre::Vector3( 0, -1, 1 )); 
 
    Ogre::Light* spotLight = mSceneMgr->createLight("spotLight");
    spotLight->setType(Ogre::Light::LT_SPOTLIGHT);
    spotLight->setDiffuseColour(0, 0, 1.0);
    spotLight->setSpecularColour(0, 0, 1.0);
 
    spotLight->setDirection(-1, -1, 0);
    spotLight->setPosition(Ogre::Vector3(300, 300, 0));
 
    spotLight->setSpotlightRange(Ogre::Degree(35), Ogre::Degree(50));

	mSceneMgr->setSkyDome(true, "Examples/CloudySky", 5, 8);

	/*
	Ogre::SceneManager* mSceneMgr = (Ogre::SceneManager*)Storage::GetSingleton().GetItem("Ogre_SceneMgr");
	mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));
	// Create the entity
    mEntity = mSceneMgr->createEntity("Robot", "robot.mesh");
 
        // Create the scene node
    mNode = mSceneMgr->getRootSceneNode()->
            createChildSceneNode("RobotNode", Ogre::Vector3(0.0f, 0.0f, 25.0f));
     mNode->attachObject(mEntity);

	mWalkList.push_back(Ogre::Vector3(550.0f,  0.0f,  50.0f ));
    mWalkList.push_back(Ogre::Vector3(-100.0f,  0.0f, -200.0f));

	// Create objects so we can see movement
        Ogre::Entity *ent;
        Ogre::SceneNode *node;
 
        ent = mSceneMgr->createEntity("Knot1", "knot.mesh");
        node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Knot1Node",
            Ogre::Vector3(0.0f, -10.0f,  25.0f));
        node->attachObject(ent);
        node->setScale(0.1f, 0.1f, 0.1f);
 
        ent = mSceneMgr->createEntity("Knot2", "knot.mesh");
        node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Knot2Node",
            Ogre::Vector3(550.0f, -10.0f,  50.0f));
        node->attachObject(ent);
        node->setScale(0.1f, 0.1f, 0.1f);
 
        ent = mSceneMgr->createEntity("Knot3", "knot.mesh");
        node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Knot3Node",
            Ogre::Vector3(-100.0f, -10.0f,-200.0f));
        node->attachObject(ent);
        node->setScale(0.1f, 0.1f, 0.1f);*/
}

void MeshLevel2::createFrameListener(void){
	OgreApplication::createFrameListener();
}

bool MeshLevel2::nextLocation(void){
	return true;
}
bool MeshLevel2::frameRenderingQueued(const Ogre::FrameEvent &evt){
	return OgreApplication::frameRenderingQueued(evt);
}



