#pragma once
#include "Ogre.h"

using namespace Ogre;
using namespace std;

class LightningManager
{
public:
    LightningManager(SceneManager* sm);
    virtual ~LightningManager() {}
};
