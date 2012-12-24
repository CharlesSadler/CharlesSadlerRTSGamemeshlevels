//Chris Armit's Class to get the Delta time
#include <Ogre.h>
class OgreMasterTimer
{
public:
OgreMasterTimer(void){}
~OgreMasterTimer(void){}


private:
Ogre::Timer mTbf;
Ogre::Timer mRunTime;

public:
double getDelta(void) 
{
double tbf = (double)mTbf.getMilliseconds() * 0.001f;
mTbf.reset();
return tbf;
}

double getRunTime(void)
{ 
return (double)mRunTime.getMilliseconds() * 0.001f; 
}

void reset(void)
{ 
mTbf.reset(); 
mRunTime.reset(); 
}
};
