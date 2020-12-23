#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <glut.h>
GLint Width = 1000, Height = 500;
int delay=20;
long time0=0;
double X, Y;
double AOM, OM, FI;				// Угловое ускорение, скорость и угол поворота	
int Xold,Yold;
int Xshow, Yshow;
double K1 = 0.003, K2 = 0.003;	// Коэффициент упругости и затухания
int X0 = 200, Y0 = 250, R=200;	// Центр и длина маятника
int XG;							// Текущая точка графика (ось времени)
int RM = 20;

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
	if (XG == Width) XG = Width / 2;	// Дошли до конца - в начало
	glColor3ub(0, 0, 0);		
	glBegin(GL_LINE_LOOP);				// Стереть ось маятника
	glVertex2f(X0, Y0);					// 
	glVertex2f(Xshow, Yshow);				
	glEnd();
	glColor3ub(255, 255, 255);			// Нарисовать ось маятника
	glBegin(GL_LINE_LOOP);				//
	glVertex2f(X0, Y0);					// 
	glVertex2f(Xold, Yold);				
	glEnd();
	glColor3ub(0, 0, 0);
	drawCircle(Xshow, Yshow, RM, 50);	// Стереть - старый цветом фона
	glColor3ub(255, 0, 0);
	drawCircle(Xold, Yold, RM, 50);		// Нарисовать на новом месте красным
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
	time0=clock();					// Ускорение пропорционально синусу угла отклонения
	AOM = -K1 * sin(FI) - K2 * OM;
	FI += OM;						// Интегрированиеугла и скорости
	OM += AOM;
	X = X0 + R * sin(FI);			// Перевод полярной в прямоугольную
	Y = Y0 - R * cos(FI);			// 
	if ((int)X != Xold || (int)Y != Yold){
		Xold = X;					// Перемещение более чем на пиксель
		Yold = Y;
		glutPostRedisplay();		// Инициализировать перерисовку
		}
	}

void main(int argc, char *argv[]){
	Y0 = Height / 2;
	X0 = Width / 4;
	FI = 3.14;			// Почти вертикально
	OM = 0;
	X = X0 + R * sin(FI);			// Перевод полярной в прямоугольную
	Y = Y0 - R * cos(FI);			// 
	Xshow = Xold = X;
	Yshow = Yold = Y;
	XG = Width /2;
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