#include"common.h"
#include"USER.h"
#include"func.h"
#include"input.h"
#include"menufunc.h"
#include"mpfunc.h"
#include "select.h"
#include "popup.h"

/*************************************************************
��������void select(int *func, struct mpdata *mp,int *statue,USER *u,int judge,int *tate)
������������ת����,˼ά��ͼ�ṹ��ָ��,�û������ο�״̬�ж�,�û��ṹ��ָ��,�жϰ�ʽ
����ֵ����
�������ܣ�ѡ�����
**************************************************************/
void select(int *func, struct mpdata *mp,int *statue,USER *u,int judge,int *tate)
{
	int light=0;
	int jud1=0;
	int jud2=0;
	int jud3=0;
	int jud4=0;

	setbkcolor(CYAN);
	setcolor(BLUE);
	rectangle(170,60,450,90);
	puthz(178,62,"ѡ��������Ҫ�İ�ʽ",24,30,YELLOW);
	
	setfillstyle(SOLID_FILL,WHITE);
	
	bar(200,160,400,320);
	rectangle(200,160,400,320);
	line(200,240,400,240);
	line(300,160,300,320);
	puthz(220,190,"��ʽһ",16,20,BLUE);
	puthz(220,270,"��ʽ��",16,20,BLUE);
	puthz(312,190,"�Ա�ģʽ",16,20,BLUE);
	puthz(312,270,"�û��ղ�",16,20,BLUE);
	setcolor(RED);
    rectangle(580,10,630,40);
    puthz(585,15,"�˳�",16,20,BLUE);

	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);

		//��ʽһ
		if(MouseX > 200 && MouseX < 300 && MouseY > 160 && MouseY <240)
		{
		if (mouse_press(200, 160, 300, 240) == 1)
			{
				if(judge == 1)
				//�û�
			{
				u->format = 1;
				clrmous(MouseX, MouseY);
				initmp(1, mp);
				clrmous(MouseX,MouseY);
				cleardevice();
				*statue = 1;
				*func = 8;
				return;
			}

			if (judge == 2)
			//�ο͵�½
			{
				Popup_Func(14);
				delay(500);
				*func = 3;
				return;
			}
			}

			if(mouse_press(210, 150, 290, 230) == 2 )
			{
				MouseS = 1;
				if(light == 0 && jud1 ==0)
				
				{
					Light_Select(1);
					light = 1;
					jud1 = 1;
				}
				continue;
			}

		}
	//��ʽ��
		if(MouseX > 200 && MouseX < 300 && MouseY > 240 && MouseY <320)
		{
			if (mouse_press(200,240,300,320) == 1)
			{
				if(judge == 1)
				{
					u->format = 2;
					clrmous(MouseX, MouseY);
					initmp(2, mp);
					clrmous(MouseX,MouseY);
					cleardevice();
					*statue = 2;
					*func = 9;
					return;
				}

				if (judge == 2)
				{
					Popup_Func(14);
					delay(500);
					*func = 3;
					return;
				}

			}

			if(mouse_press(190,230,290,310) == 2)
			{
				MouseS = 1;
				if(light == 0 && jud2 ==0)
				
				{
					Light_Select(2);
					light = 1;
					jud2 = 1;
				}
				continue;
			}
		}

	//�ԱȰ�ʽ
	if(MouseX >300 && MouseX < 400 && MouseY > 160 && MouseY <240)
	{
		
		if(mouse_press(290,150,390,230)==2)
		{
				MouseS = 1;
				if(light == 0 && jud3 ==0)
				
				{
					Light_Select(3);
					light = 1;
					jud3 = 1;
				}
				continue;
		}
		if(mouse_press(300,160,400,240)==1)
		{
			if(judge == 1)
			
			{
				u->format =3;
				*tate = 1;
			}

			if(judge ==2)
			{
				*tate = 0;
			}
			clrmous(MouseX,MouseY);
			cleardevice();
			*func =11;
			return;
		}
	}

	

		//�û�����
	if(MouseX >300 && MouseX < 400 && MouseY > 240 && MouseY <320)
	{
		
		if(mouse_press(290,230,390,310)==2)
		{
				MouseS = 1;
				if(light == 0 && jud4 ==0)
				
				{
					Light_Select(4);
					light = 1;
					jud4 = 1;
				}
				continue;
		}

		if(mouse_press(300,240,400,320)==1)
		{
			if(judge ==1)
			{
				MouseS = 0;
				clrmous(MouseX,MouseY);
				cleardevice();
				*func =12;
				return;
			}

			if (judge == 2)
			{
				Popup_Func(14);
				delay(500);
				*func = 3;
				return;
			}
		}

	}
	  if(MouseX > 580 && MouseX < 630 && MouseY >10 && MouseY <40)
        {
            if(mouse_press(580,10,630,40) == 1)
            {
            MouseS=0;
				clrmous(MouseX,MouseY);
				Popup_Func(3);
			}
            if(mouse_press(580,10,630,40) == 2)
            {
                MouseS = 1;
                continue;
            }
        }


		if(MouseS != 0)
		{
			MouseS = 0;
			continue;
		}

		if(light != 0)
		{
			if(jud1 == 1)
			{
				Recover_Select(1);
				jud1 = 0;
			}

			if(jud2 == 1)
			{
				Recover_Select(2);
				jud2 = 0;
			}
			if(jud3 == 1)
			{
				Recover_Select(3);
				jud3 = 0;
			}
			if(jud4 == 1)
			{
				Recover_Select(4);
				jud4 = 0;
			}
			light = 0;
		}
	}
}

/*************************************************************
��������void Light_Select(int n)
���������
����ֵ����
�������ܣ�����
**************************************************************/
void Light_Select(int n)
{
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	delay(10);
	switch(n)
	{
		case 1:
		bar(200,160,300,240);
		rectangle(200,160,300,240);
		puthz(220,190,"��ʽһ",16,20,WHITE);
		break;

		case 2:
		bar(200,240,300,320);
		rectangle(200,240,300,320);
		puthz(220,270,"��ʽ��",16,20,WHITE);
		break;

		case 3:
		bar(300,160,400,240);
		rectangle(300,160,400,240);
		puthz(312,190,"�Ա�ģʽ",16,20,WHITE);
		break;

		case 4:
		bar(300,240,400,320);
		rectangle(300,240,400,320);
		puthz(312,270,"�û��ղ�",16,20,WHITE);
		break;

		default:
		printf("there is something wrong");
		break;
	}
}

/*************************************************************
��������void Recover_Select(int n)
���������
����ֵ����
�������ܣ��ָ�����
**************************************************************/
void Recover_Select(int n)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(1, WHITE);

	switch(n)
	{
		case 1:
		bar(200,160,300,240);
		rectangle(200,160,300,240);
		puthz(220,190,"��ʽһ",16,20,BLUE);

		case 2:
		bar(200,240,300,320);
		rectangle(200,240,300,320);
		puthz(220,270,"��ʽ��",16,20,BLUE);
		break;

		case 3:
		bar(300,160,400,240);
		rectangle(300,160,400,240);
		puthz(312,190,"�Ա�ģʽ",16,20,BLUE);
		break;

		case 4:
		bar(300,240,400,320);
		rectangle(300,240,400,320);
		puthz(312,270,"�û��ղ�",16,20,BLUE);
		break;
	}
}