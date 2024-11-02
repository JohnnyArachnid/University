#include <GL/glut.h>

void init()
{
    glClearColor(0.560784, 0.560784, 0.737255, 0.0);
   
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.75, 0.0, 0.0);
    glVertex3f(0.75, 0.5, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInitWindowSize(400, 400);
    glutInitDisplayMode(GLUT_RGB);
    glutInit(&argc, argv);

    glutCreateWindow("Okno OpenGL");

    init();
    glutDisplayFunc(display);


    glutMainLoop();
    return 0;
}