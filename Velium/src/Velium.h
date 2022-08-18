#pragma once
#ifdef __linux__
    #include <X11/Xlib.h>
#endif
#include "graphics/WindowManager.h"
namespace Velium
{
    class Engine
    {
    private:
    public:
        Engine()
        {
            #ifdef __linux__
                XInitThreads();
            #endif
        }
        static void start()
        {
            Graphics::WindowManager::init();
        }
    };
}