#pragma once
#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "RobotManager.h"
#include "InputHandler.h"
#include "PlaneManager.h"
#include "LightningManager.h"
#include <iostream>
#include <vector>

using namespace Ogre;
using namespace OgreBites;
using namespace std;

class Game : public ApplicationContext, public InputListener
{
private:
    SceneManager* scnMgr;
    RobotManager* robotManager;
    PlaneManager* planeManager;
    LightningManager* lightManager;
    InputHandler* inputHandler;
    bool IsMoving = true;

public:
    Game();
    virtual ~Game() {}

    void setup() override;
    bool keyPressed(const KeyboardEvent& evt) override;
    bool mouseMoved(const MouseMotionEvent& evt) override;
    void frameRendered(const FrameEvent& evt) override;
};
