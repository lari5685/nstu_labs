//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include <time.h>
#include <stdlib.h>
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//-------------Глобальнеы переменные
int ON=0;
bool day=true;
int XM,YM;
int cnt=0, numb=0;
TCanvas *img;
//---------------------------------------------------------------------------
void IntToString(char c[], int n)
{
        int nn,k;
        for (nn=n, k=0; nn!=0; k++, nn/=10); // Подсчет количества цифр числа
        c[k] = '\0';                         // Конец строки
        for (k--; k >=0; k--, n /= 10)       // Получение цифр числа
        c[k] = n % 10 + '0';                 // в обратном порядке
}
//-----------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//--------------------- Инициализирующий код---------------------------
        if (ON==1) { ON=0; return; }    // Работает - остановить
        char cc[20];
        img=pbx->Canvas;                // TPaintBox *pbx
        XM=pbx->Width;                  // TCanvas *img
        IntToString(cc,XM);             // Преобразование числа во внешнюю форму
        XX->Text=cc;
        YM=pbx->Height;
        IntToString(cc,YM);
        YY->Text=cc;
        img->Brush->Color=0xFFFF00;             // Цвет 0xBBGGRR
        img->Rectangle(0,0,XM-1,YM-1);          // Прямоугольник
//---------------------------------------------------------------------
        img->Pen->Color=0x808080;              // Цвет пера (линии)
        img->Pen->Width=2;                     // Ширина пера
        img->Ellipse(175,50,275,150);
        img->Ellipse(175,150,275,250);
        img->Ellipse(175,250,275,350);
        ON=1;
}
//------------------------------то---------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        if(day)
        {
                if (ON==0) return;                              // Не нажата кнопка - выйти
                cnt++;
                img->Brush->Color=0xFFFF00;
                if (cnt%100==0) numb++;
                if (numb==4) numb=0;
                if(numb==0)
                {
                        img->Brush->Color=0x0000FF;
                        img->FloodFill(200,100,0x808080, fsBorder);
                        img->Brush->Color=0x000000;
                        img->FloodFill(200,200,0x808080, fsBorder);
                        img->FloodFill(200,300,0x808080, fsBorder);
                }
                if(numb==1)
                {
                        img->Brush->Color=0x00FFFF;
                        img->FloodFill(200,200,0x808080, fsBorder);
                        img->Brush->Color=0x0000FF;
                        img->FloodFill(200,100,0x808080, fsBorder);
                        img->Brush->Color=0x000000;
                        img->FloodFill(200,300,0x808080, fsBorder);

                }
                if(numb==2)
                {
                        if(cnt%100>50)
                        if(cnt%20<=10)
                        {
                                img->Brush->Color=0x00FF00;
                                img->FloodFill(200,300,0x808080, fsBorder);
                                img->Brush->Color=0x000000;
                                img->FloodFill(200,100,0x808080, fsBorder);
                                img->FloodFill(200,200,0x808080, fsBorder);
                        }
                        else
                        {
                              img->Brush->Color=0x000000;
                                img->FloodFill(200,100,0x808080, fsBorder);
                                img->FloodFill(200,200,0x808080, fsBorder);
                                img->FloodFill(200,300,0x808080, fsBorder);
                        }
                        else
                        {
                                img->Brush->Color=0x00FF00;
                                img->FloodFill(200,300,0x808080, fsBorder);
                                img->Brush->Color=0x000000;
                                img->FloodFill(200,100,0x808080, fsBorder);
                                img->FloodFill(200,200,0x808080, fsBorder);
                        }

                }
               if(numb==3)
                {
                        img->Brush->Color=0x00FFFF;
                        img->FloodFill(200,200,0x808080, fsBorder);
                        img->Brush->Color=0x000000;
                        img->FloodFill(200,100,0x808080, fsBorder);
                        img->FloodFill(200,300,0x808080, fsBorder);

                }
        }
        else
        {
                 if (ON==0) return;                 // Не нажата кнопка - выйти
                cnt++;
                if (cnt%50==0) numb++;
                if (numb==2) numb=0;
                if(numb==0)
                {
                        img->Brush->Color=0x00FFFF;
                        img->FloodFill(200,200,0x808080, fsBorder);
                        img->Brush->Color=0x000000;
                        img->FloodFill(200,100,0x808080, fsBorder);
                        img->FloodFill(200,300,0x808080, fsBorder);
                }
                if(numb==1)
                {
                        img->Brush->Color=0x000000;
                        img->FloodFill(200,100,0x808080, fsBorder);
                        img->FloodFill(200,200,0x808080, fsBorder);
                        img->FloodFill(200,300,0x808080, fsBorder);
                }
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::DayNightClick(TObject *Sender)
{
        cnt=0; // профилактика от переполнения
        day=!day;
        if(day)
        {
                img->Brush->Color=0xFFFF00;             // Цвет 0xBBGGRR
                img->Rectangle(0,0,XM-1,YM-1);
        }
        else
        {
                img->Brush->Color=0xFF0000;             // Цвет 0xBBGGRR
                img->Rectangle(0,0,XM-1,YM-1);          // Прямоугольник
         }
        img->Pen->Color=0x808080;              // Цвет пера (линии)
        img->Pen->Width=2;                     // Ширина пера
        img->Ellipse(175,50,275,150);
        img->Ellipse(175,150,275,250);
        img->Ellipse(175,250,275,350);

}
//---------------------------------------------------------------------------

