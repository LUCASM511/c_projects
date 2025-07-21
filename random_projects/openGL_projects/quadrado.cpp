#include <GL/glut.h>

void display(void) {
  /* Limpar todos os pixels */
  // glClear(GL_COLOR_BUFFER_BIT);
  glClear(GL_COLOR_BUFFER_BIT |
          GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
  /* Desenhar um polígono branco (retângulo) */
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex3f(0.25, 0.25, 0.0);
  glVertex3f(0.75, 0.25, 0.0);
  glVertex3f(0.75, 0.75, 0.0);
  glVertex3f(0.25, 0.75, 0.0);
  glEnd();
  /* Não esperar! */
  glFlush();
}

void init(void) {
  /* selecionar cor de fundo (preto) */
  glClearColor(0.0, 0.0, 0.0, 0.0);
  /* inicializar sistema de viz. */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glClearDepth(1.0f);      // Set background depth to farthest
  glEnable(GL_DEPTH_TEST); // Enable depth testing for z-culling
  glDepthFunc(GL_LEQUAL);  // Set the type of depth-test
  glShadeModel(GL_SMOOTH); // Enable smooth shading
  glHint(GL_PERSPECTIVE_CORRECTION_HINT,
         GL_NICEST); // Nice perspective corrections
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void reshape(GLsizei width,
             GLsizei height) { // GLsizei for non-negative integer
  // Compute aspect ratio of the new window
  if (height == 0)
    height = 1; // To prevent divide by 0
  GLfloat aspect = (GLfloat)width / (GLfloat)height;

  // Set the viewport to cover the new window
  glViewport(0, 0, width, height);

  // Set the aspect ratio of the clipping volume to match the viewport
  glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
  glLoadIdentity();            // Reset
  // Enable perspective projection with fovy, aspect, zNear and zFar
  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(550, 50);
  glutCreateWindow("hello");
  glutDisplayFunc(display);
  glutReshapeFunc(
      reshape); // Register callback handler for window re-size event
  init();
  glutMainLoop();
  /* C ANSI requer que main retorne um
  inteiro */
  return 0;
}
