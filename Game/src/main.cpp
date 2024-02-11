#include <chrono>
#include <thread>
#include "graphics/Window.h"
#include "Velium.h"
#include "graphics/WindowManager.h"
#include "debug/ImGuiLayer.h"
#include "resources/ResHandler.h"

int main()
{
    using Velium::Graphics::Window;

    Window window("Game", 600, 1200, Velium::Graphics::Window::WINDOW_POSITION_TOP_LEFT);

    sf::CircleShape* shape = new sf::CircleShape(100.f);

    window.addToDrawList(shape);
    window.imGuiDrawFunc = ImGuiLayer::draw;

    sf::Image icon;
    icon.loadFromFile(ResHandler::GetFilePath("images/pepe.jpg"));
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Start the engine
    Velium::Engine::start();

    return 0;
}
