#include "common.h"
#include "quit.h"
/*************************************************************
��������Quit()
��������
����ֵ����
�������ܣ��˳�����Ļ���
**************************************************************/	
void Quit()
{
    char s[]="A PICTURE WINS A THOUSAND WORDS";
	char a[] = "MINDMAP";
    settextstyle(2, 0, 10);
    setbkcolor(LIGHTCYAN);
    ellipse(330,150,0,360,100,40);
    setcolor(BLUE);
    outtextxy(255,130,a);
    settextstyle(2, 0, 8);
    outtextxy(100,300,s);
	puthz(80,230,"��ӭ���´μ���ʹ��˼ά��ͼ���л���",24,30,BLUE);
    delay(3000);
	closegraph() ;
    exit(1);   
}