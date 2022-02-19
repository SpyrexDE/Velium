#pragma once
#include "iostream"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <cstdlib>

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
    private:
        //m_vars
    public:
        Window(const char* title, int height, int width, WINDOW_POSITION win_pos = WINDOW_POSITION_CENTER);
        ~Window();
        void update();
        void clear();

        sf::Text text;

    private:
        void handleClose(sf::Event &event);
        void handleResize(sf::Event event);
    };
}
