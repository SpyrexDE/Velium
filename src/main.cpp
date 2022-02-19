#include "graphics/Window.h"
#include "iostream"
#include "graphics/WindowManager.h"

int main()
{
    using namespace Velium;
    using namespace Graphics;

    Window window("Velium", 500, 500);
    WindowManager::addWindow(&window);

    WindowManager::init();

    return 0;
}
