#include <GL/glew.h>      // glew.h deve vir antes
#include <GL/freeglut.h>  // do freeglut.h

// callback de desenho (display)
void desenhaMinhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0, 1, 0);

    // desenha um POLYGON por seus vértices
    glBegin(GL_TRIANGLE_STRIP);
        // NOVIDADE: antes os valores eram -0.5, 0.5
        glVertex3f(20, 20, 0);
        glVertex3f(80, 20, 0);
        glVertex3f(80, 80, 0);
        glVertex3f(20, 80, 0);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);

    glVertex3f(120, 120, 0);
    glVertex3f(180, 120, 0);
    glVertex3f(180, 180, 0);
    glVertex3f(120, 180, 0);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);

    glVertex3f(20, 120, 0);
    glVertex3f(80, 120, 0);
    glVertex3f(80, 180, 0);

    glEnd();

    glPointSize(10);

    glBegin(GL_TRIANGLE_STRIP);

    glVertex3f(120, 20, 0);
    glVertex3f(180, 20, 0);
    glVertex3f(180, 80, 0);
    glVertex3f(120, 80, 0);

    glEnd();


    glFlush();
}

// NOVIDADE: uma função que vamos chamar dentro
//    do "main"
// Inicia algumas variáveis de estado do OpenGL
void inicializa() {
    // define qual é a cor do fundo
    glClearColor(1, 1, 1, 1); // branco

    // desenho preenchido vs. contorno
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

// NOVIDADE: callback para o evento "reshape"
void redimensionada(int width, int height) {
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho( 0, 200,  0, 200, -2, 5);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// NOVIDADE: callback de "keyboard"
void teclaPressionada(unsigned char key, int x, int y) {
    // vê qual tecla foi pressionada
    switch(key) {
    case 27:      // Tecla "ESC"
        exit(0);  // Sai da aplicação
        break;
    default:
        break;
    }
}

// função principal
int main(int argc, char** argv) {
   glutInit(&argc, argv);

   glutInitContextVersion(1, 1);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);

   glutCreateWindow("Muller Penaforte Fernandes");

   // registra callbacks para alguns eventos
   glutDisplayFunc(desenhaMinhaCena);
   glutReshapeFunc(redimensionada);
   glutKeyboardFunc(teclaPressionada);

   // configura valor inicial de algumas
   // variáveis de estado do OpenGL
   inicializa();

   glutMainLoop();
   return 0;
}
