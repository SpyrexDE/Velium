#include "Window.h"
#include "imgui.h"
#include "WindowManager.h"
#include "DebugGUIStyle.cpp"

namespace Velium::Graphics {

    Window::Window(const char *title, int height, int width, WINDOW_POSITION win_pos) :
        sf::RenderWindow(sf::VideoMode(width, height), title)
    {
        // Add to WindowManager
        m_window_id = WindowManager::addWindow(this);

        // Setup ImGUI
        if(!ImGui::SFML::Init(*this, false))
            std::cout << "Error while initializing ImGui!";

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


    }

    Window::~Window()
    {
        WindowManager::removeWindow(m_window_id);
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

        sf::Font font;
        if (!font.loadFromFile("src/res/fonts/consolas/consolas.ttf"))
            std::cout << "Error loading font file";
        text = sf::Text("Hello SFML", font, 50);
        text.setPosition(100, 100);
        sf::RenderWindow::draw(text);


        sf::RectangleShape pixel;
        pixel.setSize({ 1.f, 1.f });
        pixel.setFillColor({ 255, 255, 255 });
        pixel.setPosition(sf::RenderWindow::mapPixelToCoords(sf::Mouse::getPosition(*this)));
        sf::RenderWindow::draw(pixel);

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
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
}
