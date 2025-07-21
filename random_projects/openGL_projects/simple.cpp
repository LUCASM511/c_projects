// Um programa OpenGL simples que abre uma janela GLUT
// Este código está baseado no Simple.c, exemplo
// disponível no livro "OpenGL SuperBible",
// 2nd Edition, de Richard S. e Wright Jr.

#include <GL/freeglut_std.h>
#include <GL/glut.h>

// Função callback chamada para fazer o desenho
void Desenha(void) {
  // Limpa a janela de visualização com a cor de fundo especificada
  glClear(GL_COLOR_BUFFER_BIT);

  // Executa os comandos OpenGL
  glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa(void) {
  // Define a cor de fundo da janela de visualização como preta
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClearDepth(1.0f); // Set background depth to farthest
}

// Programa Principal
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480); // Set the window's initial width & height
  glutInitWindowPosition(550, 50); // Position the window's initial top-left corner
  glutCreateWindow("Primeiro Programa");
  glutDisplayFunc(Desenha);
  Inicializa();
  glutMainLoop();
  return 0;
}
