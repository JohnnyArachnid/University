#include <GL/glut.h>
#include <cmath>

// Definicje zmiennych globalnych do obsługi kamery
float angle = 0.0f;
float lx = 0.0f, lz = -1.0f;
float x = 0.0f, z = 4.9f;
float y = 1.75f;

void changeSize(int w, int h) {
    if (h == 0) h = 1;
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0, ratio, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawCube(float size) {
    float half = size / 2.0f;
    glBegin(GL_QUADS);
    // Front face
    glVertex3f(-half, -half, half);
    glVertex3f(half, -half, half);
    glVertex3f(half, half, half);
    glVertex3f(-half, half, half);
    // Back face
    glVertex3f(-half, -half, -half);
    glVertex3f(-half, half, -half);
    glVertex3f(half, half, -half);
    glVertex3f(half, -half, -half);
    // Top face
    glVertex3f(-half, half, -half);
    glVertex3f(-half, half, half);
    glVertex3f(half, half, half);
    glVertex3f(half, half, -half);
    // Bottom face
    glVertex3f(-half, -half, -half);
    glVertex3f(half, -half, -half);
    glVertex3f(half, -half, half);
    glVertex3f(-half, -half, half);
    // Right face
    glVertex3f(half, -half, -half);
    glVertex3f(half, half, -half);
    glVertex3f(half, half, half);
    glVertex3f(half, -half, half);
    // Left face
    glVertex3f(-half, -half, -half);
    glVertex3f(-half, -half, half);
    glVertex3f(-half, half, half);
    glVertex3f(-half, half, -half);
    glEnd();
}

void drawCone(float base, float height, int slices) {
    float angle;
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, height, 0);  // Top point
    for (int i = 0; i <= slices; ++i) {
        angle = 2 * M_PI * i / slices;
        glVertex3f(base * cos(angle), 0, base * sin(angle));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, 0);  // Bottom circle center
    for (int i = 0; i <= slices; ++i) {
        angle = 2 * M_PI * i / slices;
        glVertex3f(base * cos(angle), 0, base * sin(angle));
    }
    glEnd();
}

void drawCylinder(float radius, float height, int slices) {
    float angle;
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, height / 2, 0);  // Top circle center
    for (int i = 0; i <= slices; ++i) {
        angle = 2 * M_PI * i / slices;
        glVertex3f(radius * cos(angle), height / 2, radius * sin(angle));
    }
    glEnd();

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= slices; ++i) {
        angle = 2 * M_PI * i / slices;
        glVertex3f(radius * cos(angle), height / 2, radius * sin(angle));
        glVertex3f(radius * cos(angle), -height / 2, radius * sin(angle));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, -height / 2, 0);  // Bottom circle center
    for (int i = slices; i >= 0; --i) {
        angle = 2 * M_PI * i / slices;
        glVertex3f(radius * cos(angle), -height / 2, radius * sin(angle));
    }
    glEnd();
}

void drawCircle(float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.01f, 0.0f);  // Center point
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * float(i) / float(segments);
        float dx = radius * cosf(angle);
        float dz = radius * sinf(angle);
        glVertex3f(dx, 0.01f, dz);
    }
    glEnd();
}

void drawRoom() {
    // Podłoga
    glPushMatrix();
    glColor3f(0.8f, 0.5f, 0.2f);
    glScalef(10.0f, 0.1f, 10.0f);
    drawCube(1.0f);
    glPopMatrix();

    // Ściany
    glColor3f(0.6f, 0.8f, 1.0f);
    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glRotatef(i * 90.0f, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.0f, 2.5f, -5.0f);
        glScalef(10.0f, 5.0f, 0.1f);
        drawCube(1.0f);
        glPopMatrix();
    }

    // Sufit
    glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.8f);
    glTranslatef(0.0f, 4.0f, 0.0f);
    glScalef(10.0f, 0.1f, 10.0f);
    drawCube(1.0f);
    glPopMatrix();

    // Rysowanie krawędzi
    glColor3f(0.0f, 0.0f, 0.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Podłoga krawędzie
    glPushMatrix();
    glScalef(10.0f, 0.1f, 10.0f);
    drawCube(1.0f);
    glPopMatrix();

    // Ściany krawędzie
    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glRotatef(i * 90.0f, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.0f, 2.5f, -5.0f);
        glScalef(10.0f, 5.0f, 0.1f);
        drawCube(1.0f);
        glPopMatrix();
    }

    // Sufit krawędzie
    glPushMatrix();
    glTranslatef(0.0f, 5.0f, 0.0f);
    glScalef(10.0f, 0.1f, 10.0f);
    drawCube(1.0f);
    glPopMatrix();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y, z + lz, 0.0f, 1.0f, 0.0f);

    // Pokój
    drawRoom();

    // Lampa
    glPushMatrix();
    glTranslatef(0.0f, 3.99f, -2.0f);
    glColor3f(1.0f, 1.0f, 0.5f);
    drawCylinder(1.0f, 0.1f, 36);
    glPopMatrix();

    // Dywan
    glPushMatrix();

    // Największy czerwony dywan
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.051f, -2.0f);
    drawCircle(2.5f, 36);

    // Mniejszy niebieski dywan
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.01f, 0.0f);
    drawCircle(2.0f, 24);

    // Najmniejszy zielony dywan
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.01f, 0.0f);
    drawCircle(1.5f, 12);

    glPopMatrix();

    // Półki na drzewka
    for (int i = 0; i < 3; i++) {
        glColor3f(0.6f, 0.3f, 0.0f);
        glPushMatrix();
        glTranslatef(-4.25f + i * 3.0f, 2.25f, -4.5f);
        glScalef(1.5f, 0.1f, 0.8f);
        drawCube(1.0f);
        glPopMatrix();

        // Drzewka
        glPushMatrix();
        glColor3f(0.36f, 0.25f, 0.20f);
        glTranslatef(-4.25f + i * 3.0f, 2.25f, -4.5f);
        glTranslatef(0.0f, 0.1f, 0.0f);
        drawCylinder(0.3f, 0.2f, 36);
        glColor3f(0.0f, 0.5f, 0.0f);
        drawCone(0.3f, 1.0f, 6);
        glPopMatrix();
    }

    // Półka na książki
    glColor3f(0.6f, 0.6f, 0.6f);
    glPushMatrix();
    glTranslatef(0.0f, 2.25f, 4.6f);
    glScalef(10.0f, 0.1f, 0.8f);
    drawCube(1.0f);
    glPopMatrix();

    // Odległość między książkami wzdłuż półki
    float bookSpacing = 0.5f;

    // Rozmiar książek
    float bookWidth = 0.2f;
    float bookHeight = 0.8f;
    float bookDepth = 0.7f;

for (int i = 0; i < 19; i++) {
    glPushMatrix();

    // Położenie książki na półce
    float offsetX = -4.5f + i * bookSpacing;
    float offsetY = 2.65f;
    float offsetZ = 4.6f;

    glTranslatef(offsetX, offsetY, offsetZ);

    // Kolor książki
    if (i % 3 == 0)
        glColor3f(0.2f, 0.2f, 0.8f);
    else if (i % 3 == 1)
        glColor3f(0.8f, 0.1f, 0.1f);
    else
        glColor3f(0.5f, 0.2f, 0.1f);

    // Rysowanie książki
    glScalef(bookWidth, bookHeight, bookDepth);
    drawCube(1.0f);

    glPopMatrix();
}

    // Drzwi
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(3.75f, 1.25f, -4.75f);
    glScalef(1.5f, 2.5f, 0.25f);
    drawCube(1.0f);
    glPopMatrix();

    // Klamka na drzwi
    glColor3f(0.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(3.25f, 1.25f, -4.6f);
    glRotatef(90.0f, 90.0f, 1.0f, 0.0f);
    drawCylinder(0.1f, 0.1f, 36);
    glPopMatrix();

    // Rośliny
    glColor3f(0.0f, 0.5f, 0.0f);
    glPushMatrix();
    glTranslatef(4.0f, 0.25f, -1.5f);
    glScalef(0.5f, 1.0f, 0.5f);
    drawCylinder(0.3f, 0.5f, 36);
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCone(0.3f, 1.0f, 6);
    glPopMatrix();

    glColor3f(0.0f, 0.5f, 0.0f);
    glPushMatrix();
    glTranslatef(4.0f, 0.25f, -1.0f);
    glScalef(0.5f, 1.0f, 0.5f);
    drawCylinder(0.3f, 0.5f, 36);
    glColor3f(0.3f, 0.3f, 0.3f);
    drawCone(0.3f, 0.2f, 36);
    glColor3f(0.0f, 0.7f, 0.0f);
    drawCone(0.3f, 1.0f, 6);
    glPopMatrix();

    // Kosz na śmieci
    glColor3f(0.5f, 0.5f, 0.5f);
    glPushMatrix();
    glTranslatef(4.0f, 0.25f, 1.5f);
    glScalef(0.5f, 0.5f, 0.5f);
    drawCube(1.0f);
    glPopMatrix();

    // Długa Sofa
    glColor3f(0.6f, 0.3f, 1.0f);
    glPushMatrix();
    glTranslatef(-4.0f, 0.5f, 0.5f);
    glScalef(-2.0f, 1.0f, 7.5f);
    drawCube(1.0f);
    glPopMatrix();

    // Stół
    glColor3f(0.5f, 0.35f, 0.05f);
    glPushMatrix();
    glTranslatef(0.0f, 0.75f, 0.0f);
    glScalef(2.0f, 0.1f, 1.0f);
    drawCube(1.0f);
    glPopMatrix();

    // Nogi stołu
    glColor3f(0.5f, 0.35f, 0.05f);
    float legOffsetX = 0.8f;
    float legOffsetZ = 0.4f;
    float legHeight = 0.65f;
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            glPushMatrix();
            glTranslatef(i * legOffsetX, 0.375f, j * legOffsetZ);
            glScalef(0.1f, legHeight, 0.1f);
            drawCube(1.0f);
            glPopMatrix();
        }
    }

    // Krzesła wokół stołu
    glColor3f(0.2f, 0.6f, 0.8f);
    float chairOffset = 1.5f;
    for (int i = 0; i < 4; ++i) {
        glPushMatrix();
        glTranslatef(chairOffset * cos(i * M_PI / 2), 0.5f, chairOffset * sin(i * M_PI / 2));
        glRotatef(i * 90.0f, 0.0f, 1.0f, 0.0f);
        glScalef(0.5f, 1.0f, 0.5f);
        drawCube(1.0f);
        glPopMatrix();
    }

    glutSwapBuffers();
}

void keyboard(unsigned char key, int xx, int yy) {
    float fraction = 0.1f;

    switch (key) {
    case 'a':
    case 'A':
        angle -= 0.05f;
        lx = sin(angle);
        lz = -cos(angle);
        break;
    case 'd':
    case 'D':
        angle += 0.05f;
        lx = sin(angle);
        lz = -cos(angle);
        break;
    case 'w':
    case 'W':
        x += lx * fraction;
        z += lz * fraction;
        break;
    case 's':
    case 'S':
        x -= lx * fraction;
        z -= lz * fraction;
        break;
    case 'r':
    case 'R':
        y += fraction;
        break;
    case 'f':
    case 'F':
        y -= fraction;
        break;
    case 'q':
    case 'Q':
        exit(0);
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Projekt OpenGL Daniel Szarek: Pokoj");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
