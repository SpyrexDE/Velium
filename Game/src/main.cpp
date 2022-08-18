#include <chrono>
#include <thread>
#include "graphics/Window.h"
#include "Velium.h"
#include "graphics/WindowManager.h"
#include "debug/ImGuiLayer.h"

int main()
{
    using Velium::Graphics::Window;

    Window window("Game", 600, 1200, Velium::Graphics::Window::WINDOW_POSITION_CENTER);

    window.addToDrawList(new sf::CircleShape(100.f));
    window.imGuiDrawFunc = ImGuiLayer::draw;

    Velium::Engine::start();

    return 0;
}
