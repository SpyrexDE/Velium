#include "graphics/window.h"
#include "iostream"

int main()
{
    using namespace Velium;
    using namespace Graphics;

    Window window("Velium", 500, 500);
    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

    while(!window.closed())
    {
        window.clear();
        glBegin(GL_TRIANGLES);
        glVertex2f( 0.0f, 0.5f);
        glVertex2f(-0.5f,-0.5f);
        glVertex2f( 0.5f,-0.5f);
        glEnd();
        window.update();
    }
    return 0;
}
