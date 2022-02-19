#include "graphics/window.h"
#include "iostream"

int main()
{
    using namespace Velium;
    using namespace Graphics;

    Window window("Velium", 500, 500);
    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);


    glViewport( 0.0f, 0.0f, window.getWidth(), window.getHeight() ); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode( GL_PROJECTION ); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity( ); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho( 0, window.getWidth(), 0, window.getHeight(), 0, 1 ); // essentially set coordinate system
    glMatrixMode( GL_MODELVIEW ); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity( ); // same as above comment

    GLfloat lineVertices[] =
            {
                    0, 0, 0,
                    0, 0, 0
            };

    lineVertices[4] = window.getHeight();

    while(!window.closed())
    {
        double x, y;
        window.getMousePosition(x, y);
        window.clear();

        lineVertices[0] = x;
        lineVertices[1] = window.getHeight() - y;

        // Render OpenGL here
        glEnable( GL_LINE_SMOOTH );
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glPushAttrib( GL_LINE_BIT );
        glLineWidth( 10 );
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, lineVertices );
        glDrawArrays( GL_LINES, 0, 2 );
        glDisableClientState( GL_VERTEX_ARRAY );
        glPopAttrib( );
        glDisable( GL_LINE_SMOOTH );

        window.update();
    }

    return 0;
}
