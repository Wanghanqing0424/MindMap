#include"common.h"
#include"func.h"
#include"hz.h"
#include"mouse.h"
#include "drawmenu.h"
#include"menufunc.h"
#include"mpfunc.h"
/*************************************************************
��������void welcome()
��������
����ֵ����
�������ܣ���ӭ����Ļ���
**************************************************************/	
void welcome()
{
    int x=250,y=320;
    char s[]="made by WangHanqing and MaRunze";
	//����ͼ��
    clrmous(MouseX,MouseY);
	setbkcolor(BLACK);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,0,3);
	moveto(x,y);       
	lineto(x,y-10);
	lineto(x+10,y-10);
	lineto(x+10,y-20);
	lineto(x+20,y-20);
	lineto(x+20,y-30);
	lineto(x+30,y-30);
	lineto(x+30,y-40);
	lineto(x+40,y-40);
	lineto(x+40,y-50);
	lineto(x+50,y-50);
	lineto(x+50,y-60);
	lineto(x+100,y-60);
	lineto(x+100,y-50);
	lineto(x+110,y-50);
	lineto(x+110,y-40);
	lineto(x+120,y-40);
	lineto(x+120,y-20);
	lineto(x+130,y-20);
	lineto(x+130,y-10);
	lineto(x+140,y-10);
	lineto(x+140,y+10);
	lineto(x+130,y+10);
	lineto(x+130,y+20);
	lineto(x+120,y+20);
	lineto(x+120,y+30);
	lineto(x+110,y+30);
	lineto(x+110,y+50);
	lineto(x+100,y+50);
	lineto(x+100,y+60);
	lineto(x+70,y+60);
	lineto(x+70,y+70);
	moveto(x+60,y+70);
	lineto(x+60,y+50);
	lineto(x+90,y+50);
	lineto(x+90,y+40);
	lineto(x+80,y+40);
	moveto(x+100,y+40);
	lineto(x+100,y+30);
	lineto(x+30,y+30);
	lineto(x+30,y+20);
	lineto(x+20,y+20);
	lineto(x+20,y+10);
	lineto(x+10,y+10);
	lineto(x+10,y);
	lineto(x,y);
	line(x+70,y-50,x+80,y-50);
	line(x+90,y-50,x+100,y-50);
	line(x+40,y-40,x+50,y-40);
	line(x+60,y-40,x+90,y-40);
	line(x+30,y-30,x+40,y-30);
	line(x+50,y-30,x+100,y-30);
	line(x+20,y-20,x+40,y-20);
	line(x+50,y-20,x+70,y-20);
	line(x+80,y-20,x+110,y-20);
	line(x+10,y-10,x+30,y-10);
	line(x+40,y-10,x+60,y-10);
	line(x+80,y-10,x+90,y-10);
	line(x+100,y-10,x+120,y-10);
	line(x+30,y,x+40,y);
	line(x+50,y,x+60,y);
	line(x+70,y,x+80,y);
	line(x+90,y,x+110,y);
	line(x+120,y,x+130,y);
	line(x+20,y+10,x+30,y+10);
	line(x+50,y+10,x+60,y+10);
	line(x+70,y+10,x+90,y+10);
	line(x+100,y+10,x+110,y+10);
	line(x+30,y+20,x+40,y+20);
	line(x+50,y+20,x+70,y+20);
	line(x+80,y+20,x+90,y+20);
	line(x+100,y+20,x+110,y+20);
	line(x+20,y-10,x+20,y);
	line(x+30,y-10,x+30,y);
	line(x+40,y-20,x+40,y-10);
	line(x+40,y+10,x+40,y+20);
	line(x+50,y-30,x+50,y-20);
	line(x+50,y-10,x+50,y);
	line(x+50,y+20,x+50,y+30);
	line(x+60,y-50,x+60,y-40);
	line(x+60,y+10,x+60,y+20);
	line(x+70,y-20,x+70,y-10);
	line(x+70,y,x+70,y+10);
	line(x+80,y-60,x+80,y-50);
	line(x+80,y-20,x+80,y);
	line(x+80,y+20,x+80,y+40);
	line(x+90,y-40,x+90,y-30);
	line(x+90,y,x+90,y+20);
	line(x+100,y-50,x+100,y-40);
	line(x+100,y-30,x+100,y-20);
	line(x+100,y-10,x+100,y);
	line(x+110,y-30,x+110,y-20);
	line(x+110,y,x+110,y+10);
	line(x+110,y+20,x+110,y+30);
	line(x+120,y,x+120,y+30);         
	//����
    puthz(200,100,"˼",48,60,RED);
    delay(250);
    cover_TITLE(100,200,BLACK);
    puthz(270,100,"ά",48,60,RED);
    delay(250);
    cover_TITLE(170,200,BLACK);
    puthz(340,100,"��",48,60,RED);
    delay(250);
    cover_TITLE(240,200,BLACK);
    puthz(410,100,"ͼ",48,60,RED);
    delay(250);
    cover_TITLE(310,200,BLACK);
    puthz(200,100,"˼ά��ͼ",48,70,RED);
    
    outtextxy(380,180,s);
   
    delay(2000);
    cleardevice();

}

