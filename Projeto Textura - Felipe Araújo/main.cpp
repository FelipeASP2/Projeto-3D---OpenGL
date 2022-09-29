#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#define TEXTURA_DO_PLANO "natu.sgi"


GLfloat chao_difusa[]    = {  0.96, 0.96, 0.96, 0.0 };
GLfloat chao_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat chao_brilho[]    = { 20.0 };

GLfloat parede_esquerda_difusa[]    = {  0.55, 0.27, 0.07, 0.0 };
GLfloat parede_esquerda_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat parede_esquerda_brilho[]    = { 20.0 };

GLfloat parede_fundo_difusa[]    = {  0.55, 0.27, 0.07, 0.0 };
GLfloat parede_fundo_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat parede_fundo_brilho[]    = { 20.0 };

GLfloat sofa_difusa[]    = { 1.0, 0.99, 0.81, 1.0 };
GLfloat sofa_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat sofa_brilho[]    = { 20.0 };

GLfloat mesa_difusa[]    = { 0.06, 0.06, 0.06, 1.0 };
GLfloat mesa_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mesa_brilho[]    = { 20.0 };

GLfloat posicao_luz[]    = { 1.0, 1.0, 1.0, 1.0};
GLfloat cor_luz[]        = { 1.0, 1.0, 1.0, 1.0};
GLfloat cor_luz_amb[]    = { 0.3, 0.3, 0.3, 1.0};

static int shoulder = 0, elbow = 0, elbow2 = 0;
GLuint  textura_plano;

static int rot = 0;
static int rot2 = 0;
static int rot3 = 0;

/*GLfloat planotext[4][2]={
  {-1,-1},
  {+1,-1},
  {+1,+1},
  {-1,+1}
};*/

GLfloat planotext[4][2]={
  {0,0},
  {+1,0},
  {+1,+1},
  {0,+1}
};

void display(void){

  glClear(GL_DEPTH_BUFFER_BIT);
  glClear(GL_COLOR_BUFFER_BIT);
  GLUquadricObj *quadric;
  glPushMatrix();

  glRotatef ((GLfloat) rot, 1.0, 0.0, 0.0);
  glRotatef ((GLfloat) rot2, 0.0, 1.0, 0.0);
  glRotatef ((GLfloat) rot3, 0.0, 0.0, 0.0);

  glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  glBindTexture(GL_TEXTURE_2D,textura_plano);
  
  /* parede - textura*/

  glEnable(GL_TEXTURE_2D);  
  glBegin(GL_QUADS);
  glTexCoord2fv(planotext[0]);  glVertex3f(-3,1,-3.72);
  glTexCoord2fv(planotext[1]);  glVertex3f(3,1,-3.72);
  glTexCoord2fv(planotext[2]);  glVertex3f(3,2.5,-3.72);
  glTexCoord2fv(planotext[3]);  glVertex3f(-3,2.5,-3.72);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  
   /* propriedades do material do chao */
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, chao_difusa);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, chao_especular);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, chao_brilho);
  
  /* chao */
  glPushMatrix();
  glTranslatef(0.0, 0.0,0.0);
  glScalef (10.0, 0.2, 8.0);
  glutSolidCube (1.0);
  glPopMatrix();

/* iluminação parede esquerda */
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, parede_esquerda_difusa);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, parede_esquerda_especular);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, parede_esquerda_brilho);
  
  /* parede esquerda */
  glPushMatrix();
  glColor3ub(244, 169, 96);
  glTranslatef (-4.9, 1.6, 0.0);
  glScalef (0.2, 3.0, 8.0);
  glutSolidCube (1.0);
  glPopMatrix();
  
   /* iluminação parede fundo */
 glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, parede_fundo_difusa);
 glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, parede_fundo_especular);
 glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, parede_fundo_brilho);

/*  parede fundo */
  glPushMatrix();
  glColor3ub(244, 169, 96);
  glTranslatef (0.0, 1.6, -3.9);
  glScalef (10.0, 3.0, 0.2);
  glutSolidCube (1.0);
  glPopMatrix();
  
  /* iluminação sofá */
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, sofa_difusa);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sofa_especular);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, sofa_brilho);

/* sofa 1 */
  glPushMatrix();
  glColor3ub(255, 165, 0);
  glTranslatef (0.0, 0.4, -2.0);
  glScalef (7.0, 0.6, 1.0);
  glutSolidCube (1.0);
  glPopMatrix();

  /* sofa 2 */
  glPushMatrix();
  glColor3ub(255, 165, 0);
  glTranslatef (-3.0, 0.4, 0.5);
  glScalef (1.0, 0.6, 4.0);
  glutSolidCube (1.0);
  glPopMatrix();

/* costas sofa 1*/
  glPushMatrix();
  glColor3ub(255, 140, 0);
  glTranslatef (0.0, 0.7, -2.6);
  glScalef (7.0, 1.2, 0.2);
  glutSolidCube (1.0);
  glPopMatrix();

  /* costas sofa 2*/
  glPushMatrix();
  glColor3ub(255, 140, 0);
  glTranslatef (-3.6, 0.7, -0.1);
  glScalef (0.2, 1.2, 5.2);
  glutSolidCube (1.0);
  glPopMatrix();

 /* iluminação mesa */
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mesa_difusa);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mesa_especular);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mesa_brilho);
  
/* Tampa mesa*/
  glPushMatrix();
  glColor3ub(218, 165, 32);
  glRotatef(90.0, 1.0, 0.0, 0.0);
  glTranslatef (0.0, 1.0, -1.2);
  glScalef (0.2, 0.2, 0.4);
  glutSolidCone (5.0, 0.0, 20.0, 2.0);
  glPopMatrix();

/* Apoio mesa*/
  glPushMatrix();
  glColor3ub(0, 0, 0);
  glTranslatef (0.0, 0.6, 1.0);
  glScalef (0.2, 1.2, 0.2);
  glutSolidCube (1.0);
  glPopMatrix();

/* teapot*/
  glPushMatrix();
  glColor3ub(255, 255, 255);
  glTranslatef (0.0, 1.6, 1.0);
  glScalef (0.2, 0.5, 0.2);
  glutSolidTeapot (1.0);
  glPopMatrix();

 /*quadro*/
  glPushMatrix();
  glColor3ub(255, 255, 255);
  glTranslatef (0.0, 1.75, -3.8);
  glScalef (6.5, 1.8, 0.1);
  glutSolidCube (1.0);
  glPopMatrix();

  glPopMatrix();
  glutSwapBuffers();

}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, 0.0, -9.5);
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
/* gira para cima */
  case 'w':
    rot = (rot + 5) % 360;
    glutPostRedisplay();
    break;
/* gira para baixo */
  case 's':
    rot = (rot - 5) % 360;
    glutPostRedisplay();
    break;
/* gira para esquerda */
    case 'a':
    rot2 = (rot2 + 5) % 360;
    glutPostRedisplay();
    break;
/* gira para direita */
  case 'd':
    rot2 = (rot2 - 5) % 360;
    glutPostRedisplay();
    break;
    /* zoom out */
  case 'z':
    rot3 = (rot3 - 5) % 360;
    glutPostRedisplay();
    break;
    /* zoom in */
    case 'Z':
    rot3 = (rot3 + 5) % 360;
    glutPostRedisplay();
    break;
  case 27:                                         // tecla Esc (encerra o programa)
	exit(0);
	break;
  }
}

void carregar_texturas(void){
  IMAGE *img;
  GLenum gluerr;

  /* textura do plano */
  glGenTextures(1, &textura_plano);
  glBindTexture(GL_TEXTURE_2D, textura_plano);
  
  if(!(img=ImageLoad(TEXTURA_DO_PLANO))) {
    fprintf(stderr,"Error reading a texture.\n");
    exit(-1);
  }

  gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
			   img->sizeX, img->sizeY, 
			   GL_RGB, GL_UNSIGNED_BYTE, 
			   (GLvoid *)(img->data));
  if(gluerr){
    fprintf(stderr,"GLULib%s\n",gluErrorString(gluerr));
    exit(-1);
  }

  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);

}

void init(void){
  carregar_texturas();
  glShadeModel(GL_FLAT);
  glEnable (GL_DEPTH_TEST);
  glClearColor (0.0, 0.0, 0.0, 0.0);
  
  glLightfv(GL_LIGHT0, GL_DIFFUSE, cor_luz);
  glLightfv(GL_LIGHT0, GL_SPECULAR, cor_luz);
  glLightfv(GL_LIGHT0, GL_AMBIENT, cor_luz_amb);
  glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz);
  
  glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);


  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
  
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  init ();
  glutMainLoop();
  return 0;
}
 
