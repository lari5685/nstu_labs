#include <windows.h>
#include <glut.h> 
//���������
void Display()
{
}
 
//���������� ������
void Reshape(int Width, int higth)
{
}
 
//������� ������
void KeyPress(unsigned char key, int lParam, int rParam)
{
}
//������
void Timer(int lparam)
{
}
 
void main(int argv, char *argc[])
{
    glutInit(&argv, argc);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("��� ����");
    glutDisplayFunc(Display);
    glutKeyboardFunc(KeyPress);
    glutReshapeFunc(Reshape);
    glutTimerFunc(0, Timer, 0);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}

