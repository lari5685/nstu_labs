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
double K1 = 0.01, K2 = 0.02;	// Коэффициент упругости и затухания
int Y0 = 250;					// Точка НЕРАСТЯНУТОЙ пружины
int XG;							// Текущая точка графика (ось времени)

void drawCircle(int x, int y, int r, int amountSegments){
	glBegin(GL_POLYGON);				// Окружность - полигон ВРУЧНУЮ
	for(int i = 0; i < amountSegments; i++){
		float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);
		float dx = r * cosf(angle);
		float dy = r * sinf(angle);
		glVertex2f(x + dx, y + dy);
		}
	glEnd(); 
	}

void Display(void){
	// Не стирать, чтобы видеть ТРАССУ
	//glClearColor(0, 0, 0, 1);
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(255, 255, 255);			// Белый график
	glBegin(GL_LINE_LOOP);				// Соединить старую и новую точки
	glVertex2f(XG, Yshow);				// 
	glVertex2f(XG-1, Yold);				// Ось X - ось времени
	glEnd();
	XG++;
	if (XG == Width) XG = Width / 10;	// Дошли до конца - в начало
	glColor3ub(0, 0, 0);
	drawCircle(Xshow, Yshow, R, 50);	// Стереть - старый цветом фона
	glColor3ub(255, 0, 0);
	drawCircle(Xold, Yold, R, 50);		// Нарисовать на новом месте красным
	Xshow = Xold; Yshow = Yold;			// Новое место = старое
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

void Idle(){	// Задержка и ДИНАМИКА
	if (clock()-time0 < delay)
		return;
	time0=clock();				// Ускорение пропорционально растяжению пружины
	Ay = -K1*(Y - Y0) - K2*Vy;	// и скорости движения (оба со знаком - )
	X += Vx;					// Интегрирование координат
	Y += Vy;
	Vx += Ax;					// Интегрирование скорости
	Vy += Ay;
	if ((int)X != Xold || (int)Y != Yold){
		Xold = X;					// Перемещение более чем на пиксель
		Yold = Y;
		glutPostRedisplay();		// Инициализировать перерисовку
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
    glutCreateWindow("Шарик свободное падение");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
	glutIdleFunc(Idle);
    glutMainLoop();
	}