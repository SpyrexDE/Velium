#include "WindowManager.h"

namespace Velium::Graphics
{
    void WindowManager::init()
    {
        WindowManager::running = true;
        while(!m_windows.empty())
        {
            for(Window* window : m_windows)
            {
                window->update();
            }
        }
        WindowManager::running = false;
        ImGui::SFML::Shutdown();
    }

    void WindowManager::addWindow(Window* window)
    {
        WindowManager::m_windows.push_back(window);

        // Start updateloop
        if(!WindowManager::running)
            thread =  std::thread(WindowManager::init);

    }

    void WindowManager::removeWindow(Window* window)
    {
        WindowManager::m_windows.remove(window);
    }
}