#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <Math.h>
#include <string.h>
#include "glut.h"               // Заголовочник  GLUT
using namespace std;
#define PI atan(1)*2

GLint Width = 800, Height = 800;// Начальные размеры окна

int R0 = 100;                   //положение маятника (R0+R)
double fi = 1;                  //угол маятника


int R = 300;                    //длина пружины
double fc = 0.0005;                //коэффицент сопративления
double m  = 0.1;                //масса
double k = 0.1;                 //коэффицент упругости


int x = (R - R0) * cos(fi);     //положение маятника по декарту
int y = (R - R0) * sin(fi);     //положение маятника по декарту
double afi, vfi = 0, ar, vr = 0;
bool state = false;
int flag = 0;

//int x0 = Width / 2;
//int y0 = 9 * Height/ 10;

int delay = 10;                 // Задержка в МС между последними IDLE
long time0 = 0;                 // Отметка системного времени

double E(double x) {
    return (x - Width / 10) / 1000;
}
double Ln(double x) {
    return x*1000 + Width / 10;
}

void renderBitmapString(
    float x,
    float y,
    //float z,
    void* font,
    char* string) {

    char* c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void Display(void) {                // Вывод на экран
    
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3ub(255, 255, 255);      // RGB - цвет заливки
    glBegin(GL_LINES);
        glVertex2d(Width / 2, 7 * Height / 10);
        glVertex3d(x + Width / 2, -y + 8 * Height / 10, 0);
    glEnd();

    glColor3ub(255, 0, 0);      // RGB - цвет заливки
    glPointSize(20);
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
        glVertex2d(Width / 2, 7 * Height / 10);
        glVertex3d(x + Width / 2, -y + 8 * Height / 10, 0);
    glEnd();

    glBegin(GL_LINES);
        glVertex3d(Width / 10, 9.5*Height/10, 0);
        glVertex3d(9 * Width / 10, 9.5 * Height / 10, 0);

        glVertex3d(Width / 10, 9 * Height / 10, 0);
        glVertex3d(9 * Width / 10, 9 * Height / 10, 0);

    glEnd();
    glBegin(GL_POINTS);
        glVertex3d(Ln(m), 9.5 * Height / 10, 0);
        glVertex3d(Ln(k), 9 * Height / 10, 0);
    glEnd();

    char text[] = "M";
    renderBitmapString(0.5 * Width / 10, 9.5 * Height / 10 - 5, GLUT_BITMAP_TIMES_ROMAN_24, text);
    text[0] = 'K';
    renderBitmapString(0.5 * Width / 10, 9 * Height / 10 - 5, GLUT_BITMAP_TIMES_ROMAN_24, text);
    char num[10];
    sprintf_s(num, "%0.3f", m);
    renderBitmapString(9.2 * Width / 10, 9.5 * Height / 10 - 5, GLUT_BITMAP_TIMES_ROMAN_24, num);
    sprintf_s(num, "%0.3f", k);
    renderBitmapString(9.2 * Width / 10, 9 * Height / 10 - 5, GLUT_BITMAP_TIMES_ROMAN_24, num);

    glFinish();
}

void Reshape(GLint w, GLint h) {        // Событие - изменение размеров окна
    Width = w;                      // Запомнить новые размеры
    Height = h;
    glViewport(0, 0, w, h);         // Область отображения
    glMatrixMode(GL_PROJECTION);    // Ортографическая проекция
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Keyboard(unsigned char key, int x, int y) {
#define ESCAPE '\033'   // Событие - символ клавиатуры
    if (key == ESCAPE)      // Клавиша ESCAPE
        exit(0);            // Закрыть программу
    if (key == 32)
        state = !state;
          
}

void Idle() {               // Постоянное событие - IDLE
    if (clock() - time0 < delay)
        return;             // Не истек интервал delay
    time0 = clock();
    if (state) {
        afi = -m * 9.8 * sin(fi + PI) + sin(vfi)*(R0+R) * -fc;
        vfi += afi * 0.1;
        fi += vfi * 0.1;

        ar = -vr * fc - k * R0;
        vr += ar * 0.1;
        R0 += vr * 0.1;
        
    }

    x = (R + R0) * cos(fi);
    y = -(R + R0) * sin(fi);

    glutPostRedisplay();    // Иниициировать событие Display
}
void Mouse(int button, int status, int cx, int cy) {
    if (cy > 1.4 * Width / 10 || flag == 3) {
        state = status == GLUT_DOWN ? false : state;
        state = status == GLUT_UP ? true : state;
    }
    cout << status << "\n";
    status == 1 ? flag = 0 : flag = flag;

}
void Motion(int cx, int cy) {

    if ((cy > 1.4 * Height/10 && flag == 0) || flag == 3) {
        flag = 3;
        cx -= Width / 2;
        cy -= 2*Height / 10;
        cx = cx == 0 ? 1 : cx;
        R0 = sqrt(cx * cx + cy * cy) - R;
        fi = -atan2(cy, cx);

        vfi = 0; vr = 0; afi = 0; ar = 0;
    }
    if (cy > 0 && cy < 0.7 * Height / 10 && flag == 0) { // m
        flag = 1;
        if (cx > Width / 10 && cx < 9 * Width / 10) {
            m = E(cx);
        }
    }
    if (cy > 0.7 * Height / 10 && cy < 1.4 * Height / 10 && flag == 0) { // k
        flag = 2;
        if (cx > Width / 10 && cx < 9 * Width / 10) {
            k = E(cx);
        }
    }
    if (flag != 0) {
        if (cx > Width / 10 && cx < 9 * Width / 10) {
            if (flag == 1)
                m = E(cx);
            if (flag == 2)
                k = E(cx);
        }
    }

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
    glutMouseFunc(Mouse);
    glutMotionFunc(Motion);
    glutMainLoop();                     // Main библиотеки
}