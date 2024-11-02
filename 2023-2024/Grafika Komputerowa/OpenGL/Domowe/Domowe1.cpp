#include <GL/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(-0.90, 0.10, 0.0);
    glVertex3f(-0.70, 0.65, 0.0);
    glVertex3f(0.70, 0.65, 0.0);
    glVertex3f(0.90, 0.10, 0.0);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.85, 0.10, 0.0);
    glVertex3f(-0.85, -0.80, 0.0);
    glVertex3f(0.85, -0.80, 0.0);
    glVertex3f(0.85, 0.10, 0.0);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0.60, 0.55, 0.0);
    glVertex3f(0.60, 0.95, 0.0);
    glVertex3f(0.35, 0.95, 0.0);
    glVertex3f(0.35, 0.55, 0.0);
    glEnd();
    glColor3f(0.8, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, -0.50, 0.0);
    glVertex3f(0.0, -0.05, 0.0);
    glVertex3f(-0.60, -0.05, 0.0);
    glVertex3f(-0.60, -0.50, 0.0);
    glEnd();
    glColor3f(0, 0.8, 1);
    glBegin(GL_POLYGON);
    glVertex3f(0.65, -0.80, 0.0);
    glVertex3f(0.25, -0.80, 0.0);
    glVertex3f(0.25, -0.20, 0.0);
    glVertex3f(0.65, -0.20, 0.0);
    glEnd();

    // Dach
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(-0.90, 0.10, 0.0);
    glVertex3f(-0.70, 0.65, 0.0);
    glVertex3f(0.70, 0.65, 0.0);
    glVertex3f(0.90, 0.10, 0.0);
    glEnd();

    // Trzon domu
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.85, 0.10, 0.0);
    glVertex3f(-0.85, -0.80, 0.0);
    glVertex3f(0.85, -0.80, 0.0);
    glVertex3f(0.85, 0.10, 0.0);
    glEnd();

    // Trzon domu linie
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.85, 0.10, 0.0);
    glVertex3f(-0.85, -0.80, 0.0);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.85, -0.80, 0.0);
    glVertex3f(0.85, -0.80, 0.0);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0.85, -0.80, 0.0);
    glVertex3f(0.85, 0.10, 0.0);
    glEnd();


    // Dach Linie
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.90, 0.10, 0.0);
    glVertex3f(-0.70, 0.65, 0.0);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.70, 0.65, 0.0);
    glVertex3f(0.70, 0.65, 0.0);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0.70, 0.65, 0.0);
    glVertex3f(0.90, 0.10, 0.0);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0.90, 0.10, 0.0);
    glVertex3f(-0.90, 0.10, 0.0);
    glEnd();

    // Komin
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0.60, 0.55, 0.0);
    glVertex3f(0.60, 0.95, 0.0);
    glVertex3f(0.35, 0.95, 0.0);
    glVertex3f(0.35, 0.55, 0.0);
    glEnd();

    // Komin Linie
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0.60, 0.55, 0.0);
    glVertex3f(0.60, 0.95, 0.0);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0.60, 0.95, 0.0);
    glVertex3f(0.35, 0.95, 0.0);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0.35, 0.95, 0.0);
    glVertex3f(0.35, 0.55, 0.0);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0.35, 0.55, 0.0);
    glVertex3f(0.60, 0.55, 0.0);
    glEnd();

    // Okno
    glColor3f(0.8, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, -0.50, 0.0);
    glVertex3f(0.0, -0.05, 0.0);
    glVertex3f(-0.60, -0.05, 0.0);
    glVertex3f(-0.60, -0.50, 0.0);
    glEnd();

    // Okno Linie

    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0.0, -0.50, 0.0);
    glVertex3f(0.0, -0.05, 0.0);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0.0, -0.05, 0.0);
    glVertex3f(-0.60, -0.05, 0.0);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.60, -0.05, 0.0);
    glVertex3f(-0.60, -0.50, 0.0);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-0.60, -0.50, 0.0);
    glVertex3f(0.0, -0.50, 0.0);
    glEnd();

    // Drzwi
    glColor3f(0, 0.8, 1);
    glBegin(GL_POLYGON);
    glVertex3f(0.65, -0.80, 0.0);
    glVertex3f(0.25, -0.80, 0.0);
    glVertex3f(0.25, -0.20, 0.0);
    glVertex3f(0.65, -0.20, 0.0);
    glEnd();

    // Drzwi Linie

    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0.65, -0.80, 0.0);
    glVertex3f(0.25, -0.80, 0.0);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0.25, -0.80, 0.0);
    glVertex3f(0.25, -0.20, 0.0);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0.25, -0.20, 0.0);
    glVertex3f(0.65, -0.20, 0.0);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(0.65, -0.20, 0.0);
    glVertex3f(0.65, -0.80, 0.0);
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