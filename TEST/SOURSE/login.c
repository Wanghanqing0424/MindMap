#include"common.h"
#include"login.h"
#include"USER.h"
#include"func.h"
#include"input.h"
#include "quit.h"
#include "popup.h"
#include "file.h"
/*************************************************************
��������Userslogin_func(int *func,USER*u, struct mpdata *mp,int *judge) 
���������������ַ*func,�û����ݵ�ַ*u,˼ά��ͼ�ṹ���ַ*mp,�ж��Ƿ��¼�ɹ��ı�־��ַ*judge
����ֵ����
�������ܣ���¼����Ĺ���ѡ��
**************************************************************/	
void Userslogin_func(int *func,USER*u, struct mpdata *mp,int *judge) 
{
	
	
	char	*s;
	int judge1=0;
	int judge2=0;

	draw_login();
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);

		//�����û���
		if(MouseX>260 && MouseX<260+315 &&MouseY>190 &&MouseY<220)
		{
			if (mouse_press(260, 190, 260 + 315, 220) == 1)
			{
				settextstyle(SMALL_FONT, HORIZ_DIR, 6);
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260, 190, 260 + 315, 220, RED, LIGHTGRAY, 1);
				u->user[0]='\0';
				
				inputadmin(u->user, 260, 190, 12, LIGHTGRAY);
				if(strlen(u->user)!=0)
					judge1=1;
				else
					judge1=0;
				continue;
		    }
		}
		
		//��������
		if(MouseX>260 && MouseX<260+315 &&MouseY>250 &&MouseY<280)
		{
			if (mouse_press(260, 250, 260 + 315, 280) == 1)
			{
				settextstyle(SMALL_FONT, HORIZ_DIR, 6);
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260, 250, 260 + 315, 280, RED, LIGHTGRAY, 1);
				u->password[0]='\0';
				inputpassword(u->password, 260, 250, 12, LIGHTGRAY);
				if(strlen(u->password)!=0)
					judge2=1;
				else
					judge2=0;
				continue;
		    }
		}

		//�ο͵�¼
		if(MouseX>340 && MouseX<570 && MouseY >310 && MouseY<345)
		{
			if(mouse_press(340, 310, 570, 345)==2)
			{
				MouseS=1;
				continue;
			}

			else if(mouse_press(340, 310, 570, 345)==1)
			{
				clrmous(MouseX,MouseY);
				cleardevice();
				*func = 3;
				*judge = 2;
				return;
			}
		}
		
		if(MouseX>260 && MouseX<260+315 && MouseY >250 && MouseY<280)
		{
			if(mouse_press(260, 250, 260 + 315, 280)==2)
			{
				MouseS=2;
				continue;
			}		
		}
		
		if(MouseX>290 && MouseX<350 && MouseY >380 && MouseY<405)
		{
			if(mouse_press(290, 380, 350, 405)==2)
			{
				MouseS=1;

				continue;
			}			
			
			//ע��
			else if(mouse_press(290, 380, 350, 405) == 1)
			{
				cleardevice();
				MouseS=0;
				*func=1;
				return;			
			}
		}

		if(MouseX>100 && MouseX<380 && MouseY >169 && MouseY<405)
		{
			if(mouse_press(100, 380, 169, 405)==2)
			{
				MouseS=1;
				continue;
			}

			//�˳�
	    	else if(mouse_press(100, 380, 169, 405) == 1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				Popup_Func(3);
			}			
		}

		if(MouseX>480 && MouseX<570 && MouseY >380 && MouseY<405)
		{
			if(mouse_press(480, 380, 570, 405)==2)
			{
				MouseS=1;
				continue;
			}
			//��������
		 	else if(mouse_press(480, 380, 570, 405) == 1)
			{
				MouseS=0;
				*func=2;
				return;
			}	
		}

		if(MouseX>260 && MouseX<260+315 && MouseY >190 && MouseY<220)
		{
			if(mouse_press(260, 190, 260 + 315, 220)==2)
			{
				MouseS=2;
				continue;
			}
		}

		if(MouseX>140 && MouseX<315 && MouseY >310 && MouseY<345)
		{
			if(mouse_press(140, 310, 315, 345)==2)
			{
				MouseS=1;
				continue;
			}

			//��¼
		 	else if(mouse_press(140, 310, 315, 345) == 1)
			{
				if(login_complete(u->user, u->password))
				{
					MouseS=0;
					Copy_infor_User(u);
					clrmous(MouseX,MouseY);
					cleardevice();
					*judge = 1;
					*func=3;
					return;
				}
				else
				{
					*func=0;
					return;
				}
			}
		}
		
		if(MouseS!=0)
		{
			MouseS=0;
			continue;
		}
	}
}
/*************************************************************
��������draw_login() 
��������
����ֵ����
�������ܣ���¼����Ļ���
**************************************************************/	
void draw_login()
//���Ƶ�¼����
{
    	
	//������
	setbkcolor(GREEN);
    setcolor(YELLOW);
    puthz(230, 130, "˼ά��ͼ", 48, 50, BLUE);
	
	//���ı���
    setfillstyle(SOLID_FILL,RED);
	setfillstyle(SOLID_FILL, WHITE);
	
	//�û���
	bar(140, 190, 260, 220);
	bar(260, 190, 260 + 315, 220);

	//����
	bar(140, 250, 260, 280);
	bar(260, 250, 260 + 315, 280);	

    //����¼С��
	sector(320, 100, 230, 310, 35, 35);
	fillellipse(320, 100 - 5, 15, 15);
	setcolor(RED);
	circle(320, 100-5, 15);	
	
	//�ڶ�����¼С��
	setfillstyle(1, RED);
	sector(102, 203, 230, 310, 15, 15);
	fillellipse(102, 203 - 2, 7, 7);
	setcolor(RED);
	circle(102, 203 - 2, 7);
	
	//����
	setcolor(BROWN);
	rectangle(89, 260, 115, 275);
	arc(102, 260, 0, 180, 7);
	circle(102, 267, 4);
	//�߿�
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, 3);
	line(260, 190, 260, 220);
	line(260, 250, 260, 280);	
	rectangle(140, 190, 260 + 315, 220);
	rectangle(140, 250, 260 + 315, 280);	

	puthz(153, 193, "�û���", 24, 34, LIGHTRED);
	puthz(163, 253, "����", 24, 50, LIGHTRED);

	setfillstyle(SOLID_FILL, RED);
	bar(140, 310, 315, 345);
	puthz(180, 315, "��¼", 24, 70, WHITE);

	setfillstyle(SOLID_FILL, RED);
	bar(340, 310, 570, 345);
	puthz(385, 315, "�ο͵�½", 24, 40, WHITE);
	
	//ע��ͷ���
	setlinestyle(SOLID_LINE, 0, 1);
	setfillstyle(SOLID_FILL, WHITE);
	bar(290, 380, 350, 405);
	puthz(302, 385, "ע��", 16, 24, LIGHTRED);
	setlinestyle(SOLID_LINE, 0, 2);
	setcolor(LIGHTRED);
	rectangle(290, 380, 350, 405);

	bar(100, 380, 169, 405);
	puthz(114, 385, "�˳�", 16, 24, LIGHTRED);
	rectangle(100, 380, 169, 405);

	bar(480, 380, 570, 405);
	puthz(492, 385, "��������", 16, 18, LIGHTRED);
	rectangle(480, 380, 570, 405);
}

/*************************************************************
��������login(char* name, char*password)
�����������û����������ַ*name,��������������ַ*password
����ֵ����
�������ܣ��ж��û����������Ƿ�ƥ��
**************************************************************/	
int login(char* name, char*password)
{
	int len;
	int i;
	FILE* fp;
	USER* u;
	if ((fp = fopen(".\\USERS\\userdata.dat", "rb+")) == NULL)
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(name, u->user) == 0)
		//�û���ƥ��
		{
			if (strcmp(password, u->password) != 0)
			//���벻��
			{
				puthz(450, 290, "�������", 16, 17, RED);
				delay(1000);
				cover_tips(450,290,GREEN);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				break;
			}
			else if (strcmp(password, u->password) == 0)
			//����ƥ��
			{
				puthz(290, 355, "��¼�ɹ�", 16, 17, RED);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				delay(1000);
				if (fclose(fp) != 0)
				{
					printf("\n cannot close Database");
					delay(3000);
					exit(1);
				}
				return 1;
				//�л�����
			}
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (i == len)
	{
		puthz(450, 170, "�˻�δע��", 16, 17, RED);
		delay(1000);
		cover_tips(450,170,GREEN);
		//�ߵ����һλ
	}

	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database");
		delay(3000);
		exit(1);
	}
	return 0;
}
/*************************************************************
��������login_complete(char* u, char* p)
�����������û����������ַ*u,��������������ַ*p
����ֵ��1:�� 2����
�������ܣ������жϵ�¼��Ϣ�Ƿ�������ȫ����ȷ
**************************************************************/	
int login_complete(char* u, char* p)
{
	int state1 = 1;//�Ƿ�����ı���
	int state2 = 1;
	while (1)
	{
		
		panduan(u, &state1, 450, 170,BLACK);
		
		panduan(p, &state2, 450, 290,BLACK);
		delay(1000);
		cover_tips(450,170,GREEN);
		cover_tips(450,290,GREEN);
		if (state1 == 1 || state2 == 1)
		{
			break;
		}
		else if (state1 == 0 && state2 == 0)
		{
			if (login(u, p))
			{

				return 1;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}


