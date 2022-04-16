#include <chrono>
#include <thread>
#include "graphics/Window.h"

#include "debug/ImGuiLayer.h"

int main()
{
    using Velium::Graphics::Window;

    Window window("Game", 600, 1200, Velium::Graphics::Window::WINDOW_POSITION_CENTER);

    window.addToDrawList(new sf::CircleShape(100.f));
    window.imGuiDrawFunc = ImGuiLayer::draw;

    std::this_thread::sleep_for(std::chrono::milliseconds(20000000000));

    return 0;
}
