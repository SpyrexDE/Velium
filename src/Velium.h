#pragma once
#include <X11/Xlib.h>

namespace Velium
{
    class Engine
    {
    private:
    public:
        Engine()
        {
            XInitThreads();
        }
    };
}