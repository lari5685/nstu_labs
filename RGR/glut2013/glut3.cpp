#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <glut.h>
GLint Width = 512, Height = 512;
int delay=20;
long time0=0;
int ON=0,Y0,YG;
double xx1,yy1,xx0,yy0,vx,vy,dx,dy,ax,ay,r,xold,yold;
double K;
double POW;
int first=1;

void drawCircle(int x, int y, int r, int amountSegments){
	glBegin(GL_POLYGON);
	for(int i = 0; i < amountSegments; i++){
		float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);
		float dx = r * cosf(angle);
		float dy = r * sinf(angle);
		glVertex2f(x + dx, y + dy);
		}
	glEnd(); 
	}

void Display(void){
	if (first){
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3ub(255,0,0);
		drawCircle(xx0, yy0, 20, 20); 
		glFlush();      
		glFinish();		
		first=0;
		return;
		}
	glColor3ub(250,250,250);
	if (xold!=0){
		glBegin(GL_LINE_LOOP);
		glVertex2f(xold, yold);
		glVertex2f(xx1, yy1);
		glEnd(); 
		glFlush();      
		glFinish();		
		}
	xold=xx1;
	yold=yy1;
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

void Idle(){
	if (clock()-time0 < delay)
		return;
	time0=clock();
    int cl,dd,xx,yy;
    int sx=(xx1<xx0 ? 1 : -1);				// Квадрант НЕБЕСНОГО ТЕЛА
	int sy=(yy1<yy0 ? 1 : -1);				// (знак проекции ускорения)
	r=sqrt(pow(xx1-xx0,2)+pow(yy1-yy0,2));	// Расстояние
	double fi=asin(fabs(yy1-yy0)/r);		// УГОЛ между СОЛЦЕМ и ТЕЛОМ
	double aa=K/(pow(r,POW));				// Модуль ускорения
	ax=sx*aa*cos(fi);						// Проекции ускорения
	ay=sy*aa*sin(fi);
	vx+=ax;									// Интегрирование движения
	vy+=ay;
	xx1+=vx;
	yy1+=vy;
	glutPostRedisplay();
	}

void main(int argc, char *argv[]){
	xx0 = Width / 2;	// Координаты СОЛНЦА
	yy0 = Height/2;
	xx1=xx0-100;		// Координаты НЕБЕСНОГО ТЕЛА
	yy1=yy0-50;
	vx=-0.2;			// Начальная скорость
	vy=1;
	dx=0;
	dy=0;
	K=200;
	POW = 1.75;			// СТЕПЕНЬ закона тяготения
	xold=yold=0;
	time0 = clock();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("Red square example");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
	glutIdleFunc(Idle);
    glutMainLoop();
	}