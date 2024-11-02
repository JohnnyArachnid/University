#include <GL/glut.h>

void init()
{
    glClearColor(0.560784, 0.560784, 0.737255, 0.0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);

    glRotatef(20,1.0f,0.0f,0.0f); // obrót lokalnego układu wokół osi x
    glRotatef(20,0.0f,1.0f,0.0f); // obrót lokalnego układu wokół osi y
    //glPolygonMode(GL_BACK, GL_LINE);

    glBegin(GL_QUADS);
    // Ściana przednia
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.6f, -0.6f, 0.6f);
    glVertex3f(0.6f, -0.6f, 0.6f);
    glVertex3f(0.6f, 0.6f, 0.6f);
    glVertex3f(-0.6f, 0.6f, 0.6f);

    // Ściana tylna
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.6f, 0.6f, -0.6f);
    glVertex3f(0.6f, 0.6f, -0.6f);
    glVertex3f(0.6f, -0.6f, -0.6f);
    glVertex3f(-0.6f, -0.6f, -0.6f);

    // Ściana lewa
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.6f, -0.6f, -0.6f);
    glVertex3f(-0.6f, -0.6f, 0.6f);
    glVertex3f(-0.6f, 0.6f, 0.6f);
    glVertex3f(-0.6f, 0.6f, -0.6f);

    // Ściana prawa
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.6f, 0.6f, -0.6f);
    glVertex3f(0.6f, 0.6f, 0.6f);
    glVertex3f(0.6f, -0.6f, 0.6f);
    glVertex3f(0.6f, -0.6f, -0.6f);

    // Ściana dolna
    glColor3f(1.0f, 0.0f, 0.6f);
    glVertex3f(-0.6f, -0.6f, 0.6f);
    glVertex3f(-0.6f, -0.6f, -0.6f);
    glVertex3f(0.6f, -0.6f, -0.6f);
    glVertex3f(0.6f, -0.6f, 0.6f);

    // Ściana górna
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.6f, 0.6f, 0.6f);
    glVertex3f(0.6f, 0.6f, 0.6f);
    glVertex3f(0.6f, 0.6f, -0.6f);
    glVertex3f(-0.6f, 0.6f, -0.6f);

    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInit(&argc, argv);

    glutCreateWindow("Okno OpenGL");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
