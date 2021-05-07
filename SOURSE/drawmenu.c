#include"common.h"
#include"input.h"
#include"drawmenu.h"
#include"mpfunc.h"
/*************************************************************
��������draw_menu(struct mpdata mp)
������˼ά��ͼ�ṹ��mp
����ֵ����
�������ܣ����»����Ϸ��˵�
**************************************************************/
void draw_menu(struct mpdata mp)
{	
	setbkcolor(mp.bkcolor);

	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(0, 0, 640, 24);
	
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE, 0, 1);
	//�ļ�
	line(60, 0, 60, 24);
	puthz(10, 4, "�ļ�", 16, 24, DARKGRAY);
	//��������
	line(165, 0, 165, 24);
	puthz(68, 4, "��������", 16, 24, DARKGRAY);
	//�������
	line(255, 0, 255, 24);
	puthz(170, 4, "�������", 16, 20, DARKGRAY);
	//ɾ������
	line(360, 0, 360, 24);
	puthz(260, 4, "ɾ������", 16, 24, DARKGRAY);
	//Ԥ��
	line(415, 0, 415, 24);
	puthz(367, 4, "�༭", 16, 24, DARKGRAY);
	//����
	line(472,0,472,24);
	puthz(425,4,"����",16,24,DARKGRAY);
	//ȡ��
	line(525,0,525,24);
	puthz(476,4,"ȡ��",16,28,DARKGRAY);
	//����
	line(575,0,575,24);
	puthz(529,4,"����",16,24,DARKGRAY);

	//���
	line(616, 0, 616, 24);
	line(616, 0, 640, 0);
	line(616, 24, 640, 24);
	line(640, 0, 640, 24);
	line(616, 0, 640, 24);
	line(616, 24, 640, 0);
	//���ͷ
	line(0, 465, 5, 460);
	line(0, 465, 5, 470);
	line(5, 460, 5, 463);
	line(5, 467, 5, 470);
	line(5, 463, 10, 463);
	line(5, 467, 10, 467);
	line(10, 463, 10, 467);
	//�Ҽ�ͷ
	line(20, 463, 20, 467);
	line(20, 463, 25, 463);
	line(20, 467, 25, 467);
	line(25, 463, 25, 460);
	line(25, 467, 25, 470);
	line(25, 460, 30, 465);
	line(25, 470, 30, 465);
	//�ϼ�ͷ
	line(15, 450, 10, 455);
	line(15, 450, 20, 455);
	line(10, 455, 13, 455);
	line(17, 455, 20, 455);
	line(13, 455, 13, 460);
	line(17, 455, 17, 460);
	line(13, 460, 17, 460);
	//�¼�ͷ
	line(13, 470, 17, 470);
	line(13, 470, 13, 475);
	line(17, 470, 17, 475);
	line(10, 475, 13, 475);
	line(17, 475, 20, 475);
	line(10, 475, 15, 480);
	line(20, 475, 15, 480);
}

/*************************************************************
��������init_z_menu(int flag)
�������ж����ĸ������˵��ı�־flag
����ֵ����
�������ܣ����»��������˵�
**************************************************************/
void init_z_menu(int flag)
{
	clrmous(MouseX,MouseY);
	setfillstyle(1,LIGHTGRAY);

	switch(flag)
	{
		case 1:
		//�ļ������˵�
		bar(0,24,60,105);
		setcolor(RED);
		rectangle(0,24,60,104);
		line(0,24,60,24);
		line(0,44,60,44);
		line(0,64,60,64);
		line(0,84,60,84);
		puthz(3,25,"�½�",16,20,DARKGRAY);
		puthz(3,45,"����",16,20,DARKGRAY);
		puthz(3,65,"��ʷ",16,20,DARKGRAY);
		puthz(3,85,"���",16,20,DARKGRAY);
	
		break;

		case 2:
		//�༭�����˵�
		bar(60,24,165,185);
		setcolor(RED);
		rectangle(60,24,165,184);
		line(60,44,165,44);
		puthz(63,25,"��������ɫ",16,20,DARKGRAY);
		line(60,64,165,64);
		puthz(63,45,"�ı�����ɫ",16,20,DARKGRAY);
		line(60,84,165,84);
		puthz(63,65,"������ɫ",16,23,DARKGRAY);
		line(60,104,165,104);
		puthz(63,85,"������ɫ",16,23,DARKGRAY);
		line(60,124,165,124);
		puthz(63,105,"��ע",16,79,DARKGRAY);
		line(60,144,165,144);
		puthz(63,125,"����",16,79,DARKGRAY);
		line(60,164,165,164);
		puthz(63,145,"����״̬",16,23,DARKGRAY);
		line(60,184,165,184);
		puthz(63,165,"�۵�",16,79,DARKGRAY);
	
	
		default:
		break;

	}

}

