#include <GL/glut.h>

// Define the coordinates of the polygon
GLfloat vertices[][2] = {{100, 100}, {300, 100}, {400, 200}, {300, 300}, {100, 300}};

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the polygon
    glBegin(GL_POLYGON);
    for (int i = 0; i < 5; i++)
        glVertex2fv(vertices[i]);
    glEnd();

    // Set raster position for first word
    glRasterPos2f(200, 200);
    // Display each character of "Hello"
    char hello[] = "Hello";
    for (int i = 0; i < 5; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, hello[i]);
    }

    // Set raster position for second word
    glRasterPos2f(200, 250);
    // Display each character of "World"
    char world[] = "World";
    for (int i = 0; i < 5; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, world[i]);
    }

    glFlush();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Polygon with Text");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
