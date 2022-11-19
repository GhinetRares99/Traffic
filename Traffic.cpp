#include <windows.h>  
#include <gl/freeglut.h> 
#include <iostream>
using namespace std;
int i = 0, j = 0, m = 0, r = 0;
void init(void)
{
	glClearColor(0.0, 0.4, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1600.0, 0.0, 1000.0);
}
enum {
	NONE, ALTVERDE, ALB, GALBEN
};

int rendermode = NONE;

void menu(int selection)
{
	rendermode = selection;
	glutPostRedisplay();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1600.0, 0.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void desenMasinaMea(int x, int y)
{
	x = x - 80;
	y = y - 35;
	glRecti(x, y, x + 160, y + 70);

	//Faruri, stopuri si geamuri
	glColor3f(1.0, 1.0, 0.0);
	glRecti(x + 155, y + 50, x + 160, y + 65);

	glColor3f(1.0, 1.0, 0.0);
	glRecti(x + 155, y + 5, x + 160, y + 20);

	glColor3f(1.0, 0.0, 0.0);
	glRecti(x, y + 50, x + 5, y + 65);

	glColor3f(1.0, 0.0, 0.0);
	glRecti(x, y + 5, x + 5, y + 20);

	glColor3f(0.419, 1, 0.882);
	glBegin(GL_POLYGON);
	glVertex2i(x + 30, y+15);
	glVertex2i(x + 60, y+25);
	glVertex2i(x + 60, y+50);
	glVertex2i(x + 30, y+60);
	glEnd();

	glColor3f(0.419, 1, 0.882);
	glBegin(GL_POLYGON);
	glVertex2i(x + 100, y + 25);
	glVertex2i(x + 130, y + 15);
	glVertex2i(x + 130, y + 60);
	glVertex2i(x + 100, y + 50);
	glEnd();

	glColor3f(0.419, 1, 0.882);
	glBegin(GL_POLYGON);
	glVertex2i(x + 40, y + 15);
	glVertex2i(x + 120, y + 15);
	glVertex2i(x + 90, y + 25);
	glVertex2i(x + 70, y + 25);
	glEnd();

	glColor3f(0.419, 1, 0.882);
	glBegin(GL_POLYGON);
	glVertex2i(x + 70, y + 50);
	glVertex2i(x + 90, y + 50);
	glVertex2i(x + 120, y + 60);
	glVertex2i(x + 40, y + 60);
	glEnd();

	glColor3f(0.690, 0.415, 0.066);
	//Faruri, stopuri si geamuri 
}

void desenMasinaMeaInvers(int x, int y)
{
	x = x - 80;
	y = y - 35;
	glRecti(x, y, x + 160, y + 70);

	//Faruri, stopuri si geamuri
	glColor3f(1.0, 0.0, 0.0);
	glRecti(x + 155, y + 50, x + 160, y + 65);

	glColor3f(1.0, 0.0, 0.0);
	glRecti(x + 155, y + 5, x + 160, y + 20);

	glColor3f(1.0, 1.0, 0.0);
	glRecti(x, y + 50, x + 5, y + 65);

	glColor3f(1.0, 1.0, 0.0);
	glRecti(x, y + 5, x + 5, y + 20);

	glColor3f(0.419, 1, 0.882);
	glBegin(GL_POLYGON);
	glVertex2i(x + 30, y+15);
	glVertex2i(x + 60, y+25);
	glVertex2i(x + 60, y+50);
	glVertex2i(x + 30, y+60);
	glEnd();

	glColor3f(0.419, 1, 0.882);
	glBegin(GL_POLYGON);
	glVertex2i(x + 100, y + 25);
	glVertex2i(x + 130, y + 15);
	glVertex2i(x + 130, y + 60);
	glVertex2i(x + 100, y + 50);
	glEnd();

	glColor3f(0.419, 1, 0.882);
	glBegin(GL_POLYGON);
	glVertex2i(x + 40, y + 15);
	glVertex2i(x + 120, y + 15);
	glVertex2i(x + 90, y + 25);
	glVertex2i(x + 70, y + 25);
	glEnd();

	glColor3f(0.419, 1, 0.882);
	glBegin(GL_POLYGON);
	glVertex2i(x + 70, y + 50);
	glVertex2i(x + 90, y + 50);
	glVertex2i(x + 120, y + 60);
	glVertex2i(x + 40, y + 60);
	glEnd();

	glColor3f(0.690, 0.415, 0.066);
	//Faruri, stopuri si geamuri
}

//Pod
void desenPod(int x) {
	glColor3f(0.25, 0.25, 0.25);
	glBegin(GL_POLYGON);
	glVertex2i(x, 0);
	glVertex2i(x + 10, 0);
	glVertex2i(x + 10, 1000);
	glVertex2i(x, 1000);
	glEnd();

	glColor3f(0.368, 0.368, 0.368);
	glBegin(GL_POLYGON);
	glVertex2i(x + 10, 0);
	glVertex2i(x + 70, 0);
	glVertex2i(x + 70, 1000);
	glVertex2i(x + 10, 1000);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2i(x + 70, 0);
	glVertex2i(x + 370, 0);
	glVertex2i(x + 370, 1000);
	glVertex2i(x + 70, 1000);
	glEnd();

	glColor3f(0.368, 0.368, 0.368);
	glBegin(GL_POLYGON);
	glVertex2i(x + 370, 0);
	glVertex2i(x + 420, 0);
	glVertex2i(x + 420, 1000);
	glVertex2i(x + 370, 1000);
	glEnd();

	glColor3f(0.25, 0.25, 0.25);
	glBegin(GL_POLYGON);
	glVertex2i(x + 420, 0);
	glVertex2i(x + 430, 0);
	glVertex2i(x + 430, 1000);
	glVertex2i(x + 420, 1000);
	glEnd();

	glLineWidth(3.0);
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(x + 75, 0);
	glVertex2i(x + 75, 1000);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(x + 365, 0);
	glVertex2i(x + 365, 1000);
	glEnd();

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(7, 0xF0F0);
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(x + 220, 0);
	glVertex2i(x + 220, 1000);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
}
//Pod

//Traversa
void desenTraversa(int x, int y) {
	glColor3f(0.588, 0.188, 0.011);
	glBegin(GL_POLYGON);
	glVertex2i(x, y - 38);
	glVertex2i(x + 10, y - 38);
	glVertex2i(x + 10, y + 38);
	glVertex2i(x, y + 38);
	glEnd();

	glColor3f(0.211, 0.211, 0.211);
	glBegin(GL_POLYGON);
	glVertex2i(x, y + 18);
	glVertex2i(x + 10, y + 18);
	glVertex2i(x + 10, y + 32);
	glVertex2i(x, y + 32);
	glEnd();

	glColor3f(0.211, 0.211, 0.211);
	glBegin(GL_POLYGON);
	glVertex2i(x, y - 18);
	glVertex2i(x + 10, y - 18);
	glVertex2i(x + 10, y - 32);
	glVertex2i(x, y - 32);
	glEnd();

}
//Traversa

void desen(void)
{
	// soseaua
	int mult = 15;
	glClear(GL_COLOR_BUFFER_BIT);
	glDisable(GL_LINE_STIPPLE);
	glPushMatrix();
	glTranslated((i/8)*mult, 0, 0);

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2i(0, 190);
	glVertex2i(999999, 190);
	glVertex2i(999999, 810);
	glVertex2i(0, 810);
	glEnd();

	//Curs de apa
	glColor3f(0.0, 0.6, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(0, 70);
	glVertex2i(999999, 70);
	glVertex2i(999999, 140);
	glVertex2i(0, 140);
	glEnd();
	//Curs de apa

	//marcaje
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(0, 200);
	glVertex2i(999999, 200);

	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(0, 500);
	glVertex2i(999999, 500);

	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(0, 800);
	glVertex2i(999999, 800);

	glEnd();

	glLineWidth(5.0);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(7, 0xF0F0);
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(0, 350);
	glVertex2i(999999, 350);
	glVertex2i(0, 650);
	glVertex2i(999999, 650);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	glPopMatrix();
	//marcaje
	
	//masinile de pe sensul opus (banda 1)
	glPushMatrix();
	glTranslated((i / 5)*mult, 0, 0);
	for (int k = 0; k <= 999999; k = k + 300)
	{
		if (k % 400 == 0 || k % 700 == 0 || k % 1700 == 0)desenMasinaMeaInvers(k, 725);
	}
	glPopMatrix();

	//masinile de pe sensul opus (banda 2)
	glPushMatrix();
	glTranslated((i / 4)*mult, 0, 0);
	//glRotated(180.0, 0.0, 1.0, 0.0);
	for (int k = 0; k <= 999999; k = k + 300)
	{
		if (k % 600 == 0 || k % 1100 == 0 || k % 1900 == 0)desenMasinaMeaInvers(k, 575);

	}
	glPopMatrix();

	//masinile de pe sensul nostru (banda 1)
	glPushMatrix();
	glTranslated((i / 10)*mult, 0, 0);
	for (int k = 0; k <= 999999; k = k + 300)
	{
		if (k % 800 == 0)desenMasinaMea(k, 275);
	}
	glPopMatrix();
	//cout << m << endl;
	glPushMatrix();
	//glRotated(r, 0, 0, 1);
	//glRotated(-r, 0, 0, 1);
	
	//masina pe care o controlam
	glTranslated(300, m + 274, 0);
	glColor3f(0.0, 0.0, 1.0);
	glTranslated(-300, -274, 0);
	desenMasinaMea(300, 274);
	glPopMatrix();

	//Cale ferata
	glPushMatrix();
	glTranslated((i / 8)*mult, 0, 0);
	for (int k = 0; k <= 499999; k = k + 35)
	{
		desenTraversa(k, 925);
	}
	glPopMatrix();

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2i(0, 950);
	glVertex2i(999999, 950);

	glColor3f(0.6, 0.6, 0.6);
	glVertex2i(0, 900);
	glVertex2i(999999, 900);
	glEnd();
	//Cale ferata
	//generare poduri
	glPushMatrix();
	glTranslated((i / 8)*mult, 0, 0);
	desenPod(3000);
	desenPod(3500);
	desenPod(10000);
	desenPod(16500);
	desenPod(23000);
	desenPod(27000);
	desenPod(27500);

	glPopMatrix();
	//fundal animatie
	//glClear(GL_COLOR_BUFFER_BIT);
	switch (rendermode) {
	case NONE:
		glClearColor(0.0, 0.4, 0.0, 0.0);
		break;

	case ALTVERDE:
		glClearColor(0.0, 0.7, 0.0, 0.0);
		break;

	case ALB:
		glClearColor(0.9, 0.9, 0.9, 0.0);
		break;
	case GALBEN:
		glClearColor(1.0, 0.835, 0.239, 0.0);
	};
	glutSwapBuffers();
	glFlush();
}

void miscas(void)
{
	j = j - 1;
	i = i - 1;
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(miscas);
		r = r + 5;
		if (m != 150)m = m + 75;
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(miscas);
		r = r - 5;
		if (m != 0)m = m - 75;
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(40, 10);
	glutInitWindowSize(1600, 1000);
	glutCreateWindow("Proiect Grafica - Trafic");
	init();
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(desen);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutCreateMenu(menu);
	glutAddMenuEntry("Original", NONE);
	glutAddMenuEntry("Verde deschis", ALTVERDE);
	glutAddMenuEntry("Alb", ALB);
	glutAddMenuEntry("Galben", GALBEN);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	glutMainLoop();
}