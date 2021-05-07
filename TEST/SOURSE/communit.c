#include "communit.h"
#include "common.h"
#include "file.h"
#include "save.h"
#include "history.h"
#include"mpfunc.h"
#include"menufunc.h"

/*************************************************************
��������void draw_community()
����:	��
����ֵ����
�������ܣ������û��ղؽ���
**************************************************************/
void Draw_Community()
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

    puthz(27, 20, "�ڴ˴��鿴�����ղ�", 24,30,YELLOW);
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
��������void Community_func(int *func, USER *u,struct mpdata *mp,struct comparedata *CMP)
����:	������ת�ж�ֵfunc���û�ָ�룬�ṹ��ָ��
����ֵ����
�������ܣ��ղع��ܵ���
**************************************************************/
void Community_func(int *func, USER *u,struct mpdata *mp,struct comparedata *CMP)
{
	int fun;
	int format;
	int click1;
	int click2;
	int j;
    File allfile[FILEMAX];
    char filename[20];
	Draw_Community();
    //�ж������ϴ���¼
    if(u->num!=0)
    {
		//�������Ҵ�ӡ���ϴ��ļ�Ŀ¼
        Output_CFilemenu(allfile, u->user);
        Printfilemenu_History(allfile,u->num);
	}
	


    while(1)
    {
        newmouse(&MouseX,&MouseY,&press);

        if(MouseX > 290 && MouseX < 350 && MouseY > 455 && MouseY < 475)
        {
            //���ذ�ť
            if(mouse_press(290,455,350,475) == 1)
            {
            
                        clrmous(MouseX,MouseY);
						cleardevice();
						*func = 3;
                        return ;
                    
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
				//�����ļ������һ�ȡ��ʽ��Ϣ
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
				//�õ��ļ��Ƿ����
				fun = Examine_Filename(u, allfile, filename);
				
				//�ļ�������û�ﵽ����ļ���
				if(fun == 2)
				{
					Delete_filename(allfile, filename, u->history); 
					//ɾ���ļ���					
					u->num--; 
					//�û��ϴ���ʷ��һ
					Input_num(u->user,u->num);
					//�޸��û��ṹ������
					Input_Cfilemenu(allfile, u->user);
					//���������ļ��˵�
					puthz(220,362,"ɾ���ɹ�",24,30,BLUE);
					delay(1500);
					cover_save(220, 362,LIGHTCYAN);
					*func = 12;
					return;
				}
				if(fun == 1 || fun ==3)
				{
					puthz(260,372,"�޴��ļ�",24,30,BLUE);
					delay(1500);
					cover_save(260, 372,CYAN);
					*func = 12;
					return;
				}
			}

			if((mouse_press(10,455,70,475) == 1) && click1 == 1)
			{
				clrmous(MouseX, MouseY);
				fun = Examine_Filename(u, allfile, filename);
				if(fun == 2 && format == 3)
				//Ϊ�ԱȰ�ʽ
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
					//Ϊ��ʽһ�����ǰ�ʽ��
					memset(mp,'\0', sizeof(struct mpdata));
					initmp(format, mp);
					Output_File(u->user,mp,filename);
					//����ָ���ļ�����
					puthz(220,362,"������",24,30,BLUE);
					delay(1000);
					clrmous(MouseX,MouseY);
					cleardevice();
					//����������
					if( format == 1)
                    {
                        clrmous(MouseX,MouseY);
						cleardevice();						
						*func = 8;
                        return ;
                    }

                    if( format == 2)
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
					cover_save(260, 372,LIGHTCYAN);
					*func = 12;
					return;
				}				 
			}
		}
    }
}


