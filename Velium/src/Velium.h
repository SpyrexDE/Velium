#pragma once
#include <X11/Xlib.h>
#include <iostream>

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