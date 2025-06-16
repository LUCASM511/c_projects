#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

#define ESCAPE 27 // codigo ascii para a escape key

int window; // o numero de nossa janela GLUT
int Width;  // largura da janela
int Height; // altura da janela

// todas as configuração vão aqui
int InitGL(GLvoid) {
  // ********************************************************
  glShadeModel(GL_SMOOTH); // habilita o sombreamento suavizado
                           // mistura cores de forma suave em um polígono
  // fundo preto
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // red, green, blue, alfa(transparência)
  // ********************************************************

  // Buffer de profundidade, como camadas na tela, esse buffer controla a
  // profundidade dos objetos na tela o impedir a renderização de objetos na
  // frente enquanto eles devem estar atrás de outros objetos
  // ********************************************************
  glClearDepth(1.0f); // inicialização do Depth Buffer

  glEnable(GL_DEPTH_TEST); // habilita teste de profundidade

  // configura um operador de comparação, usado na comparação de novos valores
  // de profundidade com o atual GL_LEQUAL passa se o valor de profundidade do
  // fragmento for menor ou igual ao valor de profundidade armazenado.
  glDepthFunc(GL_LEQUAL); // define qual teste de profundidade será feito
  // ********************************************************

  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // calculo de perspectiva

  return 0; // se tudo der certo
};

int redesenhaMundo(GLvoid) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // limpa a tela e o buffer
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,
                GL_TRUE); // indica que os dois lados de qualquer superfície
                          // devem ser representados
  glLoadIdentity();       // resete a corrente Modelview Matrix
  glutSwapBuffers();
  return 0;
};

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(450, 300);
  glutInitWindowPosition(0, 0);
  InitGL(640, 400);
}
