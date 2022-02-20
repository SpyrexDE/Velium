#include "graphics/Window.h"
#include "iostream"
#include "graphics/WindowManager.h"

int main()
{
    using namespace Velium;
    using namespace Graphics;

    Window window("Velium", 500, 500);
    Window window2("Velium", 500, 500);
    Window window3("Velium", 500, 500);

    WindowManager::init();

    ImGui::SFML::Shutdown();
    return 0;
}
