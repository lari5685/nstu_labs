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
	glVertex2f(Xshow + Width/2, Yshow);	// 
	glVertex2f(Xold + Width/2, Yold);	//
	glEnd();
	glColor3ub(0, 0, 0);
	drawCircle(Xshow, Yshow, R, 50);	// ������� - ������ ������ ����
	glColor3ub(255, 0, 0);
	drawCircle(Xold, Yold, R, 50);		// ���������� �� ����� ����� �������
	Xshow = Xold; Yshow = Yold;			// ���� ����� = ������
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
	time0=clock();
	X += Vx;			// �������������� ���������
	Y += Vy;
	Vx += Ax;			// �������������� ��������
	Vy += Ay;
	if (Vx<0 && X <= R) Vx = -Vx;	// ������ �� �����
	if (Vx>0 && X > Width/2 - R) Vx = -Vx;
	if (Vy<0 && Y <= R) Vy = -Vy*0.9;
	if (Vy>0 && Y > Height - R) Vy = -Vy;
	if ((int)X != Xold || (int)Y != Yold){
		Xold = X;					// ����������� ����� ��� �� �������
		Yold = Y;
		glutPostRedisplay();		// ���������������� �����������
		}
	}


/* ������� ���� ���������� */
void main(int argc, char *argv[]){
	Vx = 3;
	Vy = 0;
	Ax = 0;
	Ay = -1;
	X = Xshow = Xold = Width / 2;
	Y = Yshow = Yold = Height-20;
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