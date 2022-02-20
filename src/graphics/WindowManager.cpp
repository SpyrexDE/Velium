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

    int WindowManager::addWindow(Window* window)
    {
        WindowManager::m_windows->push_back(window);
        return m_windows->size() - 1;
    }

    void WindowManager::removeWindow(int pos)
    {
        WindowManager::m_windows->erase(m_windows->begin() + pos);
    }
}