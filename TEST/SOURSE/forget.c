#include"common.h"
#include"forget.h"
#include"USER.h"

/*************************************************************
��������forget_func(int *func)
��������������ĵ�ַ*func
����ֵ����
�������ܣ��һ������������й��ܵĵ���
**************************************************************/	
void forget_func(int *func)
{	
	int light = 0;
	//�����û���
	char name [15] = {'\0'};
		
	//�����ֻ�����
	char tel [15] = {'\0'};
	
	//����������
	char password [15] = {'\0'};
	int jud1=0;
	int jud2=0;
	int jud3=0;


	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	draw_forget();
	
	while(1)
	{	
		newmouse(&MouseX, &MouseY, &press);
		
		//�����û���			
		if(MouseX>260 && MouseX<540 &&MouseY>180 && MouseY<200)
		{	
		 	if (mouse_press(260, 180, 260 + 280, 200) == 2)           
		 	//δ����˺ſ�
			{
				MouseS = 2;
				if (light == 0 && jud1 == 0)                  
				//light = 0��ֹ�ظ�����
				{
					lightbutton_register(260, 180, 260 + 280, 200, RED, LIGHTGRAY, 1);
					light = 1;
				}
				continue;
			}
			else if(mouse_press(260, 180, 260 + 280, 200)==1)
			{
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260, 180, 260 + 280, 200, RED, LIGHTGRAY, 1);
				name[0]='\0';
				inputadmin(name, 260, 180, 12, LIGHTGRAY);
				if(strlen(name)!=0)
					jud1=1;
				else
					jud1=0;
				continue;
			}	
		}

		//����绰����
		if(MouseX>260 && MouseX<540 &&MouseY>220 && MouseY<240)
		{	
		 if (mouse_press(260,220,540,240) == 2)           
		 //δ����绰�����
			{
				MouseS = 2;
				if (light == 0 && jud2 == 0)                  
				//light = 0��ֹ�ظ�����
				{
					lightbutton_register(260,220,540,240, RED, LIGHTGRAY, 1);
					light = 4;
				}
				continue;
			}
			else if(mouse_press(260,220,540,240)==1)
			{
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260,220,540,240, RED, LIGHTGRAY, 1);
				tel[0]='\0';
				inputadmin(tel, 260, 220, 12, LIGHTGRAY);
				if(strlen(tel)!=0)
					jud2=1;
				else
					jud2=0;
				continue;
			}	
		}
		
		//����������		
		if(MouseX>260 && MouseX<540 &&MouseY>260 && MouseY<280)
		{	
		 if (mouse_press(260, 260, 540, 280) == 2)           
		 //δ��������
			{
				MouseS = 2;
				if (light == 0 && jud3 == 0)                  
				//light = 0��ֹ�ظ�����
				{
					lightbutton_register(260,260,540,280, RED, LIGHTGRAY, 1);
					light = 2;
				}
				continue;
			}
			else if(mouse_press(260,260,540,280)==1)	
			{
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260,260,540,280, RED, LIGHTGRAY, 1);
				password[0]='\0';
				inputpassword(password, 260, 260, 12, LIGHTGRAY);
				if(strlen(password)!=0)
					jud3=1;
				else
					jud3=0;
				continue;
			}			
		}
		
		if (light != 0)
		{
			MouseS = 0;
			if (jud1 == 0)
			{	setfillstyle(1, WHITE);
				bar(260, 180, 540,200);
				rectangle(260, 180, 540,200);
			}
			if (jud2 == 0)
			{
				setfillstyle(1, WHITE);
				bar(260, 220, 540,240);
				rectangle(260, 220, 540,240);
			}
			if (jud3 == 0)
			{
				setfillstyle(1, WHITE);
				bar(260, 260, 540, 280);
				rectangle(260, 260, 540, 280);
			}			
			light = 0;
		}

		if (MouseS != 0)
		{
			MouseS = 0;
		}
		
		//ȷ��
		if(MouseX>140 && MouseX<300&&MouseY>290 && MouseY<330)
		{
			if(mouse_press(140, 290, 300, 330) == 1)
				//ȷ����ť
			{
				if(forgetpass_match(name,tel,password))
				{
					MouseS=0;
					clrmous(MouseX,MouseY);
					cleardevice();
					*func=0;
					return ;

				}
				else
				{
					*func=2;
				}
			}
		}
			
		//����
		if(MouseX>380 && MouseX<540 && MouseY>290 && MouseY<330)
		{	
			if(mouse_press(380, 290, 540, 330) == 1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				cleardevice();
				*func=0;
				return;
			}
		}
	}

}
/*************************************************************
��������draw_forget()
��������
����ֵ����
�������ܣ������һ��������
**************************************************************/	
void draw_forget()
{
    //���ñ���ɫ
	setbkcolor(CYAN);
	
	//�����ı�����ɫ
	setfillstyle(SOLID_FILL,RED);
	setfillstyle(SOLID_FILL, WHITE);
	
	//�û���
	bar(140, 180, 260,200);
	bar(260, 180, 260 + 280, 200);
	
	//�绰����
	bar(140, 220, 260,240);
	bar(260, 220, 260 + 280, 240);
	
	//������
	bar(140, 260, 260, 280);
	bar(260, 260, 260 + 280, 280);
	
	//���ð�ť��ɫ
	setfillstyle(SOLID_FILL,RED);
	
	//ȷ��
	bar(140, 290, 300, 330);
	
	//����
	bar(380, 290, 540, 330);


	//����½С��
	setcolor(CYAN);
	sector(320, 80, 230, 310, 35, 35);
	fillellipse(320, 75, 15, 15);
	setcolor(GREEN);
	circle(320, 75, 15);	
	puthz(220, 115, "˼ά��ͼ", 48, 55, YELLOW);
	
	//���ñ߿���ɫ������
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, 3);
	
	//�߿�
	line(260, 180, 260, 200);	
	rectangle(140, 180, 260 + 280, 200);
	line(260, 220, 260, 240);	
	rectangle(140, 220, 260 + 280, 240);
	line(260, 260, 260, 280);
	rectangle(140, 260, 260 + 280, 280);
	
	//����
	puthz(160, 293, "ȷ��", 24, 88, YELLOW);
	puthz(400, 298, "����", 24, 88, YELLOW);
	puthz(148, 183, "�û���", 16, 34, LIGHTRED);
	puthz(148, 223, "�绰����", 16, 30, LIGHTRED);
	puthz(148, 263, "������", 16, 34, LIGHTRED);
}

/*************************************************************
��������name_id(char* name, char* tel, char* password)
�������˺�����ĵ�ַ*name,�绰��������ĵ�ַ*tel,��������ĵ�ַ*password
����ֵ��1:ƥ�� 0:��ƥ��
�������ܣ��ж��˺������֤�Ƿ�ƥ�� �ж���������������Ƿ���ͬ ��ƥ������ͬ��д��������
**************************************************************/	
int name_id(char* name, char* tel, char* password)
{
	int str;
	int len;
	int i,j;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen(".\\USERS\\userdata.dat", "rb+" )) == NULL)
	{
		printf("cannot open file UserDat.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//�ļ�ָ�붨λ�����һλ
	len = ftell(fp) / sizeof(USER);//�����û�����
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);//ÿ��������һ���û�
		fread(u, sizeof(USER), 1, fp);//����Ϣ����u
		if (strcmp(name, u->user) == 0)
		{

			if (strcmp(tel, u->tel) == 0)
			{
				setcolor(RED);
				setlinestyle(SOLID_LINE, 0, 3);
				line(550, 228, 560, 238);
				line(560, 238, 570, 218);
				u->password[0] = '\0';
					strcpy(u->password, password);
					fseek(fp, i * sizeof(USER), SEEK_SET);
					fwrite(u, sizeof(USER), 1, fp);
					//�޸����һ��Ҫ�ǵ�д������
					puthz(300, 480 - 10 - 60, "�����޸ĳɹ�", 16, 17, RED);
					if (u != NULL)
					{
						free(u);
						u = NULL;
					}
					if (fclose(fp) != 0)
					{
						printf("\n cannot close Database");
						exit(1);
					}
					delay(2000);
					return 1;
				}
		}
	}
	if(i>=len)
	{
		puthz(50,50,"�����޸�ʧ��",24,30,RED);
		delay(1500);
		
		setfillstyle(SOLID_FILL,CYAN);
		bar(50, 50, 230, 50 + 25);

	}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database");
		exit(1);
	}
	return 0;
}

/*************************************************************
��������forgetpass_match(char* u, char* tel, char* password)
�������û�����ַ*u,�绰��������ĵ�ַ*tel,��������ĵ�ַ*password
����ֵ��1:���� 0:������
�������ܣ��ж��Ƿ���Ը���������
**************************************************************/	
int forgetpass_match(char* u, char* tel, char* password)
{
	int st1 = 1;//�û����Ƿ�����ı���
	int st2 = 1;//�Ƿ�����ı���
	int st3 = 1;//�������Ƿ�����ı���

	int state1 = 1;//�����ʽ�Ƿ���ȷ�ı���
	int state2 = 1;//���������ʽ�Ƿ���ȷ�ı���
	
	while (1)
	{
		cover(95 + 452, 138, CYAN);//�ڸǺ���
		cover(95 + 452, 218,  CYAN);
		cover(95 + 452, 298,  CYAN);
		panduan(u, &st1, 95 + 452, 183,CYAN); //�ж��Ƿ�����,δ�����=1
		panduan(tel, &st2, 95 + 452, 220,CYAN);
		panduan(password, &st3, 95 + 452, 263,CYAN);
		
	
		if (st1 == 1 || st2 == 1 || st3 == 1 )
		{
			break;
		}
		else if (st1 == 0 && st2 == 0 && st3 == 0 )
		{
			if (Search_S_user(u,2))//�û���������
			{
				puthz(95 + 450, 140, "�û�������", 16, 17, RED);
				delay(1500);
				cover_tips(95 + 450, 140,CYAN);
				state1 = judge_name(u, 95 + 452, 220 );//�жϸ����ʽ�Ƿ���ȷ

				state2 = judge_password(password, 95 + 452, 300);
				delay(1500);
				cover_tips(95 + 452, 220,CYAN);
				cover_tips(95 + 452, 300,CYAN);
				
				break;
			}
			else if (!Search_S_user(u,2))//�û�������
			{
				state1 = judge_name(u, 95 + 452, 180);
				state2 = judge_tel(tel, 95 + 452, 220,1);
				delay(1000);
				cover_tips(95 + 452, 220,CYAN);
				cover_tips(95 + 452, 300,CYAN);
				
				if (state1 != 0 || state2 != 0 )
				{
					break;
				}	
				else if (state1 == 0 && state2 == 0 )
				{
					if (name_id(u,tel,password))//д�����ݿ�
					{
						return 1;//���ص�¼����
					}
					else
					{
						break;
					}
				}
			}
		}
	}
	return 0;
}


