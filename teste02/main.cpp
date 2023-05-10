#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>





void desenha() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (1, 1, 1);
    // Começa a usar a textura que criamos
    glBegin(GL_TRIANGLE_FAN);
        // Associamos um canto da textura para cada vértice
        glVertex3f(-3, -3,  0);
        glVertex3f( -1, -3,  0);
        glVertex3f( -1,  -1,  0);
        glVertex3f(-3,  -1,  0);
    glEnd();

     glColor3f (1, 0, 1);
     glBegin (GL_TRIANGLE_FAN);
        glVertex3f(3, 3, 0);
        glVertex3f(1, 3, 0);
        glVertex3f(1, 1, 0);
        glVertex3f(3, 1, 0);
    glEnd();

    glColor3f (0, 0, 1);
     glBegin (GL_TRIANGLE_FAN);
        glVertex3f(-1, -3, 0);
        glVertex3f(1, -3, 0);
        glVertex3f(1, -1, 0);
        glVertex3f(-1, -1, 0);
    glEnd();

    glColor3f (0, 1, 1);
     glBegin (GL_TRIANGLE_FAN);
        glVertex3f(1, -3, 0);
        glVertex3f(3, -3, 0);
        glVertex3f(3, -1, 0);
        glVertex3f(1, -1, 0);
    glEnd();

    glColor3f (0.6, 0.6, 0.6);
    glBegin (GL_TRIANGLE_FAN);
        glVertex3f(-3,-1, 0);
        glVertex3f(-1,-1, 0);
        glVertex3f(-1,1,0);
        glVertex3f(-3,1,0);
    glEnd();

    glColor3f (1, 1, 0);
    glBegin (GL_TRIANGLE_FAN);
        glVertex3f(-1,-1, 0);
        glVertex3f(1,-1, 0);
        glVertex3f(1,1,0);
        glVertex3f(-1,1,0);
    glEnd();

    glColor3f (1, 0, 0);
    glBegin (GL_TRIANGLE_FAN);
        glVertex3f(1,-1, 0);
        glVertex3f(3,-1, 0);
        glVertex3f(3,1,0);
        glVertex3f(1,1,0);
    glEnd();

    glColor3f (0, 1, 0);
    glBegin (GL_TRIANGLE_FAN);
        glVertex3f(-3,1, 0);
        glVertex3f(-1,1, 0);
        glVertex3f(-1,3,0);
        glVertex3f(-3,3,0);
    glEnd();

    glColor3f (0, 0, 0);
    glBegin (GL_TRIANGLE_FAN);
        glVertex3f(-1,1, 0);
        glVertex3f(1,1,0);
        glVertex3f(1,3,0);
        glVertex3f(-1,3,0);

    glEnd();
    glDisable(GL_TEXTURE_2D);




    glutSwapBuffers();


}


//desenhaQuadrado(x, y, cor){






void redimensiona(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3, 3, -3, 3, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}

void teclado(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
        exit(0);
    }
}

void atualiza() {
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(700, 100);

    glutCreateWindow("Muller Penaforte Fernandes");

    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutDisplayFunc(desenha);
    glutIdleFunc(atualiza);



    glutMainLoop();

    return 0;
}



