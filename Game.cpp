#include "Game.h"


Game::Game(): ApplicationContext("OOP5"), scnMgr(nullptr), 
inputHandler(nullptr), lightManager(nullptr),
planeManager(nullptr), robotManager(nullptr)
{
}

void Game::setup()
{
    ApplicationContext::setup();
    addInputListener(this);

    Root* root = getRoot();
    scnMgr = root->createSceneManager();
    RTShader::ShaderGenerator* shadergen = RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(scnMgr);
    scnMgr->setSkyBox(true, "Examples/CloudyNoonSkyBox");
    scnMgr->setShadowTechnique(SHADOWTYPE_STENCIL_ADDITIVE);

    inputHandler = new InputHandler(scnMgr, getRenderWindow(), root, IsMoving);
    lightManager = new LightningManager(scnMgr);
    planeManager = new PlaneManager(scnMgr);
    robotManager = new RobotManager(scnMgr, IsMoving);

    root->addFrameListener(this);
}

bool Game::keyPressed(const KeyboardEvent& evt)
{
    return inputHandler->handleKeyPress(evt, robotManager);
}

bool Game::mouseMoved(const MouseMotionEvent& evt)
{
    return inputHandler->handleMouseMove(evt);
}

void Game::frameRendered(const FrameEvent& evt)
{
    robotManager->updateRobots(evt);
}
