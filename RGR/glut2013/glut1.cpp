#include <windows.h>
#include <glut.h> 
//Рисование
void Display()
{
}
 
//Обновление экрана
void Reshape(int Width, int higth)
{
}
 
//нажатие клавиш
void KeyPress(unsigned char key, int lParam, int rParam)
{
}
//таймер
void Timer(int lparam)
{
}
 
void main(int argv, char *argc[])
{
    glutInit(&argv, argc);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Мое окно");
    glutDisplayFunc(Display);
    glutKeyboardFunc(KeyPress);
    glutReshapeFunc(Reshape);
    glutTimerFunc(0, Timer, 0);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}

