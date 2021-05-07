#include"common.h"
#include"func.h"
#include"USER.h"
/*************************************************************
��������inputadmin(char* id, int x1, int y1, int charnum, int color)
�������洢�����˺ŵ������ַ*id,��������Ͻǵ�����xy,����ַ���charnum,��������ɫcolor 
����ֵ����
�������ܣ������˺ſ���
**************************************************************/	
void inputadmin(char* id, int x1, int y1, int charnum, int color)
{
	int k = 0;
	int i = 0;
	char t;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(RED);
	settextstyle(SMALL_FONT, HORIZ_DIR, 4);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 16);
	//���
	while(bioskey(1))
	{
		k = bioskey(0);
		//����
	}
	while (1)
	{
	
		t = bioskey(0); 
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)
				//Esc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 16); 
					//�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1+5, id + i);
					//���t�ַ�(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 16);
				}
				else if (t == '\b' && i > 0)
				//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 16);
					//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 16);
					//�ڸ�����
					i--;//����һ���ַ�?
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 16);
					//���ƹ��
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 16);
				//�ڸǹ��
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)
				//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 16);
					//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 16);
					//�ڸ�����
					i--;
					//����һ���ַ�
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 16);
					//���ƹ��
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 16);//�ڸǹ��  
				break;
			}
		}
	}
}

/*************************************************************
��������inputpassword(char* id, int x1, int y1, int charnum, int color)
�������洢��������������ַ*id,��������Ͻǵ�����xy,����ַ���charnum,��������ɫcolor 
����ֵ����
�������ܣ������������
**************************************************************/
void inputpassword(char* id, int x1, int y1, int charnum, int color)
{
	int k = 0;
	int i = 0;
	char t;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 4, x1 + 10, y1 + 15);
	while(bioskey(1))
	{
		k = bioskey(0);
		//��
	}
	while (1)
	{
		t = bioskey(0);
		//��ȡ��ֵ
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)
				//033��ʾEsc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 17);
					//�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1 + 3, "*");
					//���*�ַ�
					i++;
					line(x1 + 10 + i * 18, y1 + 4, x1 + 10 + i * 18, y1 + 17);
				}
				else if (t == '\b' && i > 0)
				//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 17);
					//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 17);
					//�ڸ�����
					i--;
					//����һ������
					line(x1 + 10 + i * 18, y1 + 4, x1 + 10 + i * 18, y1 + 17);
					//���ƹ��
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 17);
				//�ڸǹ��
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)
				//Esc
			{
				if (t == '\b' && i > 0)
				//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 17);
					//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 17);
					//�ڸ�����
					i--;
					//����һ������
					line(x1 + 10 + i * 18, y1 + 2, x1 + 10 + i * 18, y1 + 14);
					//���ƹ��
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 17);
				//�ڸǹ��
				break;
			}
		}
	}
}

/*************************************************************
��������panduan(char* s, int* jud, int x, int y,int color)
�������洢����������ַ*s,�ж��Ƿ�����ı�־��ַ*jud,��������Ͻǵ�����xy,��������ɫcolor 
����ֵ����
�������ܣ��ж��Ƿ�����
**************************************************************/
void panduan(char* s, int* jud, int x, int y,int color)
{
	if (strlen(s) == 0)
	{
		*jud = 1;
		puthz(x, y, "δ����", 16, 17, RED);
		delay(1000);
		cover_tips(x,y,color);
	}
	else
	{
		*jud= 0;
	}


}
/*************************************************************
��������Search_S_user(char * new,int z)
�������洢�����˺ŵ������ַ*new,��ʾ �Ƿ�ע�� ������ʾ �Ƿ���� �ı�־z
����ֵ��1:�� 0:��
�������ܣ��ж��Ƿ��ظ�
**************************************************************/
int Search_S_user(char * new,int z)
{
	int i;
	int len;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen(".\\USERS\\userdata.dat", "rb+")) == NULL)
	//�������ݿ�
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
		if (strcmp(u->user, new) == 0)
		{
			switch (z)
			{
			case 1: 
				puthz(135, 60, "�û��ѱ�ע��", 16, 17, RED);
				break;
			case 2:
				puthz(450, 110, "�˺Ŵ���", 16, 17, RED);
				break;
			default:
				printf("something wrong");
				delay(3000);
				exit(1);
			}
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n cannot close Database.");
				delay(3000);
				exit(1);
			}
			return 0;
		}
		free(u);
		u = NULL;
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	return 1;


}
/*************************************************************
��������judge_name(char* s, int x, int y)
�������洢�����˺ŵ������ַ*s,��ʾ ����Ӧ ������xy
����ֵ��1:�� 0:��
�������ܣ��ж��û����Ƿ����6λ��С��12λ
**************************************************************/
int judge_name(char* s, int x, int y)
{
	if (strlen(s) < 6 
	/*С��6λ*/)
	{
		puthz(x, y, "����Ӧ", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x + 53, y - 5, ">6");
		return 1;
	}
	else if(strlen(s)>=6&&strlen(s)<=12)
	{
		setcolor(RED);
		setlinestyle(SOLID_LINE, 0, 3);		
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;

}

/*************************************************************
��������judge_password(char* s, int x, int y)
�������洢��������������ַ*s,��ʾ ����Ӧ ������xy
����ֵ��1:�� 0:��
�������ܣ��ж������Ƿ����6λС��12λ
**************************************************************/
int judge_password(char* s, int x, int y)
{

	if (strlen(s) < 6
	/*С��6λ*/)
	{
		puthz(x, y, "����Ӧ", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x + 53, y - 5, ">=6");
		return 1;
	}
	else if(strlen(s)>=6&&strlen(s)<=12)
	{
		setcolor(RED);
		setlinestyle(SOLID_LINE, 0, 3);		
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

/*************************************************************
��������judge_ispasswordsame(char* s1, char* s2, int x, int y)
�������洢��������������ַ*s1*s2,��ʾ ���β�һ�� ������xy
����ֵ��1:�� 0:��
�������ܣ��ж������Ƿ����6λС��12λ
**************************************************************/
int judge_ispasswordsame(char* s1, char* s2, int x, int y)
{
	if (strcmp(s1, s2) != 0)
	{
		puthz(x, y, "���β�һ��", 16, 17, RED);
		return 1;
	}
	else if (strcmp(s1, s2) == 0)
	{
		setcolor(RED);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 0;
}

/*************************************************************
�������� judge_tel(char* s, int x, int y,int z)
�������洢����绰����������ַ*s1,��ʾ ӦΪ �� ��ʽ����ȷ ������xy,�Ƿ��ӡ�Ժŵı�־z
����ֵ��1:�� 0:��
�������ܣ��жϵ绰�����Ƿ���ϸ�ʽ
**************************************************************/
int judge_tel(char* s, int x, int y,int z)
{
	int i=0;
	int state = 1;
	if (strlen(s) != 11)
	{
		puthz(x, y, "ӦΪ", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x+50, y-5, "11");
		puthz(x + 73, y, "λ", 16, 17, RED);
		//���Ȳ�����
		return 1;
	}
	else if (strlen(s) == 11)
	{
		for (i = 0; i < 10; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				continue;
			}
			else
			{
				puthz(x, y, "��ʽ����ȷ", 16, 17, RED);
				return 0;
			}
			
		}
		if (s[10] == 'X' || (s[10]>='0' && s[10]<='9'))
		{
			state = 0;
			//�ж����һλ�Ƿ�Ϊ���ֺ�X
		}
		else
		{
			puthz(x, y, "��ʽ����ȷ", 16, 17, RED);
			return 1;
		}
	}
	if (state == 0)
	{
		switch (z)
		{
		case 1:
			setcolor(RED);
			setlinestyle(SOLID_LINE, 0, 3);
			line(x + 3, y + 8, x + 13, y + 18);
			line(x + 13, y + 18, x + 23, y - 2);
			break;
		case 2:
			break;
		}
		return 0;
	}
	return 1;
}

