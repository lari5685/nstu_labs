#include <stdlib.h>
#include <time.h>

#include <glut.h>				// Заголовочник  GLUT
GLint Width = 512, Height = 512;// Начальные размеры окна
int CubeSize0 = 200;			// Начальный размер квадрата
int CubeSize = 200;
int dd=3;						// Приращение размера меняется с + на -
int delay=20;					// Задержка в МС между последними IDLE
long time0=0;					// Отметка системного времени

void Display(void){				// Вывод на экран
    int left, right, top, bottom;
    left  = (Width - CubeSize) / 2;
    right = left + CubeSize;
    bottom = (Height - CubeSize) / 2;
    top = bottom + CubeSize;	// Координаты - квадрат ПО СЕРЕДИНЕ
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);    
    glColor3ub(255,0,0);		// RGB - цвет заливки
    glBegin(GL_QUADS);			// Начало полигона
    glVertex2f(left,bottom);	// Вершина полигона
    glVertex2f(left,top);
    glVertex2f(right,top);
    glVertex2f(right,bottom);
    glEnd();
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
	if (CubeSize<30 && dd>0 || CubeSize>200 && dd<0){
		dd=-dd;				// Сменить направление пульсации
		}
	CubeSize-=dd;			// Изменить размеры квадрата
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