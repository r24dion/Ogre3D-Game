#pragma once
#include "Ogre.h"
#include "OgreInput.h"
#include "RobotManager.h"

using namespace Ogre;
using namespace OgreBites;
using namespace std;

class InputHandler
{
private:
    SceneManager* scnMgr;
    SceneNode* camNode;
    float moveSpeed = 10.0f;
    float mouseSensitivity = 0.2f;
    float yaw = 0.0f;
    float pitch = 0.0f;
    Root* root;
    bool& IsMoving;

public:
    InputHandler(SceneManager* sm, RenderWindow* rw, Root* root, bool& IsMoving);
    virtual ~InputHandler() {}
    bool handleKeyPress(const KeyboardEvent& evt, RobotManager* robotMgr);
    bool handleMouseMove(const MouseMotionEvent& evt);
};
