#include <GL/glut.h> // GLUT, include glu.h e gl.h

// Inicialização parte gráfica da OpenGL
void initGL() {
  glClearColor(0.0, 0.0, 0.0, 0.0); // define a cor de fundo
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT); // limpa todos os pixels

  glColor3f(1.0, 1.0, 1.0); // Desenhar um polígono branco (retângulo)
  
  glBegin(GL_POLYGON); // desenha um poligono  na tela
      // definição das vertices x, y e z
     glVertex3f(0.25, 0.25, 0.0);
     glVertex3f(0.75, 0.25, 0.0);
     glVertex3f(0.75, 0.75, 0.0);
     glVertex3f(0.25, 0.75, 0.0);
  glEnd();
  glFlush(); // Não esperar!
  glutSwapBuffers(); // Troca entre os buffers  
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);            // Initialize GLUT
  glutInitDisplayMode(GLUT_DOUBLE); // Inicializa mode de buffer duple
  glutInitWindowSize(640, 480);     // Tamanho da tela (altura e largura)
  glutInitWindowPosition(550, 50);   // Posição da janela inicial (direita/esquerda e cima/baixo)
  glutCreateWindow("Quadrado"); // Criação do título da janela 
  glutDisplayFunc( display);   // Define o retorno de chamada de exibição para a janela atual. 
  initGL();       // Inicializa a função gráfica  
  glutMainLoop(); // Processo de loop 
  return 0;
}
