#include "PlaneManager.h"

PlaneManager::PlaneManager(SceneManager* sm)
{
    int rows = 3, cols = 3;
    float size = 1000.0f;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            Plane plane(Vector3::UNIT_Y, 0);
            string planeName = "plane_" + to_string(i) + "_" + to_string(j);
            MeshManager::getSingleton().createPlane(
                planeName, ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane,
                size, size, 20, 20, true, 1, 5, 5, Vector3::UNIT_Z);

            Entity* ent = sm->createEntity(planeName);
            SceneNode* node = sm->getRootSceneNode()->createChildSceneNode();
            node->setPosition((j - cols / 2) * size, 0, (i - rows / 2) * size);
            node->attachObject(ent);
            ent->setMaterialName("Examples/BeachStones");
        }
}
