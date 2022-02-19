#include "window.h"

namespace Velium::Graphics {
    void window_resize(GLFWwindow* window, int width, int height);

    Window::Window(const char *title, int height, int width)
            : m_title(title), m_height(height), m_width(width) {
        if (!init())
            glfwTerminate();

        for (int i = 0; i < MAX_KEYS; i++)
        {
            m_keys[i] = false;
        }

        for (int i = 0; i < MAX_BUTTONS; i++)
        {
            m_mouse_buttons[i] = false;
        }
    }

    Window::~Window() {
        glfwTerminate();
    }

    bool Window::isKeyPressed(unsigned int keycode) const
    {
        if (keycode >= MAX_KEYS)
            return false;

        return m_keys[keycode];
    }

    bool Window::isMouseButtonPressed(unsigned int button) const
    {
        if (button >= MAX_BUTTONS)
            return false;

        return m_mouse_buttons[button];
    }

    void Window::getMousePosition(double& x, double& y) const
    {
        x = m_mx;
        y = m_my;
    }

    void Window::clear() const
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
    }

    void Window::update() const
    {
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }

    void window_resize(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        Window* win = (Window*)glfwGetWindowUserPointer(window);
        win->m_keys[key] = action != GLFW_RELEASE;
    }

    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
    {
        Window* win = (Window*)glfwGetWindowUserPointer(window);
        win->m_mouse_buttons[button] = action != GLFW_RELEASE;
    }

    void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
    {
        Window* win = (Window*)glfwGetWindowUserPointer(window);
        win->m_mx = xpos;
        win->m_my = ypos;
    }

    bool Window::init() {
        if (!glfwInit()) {
            std::cout << "Failed to initialize GLFW!" << std::endl;
            return false;
        }

        m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
        if (!m_window) {
            glfwTerminate();
            std::cout << "Failed to create GLFW window!" << std::endl;
            return false;
        }

        glfwMakeContextCurrent(m_window);
        glfwSetWindowSizeCallback(m_window, window_resize);

        glfwSetWindowUserPointer(m_window, this);
        glfwSetWindowSizeCallback(m_window, window_resize);
        glfwSetKeyCallback(m_window, key_callback);
        glfwSetMouseButtonCallback(m_window, mouse_button_callback);
        glfwSetCursorPosCallback(m_window, cursor_position_callback);

        if(glewInit() != GLEW_OK)
        {
            std::cout << "Failed to initialize GLEW" << std::endl;
            return false;
        }

        return true;
    }

    bool Window::closed() const {
        return glfwWindowShouldClose(m_window);
    }
}
