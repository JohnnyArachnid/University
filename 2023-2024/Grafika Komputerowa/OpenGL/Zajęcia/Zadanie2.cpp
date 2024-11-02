#include <GL/glut.h>

void display(void)
{
    glColor3f(0, 0, 1);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-1.0, 0.0, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glEnd();


    glFlush();
}

int main(int argc, char *argv[])
{
    glutInitWindowSize(400, 400);
    glutInitDisplayMode(GLUT_RGB);
    glutInit(&argc, argv);

    glutCreateWindow("Okno OpenGL");

    glutDisplayFunc(display);


    glutMainLoop();
    return 0;
}