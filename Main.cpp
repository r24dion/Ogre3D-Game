#include "Game.h"

int main()
{
    try
    {
        Game app;
        app.initApp();
        app.getRoot()->startRendering();
        app.closeApp();
    }
    catch (const exception& e)
    {
        cerr << "Error occurred during execution: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
