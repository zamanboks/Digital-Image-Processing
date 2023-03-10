#include <GL/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // set color to red

    // set endpoints of line
    int x1 = 10, y1 = 10;
    int x2 = 100, y2 = 100;

    // calculate difference between endpoints
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    // determine direction of line
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;

    // calculate error terms
    int err = dx - dy;
    int e2;

    // draw line using Bresenham's algorithm
    while (1) {
        glBegin(GL_POINTS);
        glVertex2i(x1, y1);
        glEnd();

        if (x1 == x2 && y1 == y2) {
            break;
        }

        e2 = 2 * err;

        if (e2 > -dy) {
            err = err - dy;
            x1 = x1 + sx;
        }

        if (e2 < dx) {
            err = err + dx;
            y1 = y1 + sy;
        }
    }

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham's Line Drawing Algorithm");
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 500, 0, 500, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutMainLoop();
    return 0;
}
