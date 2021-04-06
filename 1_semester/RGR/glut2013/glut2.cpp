#include <stdlib.h>
#include <time.h>

#include <glut.h>				// ������������  GLUT
GLint Width = 512, Height = 512;// ��������� ������� ����
int CubeSize0 = 200;			// ��������� ������ ��������
int CubeSize = 200;
int dd=3;						// ���������� ������� �������� � + �� -
int delay=20;					// �������� � �� ����� ���������� IDLE
long time0=0;					// ������� ���������� �������

void Display(void){				// ����� �� �����
    int left, right, top, bottom;
    left  = (Width - CubeSize) / 2;
    right = left + CubeSize;
    bottom = (Height - CubeSize) / 2;
    top = bottom + CubeSize;	// ���������� - ������� �� ��������
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);    
    glColor3ub(255,0,0);		// RGB - ���� �������
    glBegin(GL_QUADS);			// ������ ��������
    glVertex2f(left,bottom);	// ������� ��������
    glVertex2f(left,top);
    glVertex2f(right,top);
    glVertex2f(right,bottom);
    glEnd();
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
	if (CubeSize<30 && dd>0 || CubeSize>200 && dd<0){
		dd=-dd;				// ������� ����������� ���������
		}
	CubeSize-=dd;			// �������� ������� ��������
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