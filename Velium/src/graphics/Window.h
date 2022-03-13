#pragma once
#include <iostream>
#include <cstdlib>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "imgui-SFML.h"
#include <list>


namespace Velium::Graphics {

    class Window : public sf::RenderWindow
    {
    public:
        enum WINDOW_POSITION
        {
            WINDOW_POSITION_CENTER,
            WINDOW_POSITION_TOP_LEFT,
            WINDOW_POSITION_TOP_RIGHT,
            WINDOW_POSITION_BOTTOM_LEFT,
            WINDOW_POSITION_BOTTOM_RIGHT,
        };

        sf::Vector2<float> getRelativeMousePos();

    private:
        sf::Clock m_delta_clock;
        std::vector<std::unique_ptr<sf::Drawable>> drawList{};

    public:
        Window(const char* title, int height, int width, WINDOW_POSITION win_pos = WINDOW_POSITION_CENTER);
        ~Window();
        void update();
        void clear();

        void addToDrawList(sf::Drawable* item);
        void removeFromDrawList(sf::Drawable* item);



    private:
        void handleClose(sf::Event& event);
        void handleResize(sf::Event event);

    };
}
