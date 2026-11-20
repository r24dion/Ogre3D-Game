#include "InputHandler.h"

InputHandler::InputHandler(SceneManager* sm, RenderWindow* rw, Root* root, bool& IsMoving)
    : scnMgr(sm), root(root), IsMoving(IsMoving)
{
    camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    Camera* cam = scnMgr->createCamera("myCam");
    cam->setNearClipDistance(5);
    cam->setAutoAspectRatio(true);
    camNode->attachObject(cam);
    camNode->setPosition(200, 70, 200);
    camNode->lookAt(Vector3(0, 0, 0), Node::TS_WORLD);
    rw->addViewport(cam);
}

bool InputHandler::handleKeyPress(const KeyboardEvent& evt, RobotManager* robotMgr)
{
    Vector3 direction = Vector3::ZERO;

    switch (evt.keysym.sym)
    {
        case SDLK_ESCAPE:
            root->queueEndRendering();
            break;
        case SDLK_UP:
            direction += camNode->getOrientation() * Vector3(0, 0, -moveSpeed);
            break;
        case SDLK_DOWN:
            direction += camNode->getOrientation() * Vector3(0, 0, moveSpeed);
            break;
        case SDLK_LEFT:
            direction += camNode->getOrientation() * Vector3(-moveSpeed, 0, 0);
            break;
        case SDLK_RIGHT:
            direction += camNode->getOrientation() * Vector3(moveSpeed, 0, 0);
            break;
        case SDLK_SPACE:
            robotMgr->createRobotAtCameraPosition(camNode->getPosition());
            break;
        case SDLK_DELETE:
            robotMgr->deleteRobot(camNode->getPosition());
            break;
        case SDLK_LSHIFT:
            IsMoving = !IsMoving;
            break;
    }

    direction.y = 0;
    direction.normalise();
    camNode->translate(direction * moveSpeed, Node::TS_WORLD);
    return true;
}

bool InputHandler::handleMouseMove(const MouseMotionEvent& evt)
{
    yaw -= evt.xrel * mouseSensitivity;
    pitch -= evt.yrel * mouseSensitivity;

    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    camNode->setOrientation(Quaternion::IDENTITY);
    camNode->yaw(Degree(yaw));
    camNode->pitch(Degree(pitch));

    return true;
}
