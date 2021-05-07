#include "common.h"
#include "help.h"

void Draw_About()
{
    int i, j;
    setcolor(RED);
    rectangle(520,0,580,30);
    rectangle(580,0,640,30);
    rectangle(460,0,520,30);
    puthz(462,2,"����",24,30,BLUE);
    puthz(522,2,"����",24,30,BLUE);
    puthz(582,2,"����",24,30,BLUE);
    
	setbkcolor(WHITE);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(2, HORIZ_DIR, 6);
    puthz(246,2,"˼ά��ͼ",32,40,BLUE);
    
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 620; j++)
		{
			putpixel(10 + 10 * j, 40 + 20 * i, LIGHTRED);
		}
	}
	puthz(10, 40, "������Ա�����пƼ���ѧ�˹��������Զ���ѧԺ", 16, 17, RED);

	puthz(10+17*5, 60, "�Զ�����", 16, 17, RED);
	setcolor(RED);
	outtextxy(13 + 17 * 8, 57, "  2003");
	puthz(10 + 17 * 12, 60, "������", 16, 17, BLUE);
	puthz(10 + 17 * 17, 60, "������", 16, 17, BLUE);
    puthz(10, 80, "������Ա�����пƼ���ѧ�˹��������Զ���ѧԺ", 16, 17, RED);
	setcolor(RED);
	outtextxy(13 + 17 * 21, 77, "C");
	puthz(10 + 22 * 17, 80, "���Խ��ڡ�������", 16, 17, RED);

	puthz(10, 100, "�������ڣ�", 16, 17, RED);
	setcolor(BLUE);
	outtextxy(13 + 17 * 5, 97, "2021/4/3");

	puthz(10, 120, "��С��", 16, 17, RED);
	setcolor(BLUE);
	outtextxy(13 + 17 * 3, 117, "xxxx");

	setcolor(RED);
	outtextxy(10, 137, "VERSION: 1.0");

	puthz(10 + 17 * 2, 180, "�����Ϊ���ż���Ʒ���Ե�������Ҫ��ϵ͡�", 16, 17, BLUE);

	puthz(10 + 17 * 2, 200, "���������Ϊ�κ���ҵ��;������������κ�Υ����߳�Ϯ�����", 16, 17, BLUE);
	puthz(10, 220, "����Ϯ���󣬿����߽��е�����Ȩ׷�������Ρ�", 16, 17, BLUE);

	puthz(10 + 17 * 2, 240, "������Ŀ���Ŀ�ģ���Ϊ�˷�����Ҫʹ��˼ά��ͼ�����Լ���ĳ����", 16, 17, BLUE);
	puthz(10, 260, "��������������Աȥѧϰ�뷢ɢ�Լ���˼ά", 16, 17, BLUE);
	puthz(10, 280, "������Ĺ��������������������", 16, 17, BLUE);
	puthz(10+17*2, 320, "����������л", 16, 17, BLUE);
	outtextxy(13 + 17 * 10, 317, "C");
	puthz(10 + 17 * 11, 320, "���Կγ���Ƶ�������ʦ�����̣��Լ�������", 16, 17, BLUE);
	puthz(10, 340, "���ǵ�ͬѧ����������кܶ಻������ǿɸ����Ż��ĵط���ϣ������", 16, 17, BLUE);
	puthz(10, 360, "��һֱ�Ȱ����",16, 17, BLUE);
	
	puthz(30+ 17 * 6, 360, "���Ժͱ����ƣ���������������ߵĸ�Զ��", 16, 17, BLUE);

	
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(3, HORIZ_DIR, 4);
	setcolor(RED);
	outtextxy(140, 390, "HUST:");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(2, HORIZ_DIR, 8);
	setcolor(RED);
	outtextxy(220, 397, "	   SCHOOL OF");
	setcolor(RED);
	outtextxy(50, 430, "ARTIFICIAL INTELLIGENCE AND AUTOMATION");
}

void Help_Func(int *func,int statue)
{
    Draw_Help();
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        //���ذ�ť
        if(MouseX > 580 && MouseY > 0 && MouseX < 640 && MouseY < 30)
        {
            if(mouse_press(580,0,640,30) == 1)
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

            if(mouse_press(580,0,640,30) == 2)
            {
                MouseS = 1;
                continue;
            }
        }
            //����
        if(MouseX > 520 && MouseY > 0 && MouseX < 580 && MouseY < 30)
        {

            if(mouse_press(520,0,580,30) == 2)
            {
                
                MouseS = 1;
                continue;
            
            }

            if(mouse_press(520,0,580,30) == 1)
            {
                clrmous(MouseX , MouseY);
                cleardevice();
               *func = 7;
                return;
            }
            
        }
            //����
        if(MouseX > 460 && MouseY > 0 && MouseX < 520 && MouseY < 30)
        {

            if(mouse_press(460,0,520,30) == 2)
            {
                
                MouseS = 1;
                continue;
            
            }

            if(mouse_press(460,0,520,30) == 1)
            {
                clrmous(MouseX , MouseY);
                cleardevice();
                *func = 6;
                return;

            }
        }

        if(MouseS != 0)
        {
            MouseS = 0;
            continue;
        }

    }
}

void Draw_Help()
{
    int i, j;
    setcolor(RED);
    rectangle(520,0,580,30);
    rectangle(580,0,640,30);
    rectangle(460,0,520,30);
    puthz(462,2,"����",24,30,BLUE);
    puthz(522,2,"����",24,30,BLUE);
    puthz(582,2,"����",24,30,BLUE);
	setbkcolor(WHITE);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(2, HORIZ_DIR, 6);
    puthz(246,2,"˼ά��ͼ",32,40,BLUE);

	puthz(10, 40, "һ�����ʹ�ã�", 16, 17, RED);
    puthz(40,60,"��������Ӱ�ť�������Ӧ���ı���Ϳ��Խ����������",16,17,BLUE);
    puthz(40,80,"���ɾ���ڵ㰴ť����Խ���ɾ��",16,17,BLUE);
    puthz(40,100,"����������ÿ��Ը����ı�����ɫ����������ɫ��������ɫ",16,17,BLUE);
	puthz(40,120,"�ļ���ť���Խ����ļ��ı����½���鿴��ʷ",16,17,BLUE);

    puthz(10, 150, "��������������ô�죺", 16, 17, RED);
    puthz(40,170,"�ڵ�¼��������������ѡ������û����͵绰����ƥ��ɹ�",16,17,BLUE);
	puthz(40,190,"�������д������",16,17,BLUE);
    puthz(10, 210, "������α༭���֣�", 16, 17, RED);
    puthz(40,230,"����һ��ı�������Խ������ֵı༭",16,17,BLUE);
    puthz(40,250,"�����뷨���У����¿ո����ʾ���ģ����»س�����ʾӢ��",16,17,BLUE);

    puthz(10, 270, "�ġ���鿴Ч����ô�죺", 16, 17, RED);
    puthz(40,290,"�����������ٽ�����ɿ���Ԥ��ͼ",16,17,BLUE);

    puthz(10, 310, "�ġ���ν��б��棺", 16, 17, RED);
    puthz(40,330,"��굥���ļ������˵��еı���ѡ��",16,17,BLUE);
    puthz(40,350,"�ڿ��������ļ��������ȷ��",16,17,BLUE);
    puthz(40,370,"�������Ӧ�ļ������ҵ�������ļ�",16,17,BLUE);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(3, HORIZ_DIR, 4);
	setcolor(RED);
	outtextxy(140, 390, "HUST:");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(2, HORIZ_DIR, 8);
	setcolor(RED);
	outtextxy(220, 397, "	   SCHOOL OF");
	setcolor(RED);
	outtextxy(50, 430, "ARTIFICIAL INTELLIGENCE AND AUTOMATION");
}

void About_func(int *func,int statue)
{
    Draw_About();
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        //���ذ�ť
        if(MouseX > 580 && MouseY > 0 && MouseX < 640 && MouseY < 30)
        {
            if(mouse_press(580,0,640,30) == 1)
            {
                if( statue == 1)
                {
                    clrmous(MouseX,MouseY);
                    cleardevice();
					*func = 8 ;
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

            if(mouse_press(580,0,640,30) == 2)
            {
                MouseS = 1;
                continue;
            }
        }
            //����
        if(MouseX > 520 && MouseY > 0 && MouseX < 580 && MouseY < 30)
        {

            if(mouse_press(520,0,580,30) == 2)
            {
                
                MouseS = 1;
                continue;
            }
        

            if(mouse_press(520,0,580,30) == 1)
            {
                clrmous(MouseX , MouseY);
                cleardevice();
                *func = 7;
                return;
                
            }
            
        }
            //����
        if(MouseX > 480 && MouseY > 0 && MouseX < 520 && MouseY < 30)
        {

            if(mouse_press(480,0,520,30) == 2)
            {
                
                MouseS = 1;
                continue;
            }

            if(mouse_press(480,0,520,30) == 1)
            {
                clrmous(MouseX , MouseY);
                cleardevice();
                *func = 6;
                return;
            }
        }

        if(MouseS != 0)
        {
            MouseS = 0;
            continue;
        }

    }
}



