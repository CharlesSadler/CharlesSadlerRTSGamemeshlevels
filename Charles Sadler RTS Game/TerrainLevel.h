#ifndef __TerrainLevel_h_
#define __TerrainLevel_h_

#include <Terrain/OgreTerrain.h>
#include <Terrain/OgreTerrainGroup.h>

#include "UsefulTool.h"
#include "OgreApplication.h"

class TerrainLevel
{
protected:
    Ogre::TerrainGlobalOptions* mTerrainGlobals;
    Ogre::TerrainGroup* mTerrainGroup;
    bool mTerrainsImported;
 
    void defineTerrain(long x, long y);
    void initBlendMaps(Ogre::Terrain* terrain);
    void configureTerrainDefaults(Ogre::Light* light);	

public:
	void createLevel();
};
#endif