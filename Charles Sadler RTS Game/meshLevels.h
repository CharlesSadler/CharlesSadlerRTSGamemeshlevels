#ifndef __LEVELS_h_
#define __LEVELS_h_

#include <Terrain/OgreTerrain.h>
#include <Terrain/OgreTerrainGroup.h>
#include "OgreApplication.h"
#include "UsefulTool.h"

class MeshLevels
{
public:
	MeshLevels();
	~MeshLevels();
	static void createLevel(void);
	static void createGrassMesh(void);
};
#endif