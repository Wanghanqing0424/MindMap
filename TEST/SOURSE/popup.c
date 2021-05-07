#include "common.h"
#include "popup.h"
#include "quit.h"

/*************************************************************
��������void DrawPopup(int a)
���������
����ֵ����
�������ܣ����Ƶ���
**************************************************************/
void DrawPopup(int a)
{
    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
    setfillstyle(SOLID_FILL, WHITE);
    bar(200, 180, 440, 300);
    rectangle(200, 180, 440, 300);
    setfillstyle(SOLID_FILL, WHITE);
    
    if(a == 1)
    {
		rectangle(297,275,343,295);
    	puthz(302,277,"ȷ��",16,20,4);
        puthz(270, 230, "�ļ��Ѵ���", 16, 20, 4);
    }
    else if(a == 2)
    {
		rectangle(297,275,343,295);
    	puthz(302,277,"ȷ��",16,20,4);
        puthz(270, 230, "����ɹ�", 16, 20, 4);
    }
    else if(a == 3)
    {
		rectangle(215, 275, 263, 295);
		rectangle(377, 275, 425, 295);
    	puthz(223, 277, "ȷ��", 16, 20, 4);
		puthz(383, 277, "ȡ��", 16, 20, 4);
        puthz(269, 230, "ȷ��Ҫ�˳���", 16, 20, 4);
    }
    else if(a == 4)
    {
		rectangle(215, 275, 263, 295);
		rectangle(377, 275, 425, 295);
    	puthz(223, 277, "ȷ��", 16, 20, 4);
		puthz(383, 277, "ȡ��", 16, 20, 4);
        puthz(280, 230, "ȷ��Ҫɾ��������", 16, 20, 4);

    }
    else if(a == 5)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"ȷ��",16,20,4);
	    puthz(280, 230, "�ļ�δ�����Ƿ����", 16, 20, 4);
    }
    else if(a == 6)
	{
		rectangle(297,275,343,295);
   		puthz(302,277,"ȷ��",16,20,4);
	    puthz(280, 230, "����ʧ��", 16, 20, 4);
    }
	else if(a == 7)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"ȷ��",16,20,4);
	    puthz(260, 230, "�ļ��������޷��鿴", 16, 20, 4);
    }
   
   else if(a == 8)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"ȷ��",16,20,4);
	    puthz(285, 230, "�Ѵ�����", 16, 20, 4);
    }

	else if(a == 9)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"ȷ��",16,20,4);
	    puthz(285, 230, "ɾ���ɹ�", 16, 20, 4);

	}

	else if(a == 10)
	{
		rectangle(215, 275, 263, 295);
		rectangle(377, 275, 425, 295);
    	puthz(223, 277, "ȷ��", 16, 20, 4);
		puthz(383, 277, "ȡ��", 16, 20, 4);
        puthz(210, 230, "�ļ���", 16, 20, 4);
		rectangle(280,230,428,250);
		puthz(220, 195, "��������Ҫ�鿴���ļ�", 16, 20, 4);
	}

	else if(a == 11)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"ȷ��",16,20,4);
	    puthz(285, 230, "��δ��¼", 16, 20, 4);
    }

	else if(a == 12)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"ȷ��",16,20,4);
	    puthz(285, 230, "�ļ�������", 16, 20, 4);
    }

	else if(a == 13)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"ȷ��",16,20,4);
	    puthz(285, 230, "�ϴ��ɹ�", 16, 20, 4);
    }

	else if(a == 14)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"ȷ��",16,20,4);
	    puthz(285, 230, "�����û�����", 16, 20, 4);
    }

	else if(a == 15)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"ȷ��",16,20,4);
	    puthz(285, 230, "�����οͿ���", 16, 20, 4);
    }
	}
	

/*************************************************************
��������void Popup_func(int statue)
���������
����ֵ����
�������ܣ����õ���
**************************************************************/
void Popup_Func(int statue)
{
	int num=0;
	void *buffer;
	unsigned s;
    clrmous(MouseX, MouseY);
	s=imagesize(200, 180, 440, 300);
	buffer=malloc(s);
	getimage(200, 180, 440, 300, buffer);
	delay(10);
	DrawPopup(statue);

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		
		if(statue == 3 && mouse_press(215, 275, 263, 295) == 1 )
		{
				cleardevice();
				Quit();
		}
        
		if(statue == 3 && mouse_press(377, 275, 425, 295) == 1)
		{
			clrmous(MouseX, MouseY);
			delay(10);
            putimage(200,180,buffer,COPY_PUT);
            free(buffer);
			return;
		}

		if(statue == 9)
		{
			clrmous(MouseX, MouseY);
			delay(10);

			if(mouse_press(215, 275, 263, 295) == 1)
			{
				clrmous(MouseX, MouseY);
				delay(10);
            	putimage(200,180,buffer,COPY_PUT);
				free(buffer);
				return;
			}

			if( mouse_press(377, 275, 425, 295) == 1)
			{
				clrmous(MouseX, MouseY);
				delay(10);
            	putimage(200,180,buffer,COPY_PUT);
            	free(buffer);
				return;
			}


		}

		//�������
		if((statue == 1 || statue == 2 || statue == 5 || statue == 6 || statue ==11 ||
		    statue == 7 || statue == 8 || statue == 12 || statue == 13 || statue ==14 ||statue ==15) && 
		   (MouseX > 297 && MouseY > 275 && MouseX <343 && MouseY < 295 ) )
		{

			if( mouse_press(297,275,343,295) == 1 )
			{
				clrmous(MouseX, MouseY);
				delay(10);
            	putimage(200,180,buffer,COPY_PUT);
            	free(buffer);
				return;
			}
				
			if( mouse_press(297,275,343,295) == 2 && num ==0)
			{
				MouseS = 1;	
				num = 1;
				continue;
			}
		}


		if(MouseS != 0)
		{
			MouseS = 0;
			continue;
		}

		
    }
}

