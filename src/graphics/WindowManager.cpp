#include "WindowManager.h"

namespace Velium::Graphics
{
    void WindowManager::init()
    {
        while(!m_windows->empty())
        {
            for(int i = 0; i < m_windows->size(); i++)
            {
                (*m_windows->at(i)).update();
            }
        }
    }

    void WindowManager::addWindow(Window* window)
    {
        WindowManager::m_windows->push_back(window);
    }
}