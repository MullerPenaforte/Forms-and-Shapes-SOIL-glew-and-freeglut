#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>


void init(){
    glClearColor(1,1,1,1);
    glEnable (GL_DEPTH_TEST);
}



/*void desenhaAnelQuadrado() {
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(0, 0,  0);
        glVertex3f( 10, 10,  0);
        glVertex3f( 50,  0,  0);
        glVertex3f(40, 10, 0);
        glVertex3f(50, 50, 0);
        glVertex3f(40, 40, 0);
        glVertex3f(0, 50, 0);
        glVertex3f(10, 40, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(10, 10, 0);
    glEnd();
      glDisable(GL_TEXTURE_2D);
glutSwapBuffers();
}
/*/
int listaAnel;

void criaListaAnelQuadrado() {
  listaAnel = glGenLists(1);
  glNewList(listaAnel, GL_COMPILE);
    glBegin(GL_TRIANGLE_STRIP);

    glVertex3f( 10, 10,  0);
        glVertex3f( 50,  0,  0);
        glVertex3f(40, 10, 0);
        glVertex3f(50, 50, 0);
        glVertex3f(40, 40, 0);
        glVertex3f(0, 50, 0);
        glVertex3f(10, 40, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(10, 10, 0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        glutSwapBuffers();


  glEndList();
}

void desenha() {
  glColor3f(0, 0, 1);       // azul
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glCallList(listaAnel);    // chama a lista

  glColor3f(0, 0, 0);       // preto
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glCallList(listaAnel);    // chama a lista
}





//...

/*void desenha() {
    glColor3f(0, 0, 1);     // azul
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    desenhaAnelQuadrado();

    glColor3f(0, 0, 0);     // preto
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    desenhaAnelQuadrado();

}*/

/*void desenha() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glColor3f(0, 0, 1);     // azul
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


glBegin(GL_TRIANGLE_STRIP);
        glVertex3f(0, 0,  0);
        glVertex3f( 10, 10,  0);
        glVertex3f( 50,  0,  0);
        glVertex3f(40, 10, 0);
        glVertex3f(50, 50, 0);
        glVertex3f(40, 40, 0);
        glVertex3f(0, 50, 0);
        glVertex3f(10, 40, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(10, 10, 0);
    glEnd();

glColor3f(0, 0, 0);     // preto
glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
glBegin(GL_TRIANGLE_STRIP);
glVertex3f(0, 0,  0);
        glVertex3f( 10, 10,  0);
        glVertex3f( 50,  0,  0);
        glVertex3f(40, 10, 0);
        glVertex3f(50, 50, 0);
        glVertex3f(40, 40, 0);
        glVertex3f(0, 50, 0);
        glVertex3f(10, 40, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(10, 10, 0);
    glEnd();

glDisable(GL_TEXTURE_2D);
glutSwapBuffers();

} */

void redimensiona(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 50, 0, 50, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(700, 100);

    glutCreateWindow("Muller Penaforte Fernandes");
    glutReshapeFunc(redimensiona);

    glutDisplayFunc(desenha);
    criaListaAnelQuadrado();



    init();

    glutMainLoop();

    return 0;
}
