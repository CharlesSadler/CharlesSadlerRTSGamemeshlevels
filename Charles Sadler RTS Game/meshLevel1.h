#ifndef __MESHLEVEL1_h_
#define __MESHLEVEL1_h_

#include <Terrain/OgreTerrain.h>
#include <Terrain/OgreTerrainGroup.h>
#include "OgreApplication.h"
#include "UsefulTool.h"

class MeshLevel1
{
public:
	MeshLevel1();
	~MeshLevel1();
	static void createLevel(void);
	static void createGrassMesh(void);
};
#endif