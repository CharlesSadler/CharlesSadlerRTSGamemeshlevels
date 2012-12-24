#include "LevelManager.h"

LevelManager* LevelManager::instance = NULL;

LevelManager* LevelManager::getInstance() 
{
	if(instance == NULL)
	instance = new LevelManager();
	return instance;
}

LevelManager::LevelManager()
{

}
LevelManager::~LevelManager()
{

}
bool LevelManager::addMesh(MeshLevels& ml)
{
	return true;
}
bool LevelManager::createMesh(MeshLevels& ml)
{
	return true;
}
void destroyMesh()
{

}