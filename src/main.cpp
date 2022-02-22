#include "graphics/Window.h"
#include "iostream"
#include "graphics/WindowManager.h"

int main()
{
    using namespace Velium;
    using namespace Graphics;

    Window window("Velium", 800, 1200);

    WindowManager::init();

    ImGui::SFML::Shutdown();
    return 0;
}
