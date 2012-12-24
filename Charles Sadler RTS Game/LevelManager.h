#ifndef __LEVELMANAGER_h_
#define __LEVELMANAGER_h_

#include "OgreApplication.h"
#include "UsefulTool.h"
#include "SdkCameraMan.h"
#include "meshLevel2.h"
#include "meshLevels.h"
#include <iostream>
#include <list>

class LevelManager 
{
protected:
	std::list<MeshLevels> items;

private: 
	static LevelManager* instance;
	LevelManager();	
public:	
	static LevelManager* getInstance();
	~LevelManager();

public:
	bool addMesh(MeshLevels& ml);
	bool createMesh(MeshLevels& ml);
	void destroyMesh();
	
};
#endif
