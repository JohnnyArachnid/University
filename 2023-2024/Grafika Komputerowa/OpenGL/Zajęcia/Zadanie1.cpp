#include <GL/glut.h>

void init()
{
    glColor3f(0, 0, 1);
   
}

void display(void)
{

    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
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