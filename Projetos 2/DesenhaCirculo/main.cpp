#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int lados=50;

void teclaPressionada(unsigned char key, int x, int y){
    switch(key){
        case 27://ASCII ESC
            exit(0);
            break;
        case 43:{ // + NA TABELA ASCII

            lados++;
            glutPostRedisplay();
        }
           break;
        case 45: {// - NA TABELA ASCII
            if(lados > 3){
                 lados--;
            }
            glutPostRedisplay();
        }
           break;
        default:
            break;
     }
}

void desenha() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);

   glBegin(GL_TRIANGLE_FAN);
   glVertex3f(0,0,-1);
     for(int i=0;i<=lados;i++){
        float ang=(2*M_PI*i)/lados;
      glVertex2f(sin(ang),cos(ang));
           }
   glVertex3f(0,0,-1);

   glEnd();

   glColor3f(1,1,1);

   glBegin(GL_TRIANGLE_FAN);
   glVertex3f(0,0,1);
     for(int i=0;i<=lados;i++){
        float ang=(2*M_PI*i)/lados;
      glVertex2f(sin(ang)/2,cos(ang)/2);
           }
   glVertex3f(0,0,1);

   glEnd();
   glFlush();

}
void Init()
{

    glClearColor(1, 1, 1, 1);
}

void redimensiona(int largura, int altura){

    glViewport(0,0,largura,altura);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2,2,-2,2,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main (int argc,char**argv){


    glutInit(&argc, argv);
    glutInitContextVersion(1,1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(800,800);
    glutInitWindowPosition (700,100);
    glutCreateWindow("Muller Penaforte Fernandes");

    glutDisplayFunc(desenha);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclaPressionada);

    Init();

    glutMainLoop();
    return 0;
}
