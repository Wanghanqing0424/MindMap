#include "common.h"
#include "history.h"
#include"menufunc.h"
#include"mpfunc.h"
#include "file.h"
#include "popup.h"
#include "USER.h"
#include "LIGANDCO.h"

/*************************************************************
��������void DrawHistory() 
��������
����ֵ����
�������ܣ�������ʷ����
**************************************************************/
void DrawHistory()
{
    setbkcolor(LIGHTCYAN);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(GREEN);
	setfillstyle(1,GREEN);
	pieslice(200,210,0,360,70);
	bar(170,270,170+60,270+40);
	bar(177,320,177+46,320+15);
	bar(185,345,185+30,345+15);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	line(200,210-90,200,210-110);
	line(200-90,210,200-110,210);
	line(200+90,210,200+110,210);
	line(200+64,210+64,200+78,210+78);
	line(200+64,210-64,200+78,210-78);
	line(200-64,210+64,200-78,210+78);
	line(200-64,210-64,200-78,210-78);
    //���Ƶ���          

    puthz(10, 20, "�ڴ˴��鿴������ʷ��¼", 24,30,YELLOW);
    puthz(373, 24, "ѡ��Ŀ¼���в鿴", 24,30,YELLOW);
    setfillstyle(1,WHITE);
    setcolor(BLUE);
    rectangle(369,59,601,461);
    bar(370, 60, 600, 460);

   	bar(10,390,350,450);

	bar(10,455,70,475);
	bar(290,455,350,475);
	rectangle(10,455,70,475);
	rectangle(290,455,350,475);

	rectangle(9,389,349,449);

	line(10,420,350,420);
	line(100,390,100,450);
	puthz(20,392,"�鿴",16,54,RED);
	puthz(20,422,"ɾ��",16,54,RED);
	puthz(18,456,"ȷ��",16,30,RED);
	puthz(298,456,"����",16,30,RED);
	
    
}

/*************************************************************
��������void History_Func(int *func,USER *u,struct mpdata *mp,int statue,struct comparedata *CMP)
������������ת����,�û��ṹ��ָ��,˼ά��ͼ�ṹ��ָ��,��ʽ�жϲ���
����ֵ����
�������ܣ�������ʷ����
**************************************************************/
void History_Func(int *func,USER *u,struct mpdata *mp,int statue,struct comparedata *CMP)
{
	int click1=0;
	int click2=0;
	int format;
	File allfile[FILEMAX];
	//�ļ���
    char filename[10];
	//�ж��ļ��������
	int fun=0;
    int num=0;
    cleardevice();
    DrawHistory();

    if(u->history != 0)
	{
		Output_Filemenu(allfile, u->user);
		//�����ļ�Ŀ¼
		Printfilemenu_History(allfile, u->history);
		//��ӡ�ļ�Ŀ¼
	}
	else
	{
		puthz(420, 180, "���û�����", 16, 17, BLUE);
	}
    while(1)
    {
        newmouse(&MouseX,&MouseY,&press);
        if(MouseX > 290 && MouseX < 350 && MouseY > 455 && MouseY < 475)
        {
            //���ذ�ť
            if(mouse_press(290,455,350,475) == 1)
            {
                if( statue == 1)
                {
                    clrmous(MouseX,MouseY);
                    cleardevice();
					*func = 8;
                    return ;
                }

                if( statue == 2)
                {
                    clrmous(MouseX,MouseY);
					cleardevice();
					*func = 9;
                    return ;
                }
            }

            if(mouse_press(290,455,350,475) == 2)
            {
                MouseS = 1;
                continue;
            }
        }

        //�鿴��ť
        if(MouseX > 100 && MouseX < 350 && MouseY > 390 && MouseY < 420)
        {
            if(mouse_press(100,390,350,420) == 2)
            {
                MouseS = 2;
                continue;
            }

            if(mouse_press(100,390,350,420) == 1)
            {
				clrmous(MouseX,MouseY);
				click1=1;
				EnterFileName(filename,110,391,7,WHITE);
				format=getfileformat(u->user,filename);
				continue;
			}
		}
		//ɾ��
	    if(MouseX > 100 && MouseX < 350 && MouseY > 420 && MouseY < 450)
        {
            if(mouse_press(100,420,350,450) == 2)
            {
                MouseS = 2;
                continue;
            }

            if(mouse_press(100,420,350,450) == 1)
            {
				clrmous(MouseX,MouseY);
				click2=1;
				EnterFileName(filename,110,420,7,WHITE);
				
			
				continue;
			}
				
		}

		//ȷ����ť
		if(MouseX > 10 && MouseX < 70 && MouseY > 455 && MouseY < 475)
		{
			if((mouse_press(10,455,70,475) == 1) && click2==1)
			{
				clrmous(MouseX, MouseY);
				fun = Examine_Filename(u, allfile, filename);
				
				//�ļ�������û�ﵽ����ļ���
				if(fun == 2)
				{
					Delete_filename(allfile, filename, u->history); 
					//ɾ���ļ���
					Delete_filedata(u, filename) ; 				
					//ɾ���ļ�����	
					u->history--; 
					//�û���ʷ��һ
					Input_history(u->user,u->history);
					//�޸��û��ṹ������
					Input_filemenu(allfile, u->user);
					//���������ļ��˵�
					puthz(220,362,"ɾ���ɹ�",24,30,BLUE);
					delay(1500);
					cover_save(260, 372,CYAN);
					*func = 5;
					return;
				}
				if(fun == 1 || fun ==3)
				{
					puthz(260,372,"�޴��ļ�",24,30,BLUE);
					delay(1500);
					cover_save(260, 372,CYAN);
					*func = 5;
					return;
				}
			}

			if((mouse_press(10,455,70,475) == 1) && click1 == 1)
			{
				clrmous(MouseX, MouseY);
				fun = Examine_Filename(u, allfile, filename);

				if(fun == 2 && format == 3)
				{
					memset(CMP,'\0', sizeof(struct comparedata));
					Output_Cfile(u->user,CMP,filename);

					puthz(220,362,"������",24,30,BLUE);
					delay(1000);
					clrmous(MouseX,MouseY);
					cleardevice();
					//����������
					*func = 13;
					return;
				}

				if(fun == 2 && format!= 3)
				{
					memset(mp,'\0', sizeof(struct mpdata));
					initmp(format, mp);
					Output_File(u->user,mp,filename);
					//����ָ���ļ�����
					puthz(220,362,"������",24,30,BLUE);
					delay(1000);
					clrmous(MouseX,MouseY);
					cleardevice();
					//����������
					if( statue == 1)
                    {
                        clrmous(MouseX,MouseY);
                        cleardevice() ;
						*func = 8;
                        return ;
                    }

                    if( statue == 2)
                    {
                        clrmous(MouseX,MouseY);
						cleardevice();
						*func = 9;
                        return ;
                    }
					
				}
				

				if(fun == 1 || fun ==3)
				{
					puthz(260,372,"�޴��ļ�",24,30,BLUE);
					delay(1500);
					cover_save(260, 372,CYAN);
					*func = 5;
					return;
				}
				 
			}
		}
		


        if( MouseS != 0 )
        {
            MouseS = 0;
            continue;
        }
    }
}


/*************************************************************
��������void printt_Filemenu(File *allfile, char *u)   
�������ļ��ṹ��ָ��,�û���
����ֵ����
�������ܣ���ӡ�ļ�Ŀ¼
**************************************************************/

void Printfilemenu_History(File *allfile, int n)   //��ӡ�ļ�Ŀ¼
{
	int i;
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	//����Ϊ���ޣ�����������
	if(n<=10);
	{
		for(i=0;i<n;i++)
		{
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
			//����
			Drawpoint(385, 100+10+40*i);
			//����ļ���
			outtextxy(392, 100+40*i, allfile[i].name);
			//�����ʽ
			switch(allfile[i].format)
			{
				case 1:
					puthz(384+165, 100+5+40*i,"��ʽһ",16,17,BLUE);
					break;
				case 2:
					puthz(384+165, 100+5+40*i,"��ʽ��",16,17,BLUE);
					break;
				case 3:
					puthz(384+165, 100+5+40*i,"�Ա�",16,17,BLUE);
					break;
			}
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			outtextxy(390+10, 100+25+40*i, allfile[i].filetime);
		}
	}
	
}

/*************************************************************
��������int getfileformat(char *username, char *filename)
�������ļ���,�û���
����ֵ����ʽ��Ϣ
�������ܣ��õ�ָ���ļ���ʽ
**************************************************************/
int getfileformat(char *username, char *filename)
{
	int i;
	int num;
	int fileformat;
	File *buf = NULL;
	FILE *fp;
	
	char path[40]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(path, username);
	strcat(path, fenge);
	strcat(path, "m_");
	strcat(path, username);
	strcat(path,".dat");
	
	if((fp = fopen(path,"rb+")) == NULL) //���û����ݿ�
	{
		printf("File fileformat cannot be open");
		delay(2000);
		exit(1);
	}
	
	fseek(fp, 0, SEEK_END);
	num = ftell(fp) / sizeof(File);
	
	for(i = 0; i < num; i++)
	{
		if((buf = (File*)malloc(sizeof(File))) == NULL)
		{
			printf("not enough memory for fileformat");
			delay(2000);
			exit(1);
		}
		fseek(fp, i*sizeof(File), SEEK_SET);
		fread(buf, sizeof(File), 1, fp);
		if(strcmp(buf->name, filename) == 0)
		{
			fileformat = buf->format;
			if(buf != NULL)
			{
				free(buf);
				buf = NULL;
			}
			break;
		}
		if(buf != NULL)
		{
			free(buf);
			buf = NULL;
		}
	}
	if(buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
	if(fclose(fp) != 0)
	{
		printf("\n cannot close fileformat");
		delay(2000);
		exit(1);
	}
	return fileformat;
}
