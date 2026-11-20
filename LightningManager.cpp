#include "LightningManager.h"

LightningManager::LightningManager(SceneManager* sm)
{
    Light* light = sm->createLight("MainLight");
    light->setType(Light::LT_POINT);
    SceneNode* lightNode = sm->getRootSceneNode()->createChildSceneNode();
    lightNode->attachObject(light);
    lightNode->setPosition(0, 100, 0);

    Entity* lightEntity = sm->createEntity("LightSphere", "sphere.mesh");
    SceneNode* lightVisualNode = lightNode->createChildSceneNode();
    lightVisualNode->attachObject(lightEntity);
    lightVisualNode->setScale(0.1f, 0.1f, 0.1f);
    lightEntity->setMaterialName("BaseWhiteNoLighting");
}
