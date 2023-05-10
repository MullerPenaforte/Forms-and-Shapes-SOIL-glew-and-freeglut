#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>


void init(){
    glClearColor(1,1,1,1);
    glEnable (GL_DEPTH_TEST);
}

int d =1;

//Desenha com preenchimento
void desenha() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f (0, 1, 1);
        glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0, 0,  0);
        glVertex3f( 10, 10,  0);
        glVertex3f( 50,  0,  0);
    glEnd();

    glColor3f (0, 1, 1);
        glBegin (GL_TRIANGLE_FAN);
        glVertex3f(10, 10, 0);
        glVertex3f(40, 10, 0);
        glVertex3f(50, 0, 0);
    glEnd();

    glColor3f (0, 1, 1);
        glBegin (GL_TRIANGLE_FAN);
        glVertex3f(50, 0, 0);
        glVertex3f(40, 10, 0);
        glVertex3f(50, 50, 0);
    glEnd();

     glColor3f (0, 1, 1);
        glBegin (GL_TRIANGLE_FAN);
        glVertex3f(50, 50, 0);
        glVertex3f(40, 10, 0);
        glVertex3f(40, 40, 0);
    glEnd();

     glColor3f (0, 1, 1);
        glBegin (GL_TRIANGLE_FAN);
        glVertex3f(50, 50, 0);
        glVertex3f(40, 40, 0);
        glVertex3f(0, 50, 0);
    glEnd();

     glColor3f (0, 1, 1);
        glBegin (GL_TRIANGLE_FAN);
        glVertex3f(0, 50, 0);
        glVertex3f(40, 40, 0);
        glVertex3f(10, 40, 0);
    glEnd();

     glColor3f (0, 1, 1);
        glBegin (GL_TRIANGLE_FAN);
        glVertex3f(0, 50, 0);
        glVertex3f(10, 40, 0);
        glVertex3f(0, 0, 0);
    glEnd();

     glColor3f (0, 1, 1);
        glBegin (GL_TRIANGLE_FAN);
        glVertex3f(0, 0, 0);
        glVertex3f(10, 40, 0);
        glVertex3f(10, 10, 0);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();

}

//Desenha com preenchimento e com linhas
void desenharLinhas(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f (0, 1, 1);

    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0, 0,  0);
        glVertex3f( 10, 10,  0);
        glVertex3f( 50,  0,  0);
    glEnd();

     glColor3f (0, 1, 1);
        glBegin (GL_TRIANGLE_FAN);
        glVertex3f(10, 10, 0);
        glVertex3f(40, 10, 0);
        glVertex3f(50, 0, 0);
    glEnd();

     glColor3f (0, 1, 1);
        glBegin (GL_TRIANGLE_FAN);
        glVertex3f(50, 0, 0);
        glVertex3f(40, 10, 0);
        glVertex3f(50, 50, 0);
    glEnd();

     glColor3f (0, 1, 1);
        glBegin (GL_TRIANGLE_FAN);
        glVertex3f(50, 50, 0);
        glVertex3f(40, 10, 0);
        glVertex3f(40, 40, 0);
    glEnd();

     glColor3f (0, 1, 1);
        glBegin (GL_TRIANGLE_FAN);
        glVertex3f(50, 50, 0);
        glVertex3f(40, 40, 0);
        glVertex3f(0, 50, 0);
    glEnd();

     glColor3f (0, 1, 1);
        glBegin (GL_TRIANGLE_FAN);
        glVertex3f(0, 50, 0);
        glVertex3f(40, 40, 0);
        glVertex3f(10, 40, 0);
    glEnd();

     glColor3f (0, 1, 1);
        glBegin (GL_TRIANGLE_FAN);
        glVertex3f(0, 50, 0);
        glVertex3f(10, 40, 0);
        glVertex3f(0, 0, 0);
    glEnd();

     glColor3f (0, 1, 1);
        glBegin (GL_TRIANGLE_FAN);
        glVertex3f(0, 0, 0);
        glVertex3f(10, 40, 0);
        glVertex3f(10, 10, 0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();

    glColor3f (0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex3f(0, 0,  1);
        glVertex3f( 10, 10,  1);
        glVertex3f( 50,  0,  1);
    glEnd();

     glColor3f (0, 0, 0);
        glBegin (GL_LINE_STRIP);
        glVertex3f(10, 10, 1);
        glVertex3f(40, 10, 1);
        glVertex3f(50, 0, 1);
    glEnd();

     glColor3f (0, 0, 0);
        glBegin (GL_LINE_STRIP);
        glVertex3f(50, 0, 1);
        glVertex3f(40, 10, 1);
        glVertex3f(50, 50, 1);
    glEnd();

     glColor3f (0, 0, 0);
        glBegin (GL_LINE_STRIP);
        glVertex3f(50, 50, 1);
        glVertex3f(40, 10, 1);
        glVertex3f(40, 40, 1);
    glEnd();

     glColor3f (0, 0, 0);
        glBegin (GL_LINE_STRIP);
        glVertex3f(50, 50, 1);
        glVertex3f(40, 40, 1);
        glVertex3f(0, 50, 1);
    glEnd();

     glColor3f (0, 0, 0);
        glBegin (GL_LINE_STRIP);
        glVertex3f(0, 50, 1);
        glVertex3f(40, 40, 1);
        glVertex3f(10, 40, 1);
    glEnd();

     glColor3f (0, 0, 0);
        glBegin (GL_LINE_STRIP);
        glVertex3f(0, 50, 1);
        glVertex3f(10, 40, 1);
        glVertex3f(0, 0, 1);
    glEnd();

     glColor3f (0, 0, 0);
        glBegin (GL_LINE_STRIP);
        glVertex3f(0, 0, 1);
        glVertex3f(10, 40, 1);
        glVertex3f(10, 10, 1);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();

}

void redimensiona(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 50, 0, 50, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}

void teclado(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
        exit(0);
    }
    if ((key == 'c') || (key == 'C')){
        d++;
        desenharLinhas();
}   if((d%2)>0){
        desenha();
}
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(700, 100);

    glutCreateWindow("Muller Penaforte Fernandes");
    glutReshapeFunc(redimensiona);
    glutDisplayFunc(desenha);
    glutKeyboardFunc(teclado);

    init();

    glutMainLoop();

    return 0;
}
