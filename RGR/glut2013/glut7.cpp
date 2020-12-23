#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include <glut.h>				// ������������  GLUT
GLint Width = 512, Height = 512;// ��������� ������� ����
int SZ = 200;
int XY0 = 50;
int dd=3;						// ���������� ������� �������� � + �� -
int delay=20;					// �������� � �� ����� ���������� IDLE
long time0=0;					// ������� ���������� �������
int X0 = 500, Y0 = 400;			// ���������� �������������
double K = 0.002;				// ������ �� ��� Z (�����������)

int get3DX(int x, int y, int z){
	int  xx = x + (X0 - x)*(1 - exp(-K*z));
	//printf("x=%d\n", xx);
	return xx;
	}
int get3DY(int x, int y, int z){
	return y + (Y0 - y)*(1 - exp(-K*z));
	}
void line3D(int x1, int y1, int z1, int x2, int y2, int z2){
	glBegin(GL_LINE_LOOP);		
	glVertex2f(get3DX(x1, y1, z1), get3DY(x1, y1, z1));
	glVertex2f(get3DX(x2, y2, z2), get3DY(x2, y2, z2));
	glEnd();
	}

void Display(void){				// ����� �� �����
    glClear(GL_COLOR_BUFFER_BIT);    
    glColor3ub(255,0,0);		// RGB - ���� �������
	line3D(XY0, XY0, 0, XY0 + SZ, XY0, 0);
	line3D(XY0, XY0, 0, XY0, XY0 + SZ, 0);
	line3D(XY0+SZ, XY0, 0, XY0 + SZ, XY0+SZ, 0);
	line3D(XY0, XY0+SZ, 0, XY0 + SZ, XY0+SZ, 0);
	line3D(XY0, XY0, SZ, XY0 + SZ, XY0, SZ);
	line3D(XY0, XY0, SZ, XY0, XY0 + SZ, SZ);
	line3D(XY0 + SZ, XY0, SZ, XY0 + SZ, XY0 + SZ, SZ);
	line3D(XY0, XY0 + SZ, SZ, XY0 + SZ, XY0 + SZ, SZ);
	line3D(XY0, XY0, 0, XY0, XY0, SZ);
	line3D(XY0, XY0 + SZ, 0, XY0, XY0 + SZ, SZ);
	line3D(XY0 + SZ, XY0, 0, XY0 + SZ, XY0, SZ);
	line3D(XY0 + SZ, XY0 + SZ, 0, XY0 + SZ, XY0 + SZ, SZ);
	glFinish();
	}

void Reshape(GLint w, GLint h){		// ������� - ��������� �������� ����
    Width = w;						// ��������� ����� �������
    Height = h;
    glViewport(0, 0, w, h);			// ������� �����������
    glMatrixMode(GL_PROJECTION);	// ��������������� ��������
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	}

void Keyboard(unsigned char key, int x, int y){
	#define ESCAPE '\033'	// ������� - ������ ����������
    if( key == ESCAPE )		// ������� ESCAPE
        exit(0);			// ������� ���������
	}

void Idle(){				// ���������� ������� - IDLE
	if (clock()-time0 < delay)
		return;				// �� ����� �������� delay
	time0=clock();			// ��������� ����� ������� �������
	if (SZ<30 && dd>0 || SZ>300 && dd<0){
		dd=-dd;				// ������� ����������� ���������
		}
	SZ-=dd;					// �������� ������� ��������
	glutPostRedisplay();	// ������������� ������� Display
	}

void main(int argc, char *argv[]){
	time0 = clock();					// ��������� ����� � ��
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Width, Height);	// ������ ����
    glutCreateWindow("Red square example");
    glutDisplayFunc(Display);			// ������� �����������
    glutReshapeFunc(Reshape);			// ������� ����� ����������� ����
    glutKeyboardFunc(Keyboard);			// ������� ���������� ����������
	glutIdleFunc(Idle);					// �������� ������� IDLE
    glutMainLoop();						// Main ����������
	}