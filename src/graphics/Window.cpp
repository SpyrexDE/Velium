#include "Window.h"
#include "imgui.h"
#include "WindowManager.h"
#include "DebugGUIStyle.cpp"

namespace Velium::Graphics {

    Window::Window(const char *title, int height, int width, WINDOW_POSITION win_pos) :
        sf::RenderWindow(sf::VideoMode(width, height), title)
    {
        // Setup ImGUI
        if(!ImGui::SFML::Init(*this, false))
            std::cout << "Error while initializing ImGui!";

        this->setActive(false);

        Velium::Graphics::applyDebugGuiStyle();

        // Set window position
        sf::Vector2<float> pos;
        sf::Vector2<float> screen_size = sf::Vector2<float>(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);

        switch(win_pos)
        {
            case WINDOW_POSITION_CENTER: pos = screen_size / 2.f; break;
            case WINDOW_POSITION_TOP_LEFT: pos = screen_size / 5.f; break;
            case WINDOW_POSITION_TOP_RIGHT: pos = sf::Vector2<float>(screen_size.x / 1.2f, screen_size.y / 5.f); break;
            case WINDOW_POSITION_BOTTOM_LEFT: pos = sf::Vector2<float>(screen_size.x / 5.f, screen_size.y / 1.2f); break;
            case WINDOW_POSITION_BOTTOM_RIGHT: pos = sf::Vector2<float>(screen_size.x / 1.2f, screen_size.y / 1.5f); break;
        }

        setPosition((sf::Vector2<int>)pos - (sf::Vector2<int>)sf::RenderWindow::getSize() / 2);


        // Add to WindowManager
        WindowManager::addWindow(this);
    }

    Window::~Window()
    {
        WindowManager::removeWindow(this);
    }

    void Window::clear()
    {
        sf::RenderWindow::clear();
    }

    void Window::update()
    {
        clear();

        sf::Event event;
        // Check for events
        while (pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(*this, event);
            handleClose(event);
            handleResize(event);
        }

        ImGui::SFML::Update(*this, m_delta_clock.restart());


        // Render drawables

        for(auto& item: drawList)
        {
            this->draw(*item);
        }


        ImGui::SFML::SetCurrentWindow(*this);
        ImGui::Begin("Hello, world!");
        if(ImGui::Button("Test")) {
            std::cout << "wow" <<std::endl;
        }
        ImGui::End();


        ImGui::SFML::Render(*this);
        sf::RenderWindow::display();
    }

    void Window::handleClose(sf::Event& event)
    {
        if (event.type == sf::Event::Closed)
            sf::RenderWindow::close();
    }

    void Window::handleResize(sf::Event event)
    {
        if (event.type == sf::Event::Resized)
        {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            this->setView(sf::View(visibleArea));
        }
    }

    void Window::addToDrawList(sf::Drawable* item)
    {
        std::unique_ptr<sf::Drawable> uniqueEntityPtr{item};
        drawList.emplace_back(move(uniqueEntityPtr));
    }

    void Window::removeFromDrawList(sf::Drawable* item)
    {
        // TODO: IMPLEMENT
    }

    sf::Vector2<float> Window::getRelativeMousePos()
    {
        return this->mapPixelToCoords(sf::Mouse::getPosition(*this));
    }
}
