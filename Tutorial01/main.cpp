#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void display();
void reshape(int,int);
void timer(int);

GLuint idTexturaFundo;
GLuint idTexturaFundo2;


GLuint carregaTextura(const char* arquivo) {
    GLuint idTextura = SOIL_load_OGL_texture(
                           arquivo,
                           SOIL_LOAD_AUTO,
                           SOIL_CREATE_NEW_ID,
                           SOIL_FLAG_INVERT_Y
                       );

    if (idTextura == 0) {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    return idTextura;
}

int lados =0;
float x_position = -1;

void init() {

    glClearColor(0.0,0.0,0.0,1.0);

    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    idTexturaFundo = carregaTextura("space.png");
    idTexturaFundo2 = carregaTextura("nave.jpg");
}


void teclaPressionada(unsigned char key, int x, int y){
    switch(key){
        case 27://ASCII ESC
            exit(0);
            glutPostRedisplay();
            break;

        case 97: if(x_position >-9.5)

            x_position -= 0.20;

            break;

        case 100: if (x_position <7.5)

            x_position += 0.20;

            break;
                }
    }
int main (int argc, char**argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);


    glutInitWindowPosition (700,100);
    glutInitWindowSize (800,800);

    glutCreateWindow("Muller Penaforte Fernandes");

    glutDisplayFunc (display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(teclaPressionada);
    glutTimerFunc(0,timer,0);
    init();

    glutMainLoop();
}


int state =0;
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaFundo);
    glBegin(GL_TRIANGLE_FAN);
    glColor4f(1,1,1,1);
        // Associamos um canto da textura para cada vértice
        glTexCoord2f(0, 0);
        glVertex3f(-10, -10,  0);
        glTexCoord2f(1, 0);
        glVertex3f( 10, -10,  0);
        glTexCoord2f(1, 1);
        glVertex3f( 10,  10,  0);
        glTexCoord2f(0, 1);
        glVertex3f(-10,  10,  0);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, idTexturaFundo2);
    glLoadIdentity();
    glPointSize(5);
    //draw
    glBegin(GL_POLYGON);
    glColor4f(1,1,1, 1);

        glTexCoord2f(0, 0);
        glVertex2f(x_position,-9);
        glTexCoord2f(0, 1);
        glVertex2f(x_position,-7);
        glTexCoord2f(1, 1);
        glVertex2f(x_position+2,-7);
        glTexCoord2f(1, 0);
        glVertex2f(x_position+2,-9);
    //

    glEnd();



    glutSwapBuffers();

}


void reshape(int w,int h) {
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);

}











void timer(int){

    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);

   /* switch (state)
    {
        case 1: if((lados ==1) && (x_position<5))
        x_position += 0.10;
        //else
        //state = -1;
        break;
        case -1: if((lados ==2) && (x_position>-5))
        x_position -=0.10;
        //else
            //state=1;
            break;

        //else
        //state = -1;

           }
           */
           //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  Carregar alpha
}









