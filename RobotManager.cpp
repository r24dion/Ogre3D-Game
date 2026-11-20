#include "RobotManager.h"

RobotManager::RobotManager(SceneManager* sm, bool& IsMoving) :
    scnMgr(sm), IsMoving(IsMoving) {}

void RobotManager::createRobotAtCameraPosition(const Vector3& camPos)
{
    Vector3 robotPosition = camPos;
    robotPosition.y = 0.0f;

    Entity* robotEntity = scnMgr->createEntity("robot.mesh");
    SceneNode* robotNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    robotNode->attachObject(robotEntity);
    robotNode->setPosition(robotPosition);

    AnimationState* walkAnim = nullptr;
    AnimationState* idleAnim = nullptr;

    if (robotEntity->getAllAnimationStates()->hasAnimationState("Walk"))
    {
        walkAnim = robotEntity->getAnimationState("Walk");
        walkAnim->setLoop(true);
        walkAnim->setEnabled(true);

        idleAnim = robotEntity->getAnimationState("Idle");
        idleAnim->setLoop(true);
        idleAnim->setEnabled(false);
    }

    robots.push_back({ robotNode, walkAnim, idleAnim, robotPosition, 0.0f });
}

void RobotManager::deleteRobot(const Vector3& camPos)
{
    float destroyRadius = 100.0f;
    auto it = robots.begin();

    while (it != robots.end())
    {
        if (it->node->getPosition().distance(camPos) < destroyRadius)
        {
            scnMgr->destroyEntity(static_cast<Entity*>(it->node->getAttachedObject(0)));
            scnMgr->destroySceneNode(it->node);
            it = robots.erase(it);
        }
        else it++;
    }
}

void RobotManager::updateRobots(const FrameEvent& evt)
{
    for (Robot& robot : robots)
    {
        if (IsMoving)
        {
            robot.angle += evt.timeSinceLastFrame * 0.5f;
            float radius = 100.0f;

            float x = robot.initialPosition.x - radius * cos(robot.angle);
            float z = robot.initialPosition.z + radius * sin(robot.angle);

            robot.node->setPosition(x, 0, z);
            robot.node->lookAt(robot.initialPosition, Node::TS_WORLD);

            if (robot.walkAnim)
                robot.walkAnim->addTime(evt.timeSinceLastFrame);
            if (robot.idleAnim)
                robot.idleAnim->addTime(evt.timeSinceLastFrame);
        }
    }
}
