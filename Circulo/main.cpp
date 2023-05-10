#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int lados=100;

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

    glColor3f(lados/20,0,lados/8);

   glBegin(GL_TRIANGLE_FAN);
   glVertex2f(0,0);
     for(int i=0;i<=lados;i++){
        float ang=(2*M_PI*i)/lados;
      glVertex2f(sin(ang),cos(ang));
           }
   glVertex2f(0,0);

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
