#pragma once
#include "Ogre.h"
#include <vector>

using namespace Ogre;
using namespace std;

class RobotManager
{
private:
    bool& IsMoving;
    SceneManager* scnMgr;
    struct Robot
    {
        SceneNode* node;
        AnimationState* walkAnim;
        AnimationState* idleAnim;
        Vector3 initialPosition;
        float angle;
    };
    vector<Robot> robots;

public:
    RobotManager(SceneManager* sm, bool& IsMoving);
    virtual ~RobotManager() {}
    void createRobotAtCameraPosition(const Vector3& camPos);
    void deleteRobot(const Vector3& camPos);
    void updateRobots(const FrameEvent& evt);
};
