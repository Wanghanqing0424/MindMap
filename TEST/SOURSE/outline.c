#include"common.h"
#include"mpfunc.h"
/*************************************************************
��������draw_outline(struct mpdata mp)
������˼ά��ͼ�ṹ��mp
����ֵ����
�������ܣ����ƴ��ģʽ����
**************************************************************/	
void draw_outline(struct mpdata mp)
{
    int i;
    int j;
    int k = 0;
    cleardevice();
    setbkcolor(WHITE);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(540, 0, 640, 50);
    puthz(541, 1, "����", 48, 50, RED);
    for(i = 0; i < mp.amooflevel; i++)
    {
        for (j = 0; j < mp.amoofson[i]; j++)
        {
            put_all(i * 20, k * 20, mp.text[i][j].hz, 5, color_select(i, j, mp));
            k++;
        }
    }
}
/*************************************************************
��������color_select(int i, int j, struct mpdata mp)
�������ı�����ij,˼ά��ͼ�ṹ��mp
����ֵ����
�������ܣ�ѡ��������ɫ
**************************************************************/	
int color_select(int i, int j, struct mpdata mp)
{
    //��ע���ı����ú�ɫ����
    if (mp.text[i][j].state == 1)
    {
        return RED;
    }
    //δ��ע���ı��������ɫ����
    if (mp.text[i][j].state == 0)
    {
		return DARKGRAY;
    }
}
/*************************************************************
��������outline_func(int state, int *func, struct mpdata mp)
������˼ά��ͼ��ʽstate,���������ַ*func,˼ά��ͼ�ṹ��mp
����ֵ����
�������ܣ����ģʽ�Ĺ���ѡ��
**************************************************************/
void outline_func(int state, int *func, struct mpdata mp)
{
    draw_outline(mp);
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        //����
        if (MouseX > 540 && MouseX < 640 && MouseY > 0 && MouseY < 50)
        {
            if (mouse_press(540, 0, 640, 50) == 1)
            {
                delay(500);
                clrmous(MouseX, MouseY);
				cleardevice();
                if (state == 1)
                {
                    *func = 3;
                }
                if (state == 2)
                {
                    *func = 3;
                }
				return;		
            }
        }
    }
}