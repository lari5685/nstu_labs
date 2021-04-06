#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include <glut.h>				// Заголовочник  GLUT
GLint Width = 512, Height = 512;// Начальные размеры окна
int SZ = 200;
int XY0 = 50;
int dd=3;						// Приращение размера меняется с + на -
int delay=20;					// Задержка в МС между последними IDLE
long time0=0;					// Отметка системного времени
int X0 = 500, Y0 = 400;			// Координаты БЕСКОНЕЧНОСТИ
double K = 0.002;				// Сжатие по оси Z (перспектива)

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

void Display(void){				// Вывод на экран
    glClear(GL_COLOR_BUFFER_BIT);    
    glColor3ub(255,0,0);		// RGB - цвет заливки
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

void Reshape(GLint w, GLint h){		// Событие - изменение размеров окна
    Width = w;						// Запомнить новые размеры
    Height = h;
    glViewport(0, 0, w, h);			// Область отображения
    glMatrixMode(GL_PROJECTION);	// Ортографическая проекция
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	}

void Keyboard(unsigned char key, int x, int y){
	#define ESCAPE '\033'	// Событие - символ клавиатуры
    if( key == ESCAPE )		// Клавиша ESCAPE
        exit(0);			// Закрыть программу
	}

void Idle(){				// Постоянное событие - IDLE
	if (clock()-time0 < delay)
		return;				// Не истек интервал delay
	time0=clock();			// Запомнить новую отметку времени
	if (SZ<30 && dd>0 || SZ>300 && dd<0){
		dd=-dd;				// Сменить направление пульсации
		}
	SZ-=dd;					// Изменить размеры квадрата
	glutPostRedisplay();	// Иниициировать событие Display
	}

void main(int argc, char *argv[]){
	time0 = clock();					// Системное время в МС
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Width, Height);	// Размер окна
    glutCreateWindow("Red square example");
    glutDisplayFunc(Display);			// Функция отображения
    glutReshapeFunc(Reshape);			// Функция смены размерности окна
    glutKeyboardFunc(Keyboard);			// Функция обраболтки клавиатуры
	glutIdleFunc(Idle);					// Функцция простоя IDLE
    glutMainLoop();						// Main библиотеки
	}