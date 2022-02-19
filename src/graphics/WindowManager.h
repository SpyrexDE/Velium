#pragma once

#include "Window.h"
#include "iostream"

namespace Velium::Graphics {
    class WindowManager {
    private:
        inline static std::vector<Window*> m_windows[10];
    public:
        static void init();
        static void addWindow(Window* window);
    private:

    };
}