#include"common.h"
#include"register.h"
#include"USER.h"
#include "func.h"
#include "file.h"
/*************************************************************
��������zhuce_func(int *func)
���������������ַ*func
����ֵ����
�������ܣ�ע����湦��ѡ��
**************************************************************/	
void zhuce_func(int *func)
{		

    int light=0; 
	//�����û���
	char name [15] = {'\0'};
	
	//��������
	char password1 [15] = {'\0'};
	
	//�ٴ���������
	char pass [15] = {'\0'};
		
	//����绰����
	char tel [15] = {'\0'};

	
	//�ж�
	int jud1=0;
	int jud2=0;
	int jud3=0;
	int jud4=0;

	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
    draw_zhuce();
	while(1)
	{	
		
		
		newmouse(&MouseX, &MouseY, &press);
		
		//�����û���
			
		if(MouseX>260 && MouseX<540 &&MouseY>140 && MouseY<160)
		{	
		 	if (mouse_press(260, 140, 260 + 280, 160) == 2)           
		 	//δ����˺ſ�
			{
				MouseS = 2;
				if (light == 0 && jud1 == 0)                  
				//light = 0��ֹ�ظ�����
				{
					lightbutton_register(260, 140, 260 + 280, 160, RED, LIGHTGRAY, 1);
					light = 1;
				}
				continue;
			}
			else if(mouse_press(260, 140, 260 + 280, 160)==1)
			{
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260, 140, 260 + 280, 160, RED, LIGHTGRAY, 1);
				name[0]='\0';
				inputadmin(name, 260, 140, 12, LIGHTGRAY);
				if(strlen(name)!=0)
					jud1=1;
				else
					jud1=0;
				continue;
			}		
		}
		//��������
		if(MouseX>260 && MouseX<540 &&MouseY>180 && MouseY<200)
		{	
		 	if (mouse_press(260,180,540,200) == 2)           
		 	//δ��������
			{
				MouseS = 2;
				if (light == 0 && jud2 == 0)                  
				//light = 0��ֹ�ظ�����
				{
					lightbutton_register(260,180,540,200, RED, LIGHTGRAY, 1);
					light = 2;
				}
				continue;
			}
			else if(mouse_press(260,180,540,200)==1)	
			{
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260,180,540,200, RED, LIGHTGRAY, 1);
				password1[0]='\0';
				inputpassword(password1, 260, 180, 12, LIGHTGRAY);
				if(strlen(password1)!=0)
					jud2=1;
				else
					jud2=0;
				continue;
			}
		}
		//�ٴ���������
		if(MouseX>260 && MouseX<540 &&MouseY>220 && MouseY<240)
		{	
		 	if (mouse_press(260, 220, 260 + 280, 240) == 2)          
		 	 //δ��������
			{
				MouseS = 2;
				if (light == 0 && jud3 == 0)                  
				//light = 0��ֹ�ظ�����
				{
					lightbutton_register(260,220,540,240, RED, LIGHTGRAY, 1);
					light = 3;
				}
				continue;
			}
			else if(mouse_press(260,220,540,240)==1)			
			{
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260,220,540,240, RED, LIGHTGRAY, 1);
				pass[0]='\0';
				inputpassword(pass, 260, 220, 12, LIGHTGRAY);
				if(strlen(pass)!=0)
					jud3=1;
				else
					jud3=0;
				continue;
			}	
		}
		//����绰����
		if(MouseX>260 && MouseX<540 &&MouseY>260 && MouseY<280)
		{	
		 	if (mouse_press(260,260,540,280) == 2)           
		 	//δ����绰�����
			{
				MouseS = 2;
				if (light == 0 && jud4 == 0)                  
				//light = 0��ֹ�ظ�����
				{
					lightbutton_register(260,260,540,280, RED, LIGHTGRAY, 1);
					light = 4;
				}
				continue;
			}
			else if(mouse_press(260,260,540,280)==1)	
			{
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260,260,540,280, RED, LIGHTGRAY, 1);
				tel[0]='\0';
				inputadmin(tel, 260, 260, 18, LIGHTGRAY);
				if(strlen(tel)!=0)
					jud4=1;
				else
					jud4=0;
				continue;
			}	
		}
		
	
		if(MouseX>140 && MouseX<330&&MouseY>340 && MouseY<380)
		{
			if(mouse_press(140, 340, 330, 380) == 1)
			//ȷ����ť
			{
				MouseS=0;
				if(check(name,tel,password1,pass))
				{
					createfolder(name);
					clrmous(MouseX,MouseY);
					cleardevice();
					*func=0;
					return;

				}
				else 
				continue;
			}
		}


		if (MouseX > 140 && MouseX < 540 && MouseY>295 && MouseY < 330)
		{
			if (mouse_press(140, 295, 260 + 280,330) == 1)
			{
				MouseS = 0;
				clrmous(MouseX,MouseY);
				cleardevice();
				*func=1;
				return;
			}	
		}

		//����
		if(mouse_press(350, 340, 540, 380) == 1)
		{
			clrmous(MouseX,MouseY);
			cleardevice();
			*func=0;
			return;
		}

		if (light != 0)
		{
			MouseS = 0;
			if (jud1 == 0)
			{
				recoverbutton_register(1);
			}
			if (jud2 == 0)
			{
				recoverbutton_register(2);
			}
			if (jud3 == 0)
			{
				recoverbutton_register(3);
			}
			if (jud4 == 0)
			{
				recoverbutton_register(4);
			}		
			light = 0;
		}

		if (MouseS != 0)
		{
			MouseS = 0;
		}		
	}
}
/*************************************************************
��������draw_zhuce()
��������
����ֵ����
�������ܣ�����ע�����
**************************************************************/	
void draw_zhuce()
//����ע�����
{
	setbkcolor(CYAN);

	//����½С��
	sector(320, 30, 230, 310, 35, 35);
	fillellipse(320, 25, 15, 15);
	setcolor(RED);
	circle(320, 25, 15);	
	puthz(220, 80, "˼ά��ͼ", 48, 55, YELLOW);
	
	//�û���
	setfillstyle(SOLID_FILL, WHITE);
	bar(140, 140, 260, 160);
	bar(260, 140, 260 + 280, 160);
	
	//����	
    bar(140, 180, 260,200);
	bar(260, 180, 260 + 280, 200);	
	
	//ȷ������
	bar(140, 220, 260,240);
	bar(260, 220, 260 + 280, 240);
	
    //�绰����
	bar(140, 260, 260,280);
	bar(260, 260, 260 + 280, 280);
	
	
	//ȷ��,���غ�����
	setfillstyle(SOLID_FILL,RED);
	bar(140, 340, 330, 380);
	bar(350, 340, 540, 380);
	bar(140, 295, 260 + 280,330);
	//�߿�
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, 3);
	line(260, 140, 260, 160);
	line(260, 180, 260, 200);	
	rectangle(140, 140, 260 + 280, 160);
	rectangle(140, 180, 260 + 280, 200);
	line(260, 220, 260, 240);	
	rectangle(140, 220, 260 + 280,240);
	line(260, 260, 260, 280);	
	rectangle(140, 260, 260 + 280,280);	
		
	rectangle(140, 295, 260 + 280,330);	
		
	

	puthz(148, 183, "����", 16, 80, LIGHTRED);
	puthz(148, 143, "�û���", 16, 34, LIGHTRED);
	puthz(148, 223, "ȷ������", 16, 30, LIGHTRED);
	puthz(148, 263, "�绰����", 16, 30, LIGHTRED);
	puthz(200,298,"�������",32,80,YELLOW);
	
	puthz(180, 343, "ȷ��", 32, 88, YELLOW);
	puthz(380, 343, "����", 32, 88, YELLOW);
	
}

/*************************************************************
��������check(char *name,char *tel,char *password1,char * password2)
�����������û����������ַ*name,����绰����������ַ*tel,��������������ַ*password1,����ȷ������������ַ*password2
����ֵ��1:�� 0:��
�������ܣ��ж�ע���˺�ʱ������Ϣ�Ƿ���ϸ�ʽ
**************************************************************/	
int check(char *name,char *tel,char *password1,char * password2)
{
	int q=0;
	
	int std1=1;
	//�ж��û����Ƿ�������ȷ�ĸ�ʽ
	int std2=1;
	//�ж������Ƿ�������ȷ�ĸ�ʽ
	int std3=1;
	//�ж������Ƿ�һ��
	int std4=1;
	//�жϵ绰�����Ƿ�������ȷ�ĸ�ʽ
	

	while(1)
	{
		cover(545,140,CYAN);
		cover(545,180,CYAN);
		cover(545,220,CYAN);
		cover(545,260,CYAN);
		panduan(name,&q,545,140,CYAN);
		panduan(password1,&q,545,180,CYAN);
		panduan(password2,&q,545,220,CYAN);
		panduan(tel,&q,545,260,CYAN);
		
		if(q==1)
		{
			break;
		}
		else if(q==0)
		{
			if(!Search_S_user(name,1))
			//�ж��Ƿ�����,��������0�����򷵻� 1
			{
				std1=judge_name(name,545,140);
				std2=judge_password(password1,545,180);
				std3=judge_ispasswordsame(password1,password2,545,220);
				std4=judge_tel(tel,545,260,1);
				break;


			}

			else if(Search_S_user(name,1))
			//û������
			{
				puthz(530,100, "���õ��û���", 16, 17, RED);
				std1=judge_name(name,545,140);
				std2=judge_password(password1,545,180);
				std3=judge_ispasswordsame(password2,password1,545,220);
				std4=judge_tel(tel,545,260,1);
				if (std1 != 0 || std2 != 0 || std3 != 0 || std4 != 0 )
				{
					break;
				}
				else if (std1 == 0 && std2 == 0 && std3 == 0 && std4 == 0 )
				{
					inputtofile(name,tel,password1);
					//д�����ݿ�
					puthz(280,420, "ע��ɹ�", 16, 17, RED);
					delay(2000);				
					return 1;
					//����
				}

			}

		}
    }
	return 0;
}