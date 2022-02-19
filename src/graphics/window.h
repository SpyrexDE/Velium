#pragma once
#include "iostream"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace Velium::Graphics {

    void window_resize(GLFWwindow* window, int width, int height);

    class Window
    {
    private:
        const char* m_title;
        int m_width, m_height;
        GLFWwindow* m_window;
        bool m_closed;

        bool m_keys[MAX_KEYS];
        bool m_mouse_buttons[MAX_BUTTONS];
        double m_mx, m_my;

    public:
        Window(const char* title, int height, int width);
        ~Window();
        void clear() const;
        void update() const;
        bool closed() const;

        inline int getWidth() const { return m_width; }
        inline int getHeight() const { return m_height; }

        bool isKeyPressed(unsigned int keycode) const;
        bool isMouseButtonPressed(unsigned int button) const;
        void getMousePosition(double& x, double& y) const;
    private:
        bool init();

        friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
        friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
    };
}
