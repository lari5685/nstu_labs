#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <glut.h>
GLint Width = 1000, Height = 500;
int delay=20;
long time0=0;
double X, Y, Vx, Vy, Ax = 0, Ay = -0.1;
int Xold,Yold,R=20;
int Xshow, Yshow;
double K1 = 0.01, K2 = 0.02;	// ����������� ��������� � ���������
int Y0 = 250;					// ����� ������������ �������
int XG;							// ������� ����� ������� (��� �������)

void drawCircle(int x, int y, int r, int amountSegments){
	glBegin(GL_POLYGON);				// ���������� - ������� �������
	for(int i = 0; i < amountSegments; i++){
		float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);
		float dx = r * cosf(angle);
		float dy = r * sinf(angle);
		glVertex2f(x + dx, y + dy);
		}
	glEnd(); 
	}

void Display(void){
	// �� �������, ����� ������ ������
	//glClearColor(0, 0, 0, 1);
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(255, 255, 255);			// ����� ������
	glBegin(GL_LINE_LOOP);				// ��������� ������ � ����� �����
	glVertex2f(XG, Yshow);				// 
	glVertex2f(XG-1, Yold);				// ��� X - ��� �������
	glEnd();
	XG++;
	if (XG == Width) XG = Width / 10;	// ����� �� ����� - � ������
	glColor3ub(0, 0, 0);
	drawCircle(Xshow, Yshow, R, 50);	// ������� - ������ ������ ����
	glColor3ub(255, 0, 0);
	drawCircle(Xold, Yold, R, 50);		// ���������� �� ����� ����� �������
	Xshow = Xold; Yshow = Yold;			// ����� ����� = ������
	glFlush();
	glFinish();		
	}

void Reshape(GLint w, GLint h){
    Width = w;
    Height = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	}

void Keyboard(unsigned char key, int x, int y){
	#define ESCAPE '\033'
    if( key == ESCAPE )
        exit(0);
	}

void Idle(){	// �������� � ��������
	if (clock()-time0 < delay)
		return;
	time0=clock();				// ��������� ��������������� ���������� �������
	Ay = -K1*(Y - Y0) - K2*Vy;	// � �������� �������� (��� �� ������ - )
	X += Vx;					// �������������� ���������
	Y += Vy;
	Vx += Ax;					// �������������� ��������
	Vy += Ay;
	if ((int)X != Xold || (int)Y != Yold){
		Xold = X;					// ����������� ����� ��� �� �������
		Yold = Y;
		glutPostRedisplay();		// ���������������� �����������
		}
	}

void main(int argc, char *argv[]){
	Y0 = Height / 2;
	Vx = 0;
	Vy = 0;
	Ax = 0;
	X = Xshow = Xold = Width / 20;
	Y = Yshow = Yold = Y0+200;
	XG = Width / 10;
	time0 = clock();
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("����� ��������� �������");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
	glutIdleFunc(Idle);
    glutMainLoop();
	}