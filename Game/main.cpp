#include <chrono>
#include <thread>
#include "graphics/Window.h"

int main()
{
    using Velium::Graphics::Window;

    Window window("asd", 600, 1200, Velium::Graphics::Window::WINDOW_POSITION_CENTER);

    std::this_thread::sleep_for(std::chrono::milliseconds(20000));

    return 0;
}
