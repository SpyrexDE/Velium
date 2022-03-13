#pragma once

#include "Window.h"
#include "iostream"
#include <list>
#include <thread>

namespace Velium::Graphics {
    class WindowManager {
    private:
        inline static std::list<Window*> m_windows;
    public:
        static void init();
        static void addWindow(Window* window);
        static void removeWindow(Window* window);
        inline static bool running;
        inline static std::thread thread;
    private:

    };
}