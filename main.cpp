#include<windows.h>
#include <GL/glut.h>

float PositionX = 0.0f;
float PositionY = 0.0f;

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();

   // Draw a moving boat

   glBegin(GL_QUADS);
   glColor3f(0.0f, 0.0f, 1.0f); //blue for water
   glVertex2f(-1.0f, -0.4f);
   glVertex2f(-1.0f, -1.0f);
   glVertex2f(1.0f, -1.0f);
   glVertex2f(1.0f, -0.4f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3f(0.275f, 0.510f, 0.706f); //ocean color
   glVertex2f(-1.0f, 1.0f);
   glVertex2f(-1.0f, -0.4f);
   glVertex2f(1.0f, -0.4f);
   glVertex2f(1.0f, 1.0f);
   glEnd();

   glTranslatef(PositionX, PositionY, 0.0f);
   glBegin(GL_QUADS);
   glColor3f(0.545f, 0.271f, 0.075f);//Brown
   glVertex2f(-0.3f, -0.475f);
   glVertex2f(-0.3f, -0.375f);
   glVertex2f(0.4f, -0.375f);
   glVertex2f(0.275f, -0.475f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
   glVertex2f(-0.425f, -0.350f);    // Bottom-left vertex
   glVertex2f(0.1f, -0.350f);     // Bottom-right vertex
   glVertex2f(0.1f, 0.6f);  // Top vertex
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
   glVertex2f(0.150f, -0.350f);    // Bottom-left vertex
   glVertex2f(0.5f, -0.350f);     // Bottom-right vertex
   glVertex2f(0.150f, 0.4f);  // Top vertex
   glEnd();

   glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
   switch (key) {

      case 'j':
         PositionX += 0.1f;
         break;
      case 'f':
         PositionX -= 0.1f;
         break;

      default:
         break;
   }
   glutPostRedisplay();
}

int main(int argc, char **argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(400, 400);
   glutCreateWindow("Moving boat payel");
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // White background
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);
   glMatrixMode(GL_MODELVIEW);
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}


