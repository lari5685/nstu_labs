#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <Math.h>
#include "glut.h"               // Заголовочник  GLUT
using namespace std;
#define PI atan(1)*2

GLint Width = 800, Height = 800;// Начальные размеры окна

int R0 = 100;
double fi = -1;


int R = 300;
double fc = 0.1;
double m  = 0.1;
double k = 0.1;

int x = (R - R0) * cos(fi);
int y = (R - R0) * sin(fi);
double afi, vfi = 0, ar, vr = 0;

//int x0 = Width / 2;
//int y0 = 9 * Height/ 10;

int delay = 10;                 // Задержка в МС между последними IDLE
long time0 = 0;                 // Отметка системного времени

void Display(void) {                // Вывод на экран
    
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3ub(255, 255, 255);      // RGB - цвет заливки
    glBegin(GL_LINES);
        glVertex3d(0, 0, 0);
        glVertex3d(x, -y, 0);
    glEnd();

    glColor3ub(255, 0, 0);      // RGB - цвет заливки
    glPointSize(20);
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
        glVertex3d(0, 0, 0);
        glVertex3d(x, -y, 0);
    glEnd();
    

    glFinish();
}

void Reshape(GLint w, GLint h) {        // Событие - изменение размеров окна
    Width = w;                      // Запомнить новые размеры
    Height = h;
    glViewport(0, 0, w, h);         // Область отображения
    glMatrixMode(GL_PROJECTION);    // Ортографическая проекция
    glLoadIdentity();
    glOrtho(-w/2, w/2, -9*h/10, h/10, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Keyboard(unsigned char key, int x, int y) {
#define ESCAPE '\033'   // Событие - символ клавиатуры
    if (key == ESCAPE)      // Клавиша ESCAPE
        exit(0);            // Закрыть программу
}

void Idle() {               // Постоянное событие - IDLE
    if (clock() - time0 < delay)
        return;             // Не истек интервал delay
    time0 = clock();

    afi = -m * 9.8 * sin(fi+PI) + vfi * -fc;
    vfi += afi * 0.1;
    fi  += vfi * 0.1;

    ar = -vr * fc - k * R0;
    vr += ar * 0.1;
    R0 += vr * 0.1;

    x = (R + R0) * cos(fi);
    y = -(R + R0) * sin(fi);


    glutPostRedisplay();    // Иниициировать событие Display
}

void main(int argc, char* argv[]) {
    time0 = clock();                    // Системное время в МС
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Width, Height);  // Размер окна
    glutCreateWindow("Red square example");
    glutDisplayFunc(Display);           // Функция отображения
    glutReshapeFunc(Reshape);           // Функция смены размерности окна
    glutKeyboardFunc(Keyboard);         // Функция обраболтки клавиатуры
    glutIdleFunc(Idle);                 // Функцция простоя IDLE
    glutMainLoop();                     // Main библиотеки
}