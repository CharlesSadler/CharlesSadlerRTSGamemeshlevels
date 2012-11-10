#ifndef __LEVELS2_h_
#define __LEVELS2_h_

#include <Terrain/OgreTerrain.h>
#include <Terrain/OgreTerrainGroup.h>
#include "OgreApplication.h"
#include "OgreVector3.h"
#include "UsefulTool.h"
#include <deque>

class MeshLevel2 : public OgreApplication
{
public:
	MeshLevel2();
	~MeshLevel2();
	static void createLevel(void);
protected:
	 void createFrameListener(void);
     bool nextLocation(void);
     bool frameRenderingQueued(const Ogre::FrameEvent &evt);
 
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