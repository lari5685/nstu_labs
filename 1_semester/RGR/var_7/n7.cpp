#include <stdlib.h>
#include <iostream>
#include <time.h>               // системное время
#include <Math.h>               // математические операторы
#include <string.h>             // работа со строками
#include "glut.h"               // Заголовочник  GLUT
using namespace std;

#define PI atan(1)*2            // pi constant

GLint Width = 800, Height = 800;// Начальные размеры окна

int R0 = 100;                   // Начальное положение маятника
double fi = 1;                  

int R = 300;                    // точка равновесия маятника
double fc = 0.0005;             // коэффициент сопративления
double m  = 0.1;                // масса
double k = 0.1;                 // коэффициент упругости
double afi = 0, vfi = 0;        // ускорение и скорость
double ar = 0, vr = 0;
bool state = false;             // флаг движения тела (true - движется, false - стоит)
int flag = 0;                   // выбор что изменять (1-масса 2-упругость 3-положение)

int delay = 10;                 // Задержка в МС между кадрами
long time0 = 0;                 // Отметка системного времени

int x = (R - R0) * cos(fi);     // положение маятника по декарту
int y = (R - R0) * sin(fi);     


double E(double x) {
    return (x - Width / 10) / 1000;
}
double Ln(double x) {
    return x*1000 + Width / 10;
}

void renderBitmapString(
    float x,
    float y,
    void* font,
    char* string) {

    char* c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void Display(void) {                // Вывод на экран
    
    glClearColor(0, 0, 0, 1);       // стираем все
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);              // Рисуем линию от центра до тела
        glVertex2d(Width / 2, 7 * Height / 10);
        glVertex3d(x + Width / 2, -y + 8 * Height / 10, 0);
    glEnd();

    glColor3ub(255, 0, 0);
    glPointSize(20);
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);             // Рисуем 2 точки - цетр и тело
        glVertex2d(Width / 2, 7 * Height / 10);
        glVertex3d(x + Width / 2, -y + 8 * Height / 10, 0);
    glEnd();

    glBegin(GL_LINES);              // Рисуем 2 ползунка
        glVertex3d(Width / 10, 9.5*Height/10, 0);
        glVertex3d(9 * Width / 10, 9.5 * Height / 10, 0);

        glVertex3d(Width / 10, 9 * Height / 10, 0);
        glVertex3d(9 * Width / 10, 9 * Height / 10, 0);

    glEnd();
    glBegin(GL_POINTS);             // И 2 торчки на них
        glVertex3d(Ln(m), 9.5 * Height / 10, 0);
        glVertex3d(Ln(k), 9 * Height / 10, 0);
    glEnd();

    char text[] = "M";              // Рисуем букавки и цифарки на экране
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
    if (key == 32)          // Клавиша SPASE
        state = !state;     // Измениить статус
          
}

void Idle() {               // Постоянное событие - IDLE
    if (clock() - time0 < delay)
        return;             // Не истек интервал delay
    time0 = clock();
    if (state) {            // Условие работы
                            // Расчет нового ускорения, скорости и координаты
        afi = -m * 9.8 * sin(fi + PI) + sin(vfi)*(R0+R) * -fc;
        vfi += afi * 0.1;
        fi += vfi * 0.1;

                            // Расчет нового ускорения, скорости и координаты
        ar = -vr * fc - k * R0;
        vr += ar * 0.1;
        R0 += vr * 0.1;
        
    }

    x = (R + R0) * cos(fi); // Перевод к декарту
    y = -(R + R0) * sin(fi);

    glutPostRedisplay();    // Иниициировать событие Display
}

void Mouse(int button, int status, int cx, int cy) {
    if (cy > 1.4 * Width / 10 || flag == 3) { // Если ниже ползунков
        state = status == GLUT_DOWN ? false : state; // Нажата лкм - остановить движение
        state = status == GLUT_UP ? true : state;    // Отпущена лкм - запустить движение
    }
    flag = status == GLUT_UP ?  0 :  flag; // Отпустили лкм? Прекратили изменять
}

void Motion(int cx, int cy) {
    if ((cy > 1.4 * Height/10 && flag == 0) || flag == 3) { //если начали движение в районе маятника
        flag = 3;

        cx -= Width / 2;
        cy -= 2*Height / 10;

        cx = cx == 0 ? 1 : cx; // Защита от деления на 0
        R0 = sqrt(cx * cx + cy * cy) - R;
        fi = -atan2(cy, cx);

        vfi = 0; vr = 0; afi = 0; ar = 0;
    }

    if (cy > 0 && cy < 0.7 * Height / 10 && flag == 0) { //если начали двигать верхний ползунок
        flag = 1; // ползунок - масса
        if (cx > Width / 10 && cx < 9 * Width / 10) {
            m = E(cx);
        }
    }

    if (cy > 0.7 * Height / 10 && cy < 1.4 * Height / 10 && flag == 0) { //если начали двигать нижний ползунок
        flag = 2; // ползунок - упругость
        if (cx > Width / 10 && cx < 9 * Width / 10) {
            k = E(cx);
        }
    }

    if (flag != 0) { // Движение ползунков - фикс бага
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
    glutCreateWindow("maitnik");
    glutDisplayFunc(Display);           // Функция отображения
    glutReshapeFunc(Reshape);           // Функция смены размерности окна
    glutKeyboardFunc(Keyboard);         // Функция обраболтки клавиатуры
    glutIdleFunc(Idle);                 // Функцция простоя IDLE
    glutMouseFunc(Mouse);               // Функцция обработки мыши
    glutMotionFunc(Motion);             // Функцция обработки движения мыши
    glutMainLoop();                     // Main библиотеки
}