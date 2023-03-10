#include <GL/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // set color to red

    // set endpoints of line
    float x1 = 10, y1 = 10;
    float x2 = 100, y2 = 100;

    // calculate slope of line
    float dx = x2 - x1;
    float dy = y2 - y1;
    float m = dy / dx;

    // draw line using DDA algorithm
    float x = x1, y = y1;
    while (x < x2) {
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
        x += 1;
        y += m;
    }

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Line Drawing Algorithm");
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 500, 0, 500, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutMainLoop();
    return 0;
}
