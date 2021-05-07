#include"save.h"
#include"common.h"
#include "file.h"
#include "popup.h"
#include "USER.h"
#include "history.h"
#include "LIGANDCO.h"
#include "compare.h"
/*************************************************************
��������void DrawSave()
���������
����ֵ����
�������ܣ����Ʊ������
**************************************************************/
void DrawSave()
{
	int x=250,y=190;
	//����ͼ��
	setbkcolor(WHITE);
    clrmous(MouseX,MouseY);
	setcolor(GREEN);
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


	
	puthz(160, 10, "��������ͷ�Է籩", 32, 42, YELLOW);
	setfillstyle(1, GREEN);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(LIGHTGRAY);
	bar(190, 435, 190+80, 435+25);
	rectangle(190, 435, 190+80, 435+25);
	puthz(209,440,"ȷ��",16,28,WHITE);
	
	bar(370, 435, 370+80, 435+25);
	rectangle(370, 435, 370+80, 435+25);
	puthz(389, 440, "ȡ��", 16, 28, WHITE);
	
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);	
	setcolor(GREEN);
	setfillstyle(1, WHITE);
	puthz(100, 335+3, "������Ҫ������ļ���", 24, 25, BLUE);
	puthz(100, 370+3, "������Ҫ�ղص��ļ���", 24, 25, BLUE);
	bar(360, 335, 555, 335+30);
	rectangle(360, 335, 555, 335+30);
	bar(360, 375, 555, 375+30);
	rectangle(360, 375, 555, 375+30);
	
	puthz(566, 335+6, "С����λ", 16, 16, BLUE); 
	puthz(566, 375+6, "С����λ", 16, 16, BLUE); 


}

/*************************************************************
��������void SaveFunc(int *func,USER *u,struct mpdata *mp,int statue)
������������ת����,�û��ṹ��ָ��,˼ά��ͼ�ṹ��ָ��,��ʽ�жϲ���
����ֵ����
�������ܣ�����������
**************************************************************/

void SaveFunc(int *func,USER *u,struct mpdata *mp,int statue)
{
	File allfile[FILEMAX];
	File cfile[FILEMAX];
	char filename[20];
	int fun = 0;
	int l=0;
	int state=0;
	int j;
	int i;
	int o=0;
	//��ʼ�������ļ����ϴ��ļ�
	for(i=0;i<FILEMAX;i++)
		{
			memset(&allfile[i],'\0',sizeof(File));
		}
	for(i=0;i<FILEMAX;i++)
		{
			memset(&cfile[i],'\0',sizeof(File));
		}
	DrawSave();


	if(u->history != 0)
	{
		Output_Filemenu(allfile, u->user);
	}
	//�����ѱ����ļ�
	
	if(u->num!=0)
	{
		Output_CFilemenu(cfile, u->user);
	}
	//�����Ѿ��ϴ����ļ�
	

	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);

		//ȷ�ϰ�ť
		if(MouseX > 190 && MouseY>435 && MouseX < 190+80 && MouseY <435+25 )

		{
			if ( mouse_press(190, 435, 190+80, 435+25) == 2)
			//δ���
			{
				MouseS = 1;
				continue;
			}

			if( mouse_press(190, 435, 190+80, 435+25) == 1)
			//���
			{
				clrmous(MouseX, MouseY);
				fun = Examine_Filename(u, allfile, filename);
				if(fun == 1 || fun ==3)
				{
					if(state==1)
					{
						u->history ++;
						Insert_filemenu(allfile, filename, u->format, u->history);
						Input_data(u->user,mp);
						Input_history(u->user,u->history);
						Input_format(u->user, u->format);
						Input_filemenu(allfile, u->user);
						Input_filedata(u->user,mp,filename);
						puthz(260,412,"����ɹ�",24,30,BLUE);
						delay(1500);
						cover_save(260, 412,WHITE);
						state = 0;
						clrmous(MouseX,MouseY);
						cleardevice();
						*func = 4;
						return;
					}
				}
				if(fun == 2 && state ==1)
				//����
				{
					puthz(260,412,"�ļ�����",24,30,BLUE);
					delay(1500);
					cover_save(260, 412,WHITE);
					state = 0;
					clrmous(MouseX,MouseY);
					cleardevice();
					*func = 4;
					return;
				}
				//�ϴ��ļ�������
				if(fun != 2 && state==2)
				{
					puthz(260,412,"�޴��ļ�",24,30,BLUE);
					delay(1500);
					cover_save(260, 412,WHITE);
					state = 0;
					clrmous(MouseX,MouseY);
					cleardevice();
					*func = 4;
					return;
				}
				//�״��ϴ�
				if(fun == 2 && state ==2 && u->num == 0)
				//�ϴ�
				{
					u->num++;
					Insert_filemenu(cfile, filename, j, u->num);
					Input_num(u->user,u->num);
					Input_Cfilemenu(cfile, u->user);																
					state = 0;
					puthz(260,412,"�ϴ��ɹ�",24,30,BLUE);
					delay(1500);
					cover_save(260, 412,WHITE);
					clrmous(MouseX,MouseY);
					cleardevice();
					*func = 4;
					return;
				}

				//���״��ϴ�
				if(fun == 2 && state ==2 && u->num != 0)
				//�ϴ�
				{
					for(o=0;o<u->num;o++)
					{
						if(strcmp(filename,cfile[o].name)==0)
						//�ж��Ƿ��Ѿ��ϴ���
						{
							l=1;
							break;
						}
						else
						{
							continue;
						}
					}
				
					if(l !=1 )
					{					
						u->num++;
						Insert_filemenu(cfile, filename, j, u->num);
						Input_num(u->user,u->num);
						Input_Cfilemenu(cfile, u->user);																
						state = 0;
						puthz(260,412,"�ϴ��ɹ�",24,30,BLUE);
						delay(1500);
						cover_save(260, 412,WHITE);		
						clrmous(MouseX,MouseY);
						cleardevice();	
						*func = 4;
						return;
					}

					if(l == 1)
					{
						puthz(260,412,"�Ѿ��ϴ�",24,30,BLUE);	
						delay(1500);
						cover_save(260, 412,WHITE);
						clrmous(MouseX,MouseY);
						cleardevice();
						*func = 4;
						return;
					}
				}

			}
		}

		if(MouseX > 370 && MouseY>435 && MouseX < 450 && MouseY <435+25 )

		{
			if ( mouse_press(370, 435, 370+80, 435+25) == 2)
			//δ���
			{
				MouseS = 1;
				continue;
			}

			if( mouse_press(370, 435, 370+80, 435+25) == 1)
			//���
			{
				if(statue == 1)
				{
					clrmous(MouseX, MouseY);
					cleardevice();
					*func = 8;
					return;

				}

				if(statue == 2)
				{
					clrmous(MouseX, MouseY);
					cleardevice();
					*func = 9;
					return;

				}
			}
		}

		if(mouse_press(360, 335, 555, 335+30)==1)
		{
			clrmous(MouseX, MouseY);
			cover_save(480, 310,WHITE);
			Light_Compare(360, 335, 555, 335+30,BLUE,WHITE);
			filename[0]='\0';
			EnterFileName(filename,360,335,7,WHITE);
			state=1;
			continue;
		}

		if(mouse_press(360, 375, 555, 375+30)==1)
		{
			clrmous(MouseX, MouseY);
			cover_save(480, 310,WHITE);
			Light_Compare(360, 375, 555, 375+30,BLUE,WHITE);
			filename[0]='\0';
			EnterFileName(filename,360,375,7,WHITE);
			j=getfileformat(u->user,filename);
			state=2;
			continue;
			
		}

        if(MouseS != 0)
        {
            MouseS = 0;
            continue;
        }



    }
}


/*************************************************************
��������void Input_history(char *u, int n)  
�������û���,����
����ֵ����
�������ܣ�������ʷ
**************************************************************/
void Input_history(char *u, int n)    
{
	int i;
	int num;
	FILE *fp;
	USER *p = NULL;
	if((fp = fopen(".\\USERS\\userdata.dat", "rb+")) == NULL)
	 //���û����ݿ�
	{
		printf("File UserData.dat cannot be open");
		delay(2000);
		//exit(1);
	}
	fseek(fp, 0, SEEK_END);
	num = ftell(fp) / sizeof(USER);
	
	if((p = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("not enough memory for userfunc.c6");
			delay(2000);
			//exit(1);
		}
	
	for(i = 0; i < num; i++)
	{
		
		fseek(fp, i*sizeof(USER), SEEK_SET);
		fread(p, sizeof(USER), 1, fp);
		fseek(fp, i*sizeof(USER), SEEK_SET);   
		 //���¶�λ�����fwrite�޷�д�������
		if(strcmp(p->user, u) == 0)
		{
			p->history = n;
			fwrite(p, sizeof(USER), 1, fp);
		
			if(p != NULL)
			{
				free(p);
				p = NULL;
			}
			if(fclose(fp) != 0)
			{
				printf("\n cannot close UserData.dat");
				delay(2000);
				//exit(1);
			}
			return;
		}
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	if(fclose(fp) != 0)
	{
		printf("\n cannot close UserData.dat");
		delay(2000);
		exit(1);
	}
	//printf("wrong");
	//exit(1);
}

/*************************************************************
��������void Input_format(char *u, int n)  
�������û���,����
����ֵ����
�������ܣ����°�ʽ
**************************************************************/
void Input_format(char *u, int n) 
{
	int i;
	int num;
	FILE *fp;
	USER *p = NULL;
	if((fp = fopen(".\\USERS\\userdata.dat","rb+")) == NULL) 
	//���û����ݿ�
	{
		printf("File UserData.dat cannot be open");
		delay(2000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	num = ftell(fp) / sizeof(USER);
	
	if((p = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("not enough memory for userfunc.c7");
			delay(2000);
			exit(1);
		}
	
	for(i = 0; i < num; i++)
	{
		
		fseek(fp, i*sizeof(USER), SEEK_SET);
		fread(p, sizeof(USER), 1, fp);
		fseek(fp, i*sizeof(USER), SEEK_SET);    
		//���¶�λ�����fwrite�޷�д�������
		if(strcmp(p->user, u) == 0)
		{
			p->format = n;
			fwrite(p, sizeof(USER), 1, fp);
		
			if(p != NULL)
			{
				free(p);
				p = NULL;
			}
			if(fclose(fp) != 0)
			{
				printf("\n cannot close UserData.dat");
				delay(2000);
				exit(1);
			}
			return;
		}
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	if(fclose(fp) != 0)
	{
		printf("\n cannot close UserData.dat");
		delay(2000);
		exit(1);
	}
}

/*************************************************************
��������void Input_num(char *u, int n)  
�������û���,����
����ֵ����
�������ܣ������ϴ��ļ���
**************************************************************/
void Input_num(char *u, int n)    
{
	int i;
	int num;
	FILE *fp;
	USER *p = NULL;
	if((fp = fopen(".\\USERS\\userdata.dat", "rb+")) == NULL)
	 //���û����ݿ�
	{
		printf("File UserData.dat cannot be open");
		delay(2000);
		//exit(1);
	}
	fseek(fp, 0, SEEK_END);
	num = ftell(fp) / sizeof(USER);
	
	if((p = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("not enough memory for userfunc.c6");
			delay(2000);
			//exit(1);
		}
	
	for(i = 0; i < num; i++)
	{
		
		fseek(fp, i*sizeof(USER), SEEK_SET);
		fread(p, sizeof(USER), 1, fp);
		fseek(fp, i*sizeof(USER), SEEK_SET);   
		 //���¶�λ�����fwrite�޷�д�������
		if(strcmp(p->user, u) == 0)
		{
			p->num = n;
			fwrite(p, sizeof(USER), 1, fp);
		
			if(p != NULL)
			{
				free(p);
				p = NULL;
			}
			if(fclose(fp) != 0)
			{
				printf("\n cannot close UserData.dat");
				delay(2000);
				//exit(1);
			}
			return;
		}
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	if(fclose(fp) != 0)
	{
		printf("\n cannot close UserData.dat");
		delay(2000);
		exit(1);
	}
	//printf("wrong");
	//exit(1);
}

/*************************************************************
��������void Input_Cfilemenu(File *allfile, char *u)  
�������ļ��ṹ��ָ��,�û���
����ֵ����
��������:�����ļ�Ŀ¼
**************************************************************/
void Input_Cfilemenu(File *allfile, char *u)  
 //�����ļ�Ŀ¼
{
	int i;
	FILE *fp;
	
	char mpath[25]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(mpath,u);
	strcat(mpath,fenge);
	strcat(mpath,"n_");
	strcat(mpath,u);
	strcat(mpath,".dat");

	if((fp = fopen(mpath, "wb+")) == NULL)
	{
		printf("can not open mfile");
		delay(2000);
		exit(1);
	}
	
	for(i=0; i<FILEMAX; i++)
	{
		fwrite(&allfile[i], sizeof(File), 1, fp);
	}
	if(fclose(fp) != 0)
	{
		printf("\n cannot close mfile");
		delay(2000);
		exit(1);
	}
}

/*************************************************************
��������void Output_CFilemenu(File *allfile, char *u)   
�������ļ��ṹ��ָ��,�û���
����ֵ����
�������ܣ������ļ�Ŀ¼
**************************************************************/
void Output_CFilemenu(File *allfile, char *u)   
//�����ļ�Ŀ¼
{
	int i;
	FILE *fp;
	
	char mpath[25]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(mpath,u);
	strcat(mpath,fenge);
	strcat(mpath,"n_");
	strcat(mpath,u);
	strcat(mpath,".dat");

	if((fp = fopen(mpath, "rb")) == NULL)
	{
		printf("can not open mfile");
		delay(2000);
		exit(1);
	}
	fseek(fp, 0, SEEK_SET);
	for(i=0; i<FILEMAX; i++)
	{
		fread(&allfile[i], sizeof(File), 1, fp);
	}
	
	if(fclose(fp) != 0)
	{
		printf("\n cannot close mfile");
		delay(2000);
		exit(1);
	}

}
/*************************************************************
��������int int check_cfile(USER *u,char *filename)
�������ļ��ṹ��ָ��,�û���
����ֵ����
�������ܣ�����ϴ��ļ��Ƿ��Ѿ��ϴ���
**************************************************************/
int check_cfile(USER *u,char *filename)
{
	FILE *fp;

	File allfile[FILEMAX];
	int i;
	int num;
	char mpath[25]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(mpath,u->user);
	strcat(mpath,fenge);
	strcat(mpath,"n_");
	strcat(mpath,u->user);
	strcat(mpath,".dat");
	if((fp = fopen(mpath, "rb+")) == NULL)
	{
		printf("can not open mfile");
		delay(2000);
		exit(1);
	}
	num=ftell(fp)/sizeof(FILE);
	fseek(fp, 0, SEEK_SET);
	for(i=0; i<num; i++)
	{
		fread(&allfile[i], sizeof(File), 1, fp);
	}
	for(i=0;i<num;i++)
	{
		if(strcmp(filename,allfile[i].name)==0)
		{
			if(fclose(fp) != 0)
			{
			printf("\n cannot close mfile");
			delay(2000);
			exit(1);
			}
			return 1;
		}
		
	}
	if(fclose(fp) != 0)
			{
			printf("\n cannot close mfile");
			delay(2000);
			exit(1);
			}
		
	return 2;
	
}



