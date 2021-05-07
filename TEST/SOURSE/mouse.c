#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include "mouse.h"


int MouseX;  //���λ��x
int MouseY;  //���λ��y
int MouseS;  //�����״Shape
int press;   //��갴ѹ״̬
void *buffer;
union REGS regs;
int flag=0;  //��껭�����״̬

/*************************************************************
��������mouseinit()
��������
����ֵ����
�������ܣ�����ʼ��
**************************************************************/	
void mouseinit()
{
	int retcode;
	int xmin,xmax,ymin,ymax,x_max=625,y_max=480;
	int size;

	xmin=2;
	xmax=x_max-1;
	ymin=8;
	ymax=y_max-2;
	regs.x.ax=0;
	int86(51,&regs,&regs);
	retcode=regs.x.ax;
	if(retcode==0)
	{
		printf("Mouse or Mouse Driver Obsent,Please Install!");
		delay(5000);
	}
	else
	{
		regs.x.ax=7;
		regs.x.cx=xmin;
		regs.x.dx=xmax;
		int86(51,&regs,&regs);
		regs.x.ax=8;
		regs.x.cx=ymin;
		regs.x.dx=ymax;
		int86(51,&regs,&regs);
	}
	MouseS = 0;
	MouseX=320,MouseY=240;
	save_bk_mou(320,240);
	mouse(MouseX,MouseY);
	flag=1;
}
/*************************************************************
��������mouse(int x,int y)
�������������xy
����ֵ����
�������ܣ�����ͬ��̬�����
**************************************************************/	
void mouse(int x,int y)
{
	
	switch(MouseS)
	{
		case 1:                                  //�������
		{
				setcolor(BLUE);
				setlinestyle(0,0,1);
				line(x-1,y+9,x-1,y+8);
				line(x,y+7,x,y+11);
				line(x+1,y+6,x+1,y+13);
				line(x+2,y+8,x+2,y+14);
				line(x+3,y-1,x+3,y+15);
				arc(x+4,y-1,0,180,1);
				line(x+4,y-2,x+4,y+15);
				line(x+5,y-1,x+5,y+16);
				arc(x+6,y+3,0,180,1);
				line(x+6,y+2,x+6,y+16);
				line(x+7,y+3,x+7,y+17);
				arc(x+8,y+5,0,180,1);
				line(x+8,y+4,x+8,y+17);
				line(x+9,y+5,x+9,y+16);
				arc(x+10,y+7,0,180,1);
				line(x+10,y+6,x+10,y+16);
				line(x+11,y+7,x+11,y+13);

				setcolor(BLUE);
				line(x-1,y+9,x-1,y+8);
				line(x-1,y+8,x+1,y+6);
				line(x+1,y+6,x+3,y+10);
				line(x+3,y+10,x+3,y-1);
				arc(x+4,y-1,0,180,1);
				line(x+5,y-1,x+5,y+5);
				arc(x+6,y+3,0,180,1);
				line(x+7,y+3,x+7,y+7);
				arc(x+8,y+5,0,180,1);
				line(x+9,y+5,x+9,y+9);
				arc(x+10,y+7,0,180,1);
				line(x+11,y+7,x+11,y+13);
				arc(x+7,y+13,-90,0,4);
				line(x+7,y+17,x+3,y+15);
				line(x+3,y+15,x+1,y+13);
				line(x+1,y+13,x-1,y+9);
		}
			break;
		case 2:                        //���
		{
			setcolor(BLUE);
			setlinestyle(0,0,1);
			line(x+1,y-1,x+9,y-1);
			line(x+1,y+15,x+9,y+15);
			line(x+5,y-1,x+5,y+15);
		}
			break;
		case 3:                        //ʮ��
		{
			setcolor(BLUE);
			setlinestyle(0,0,1);
			line(x-1,y+7,x+11,y+7);
			line(x+5,y-1,x+5,y+15);
		}
			break;
		default:              //Ĭ�����
		{
			setcolor(BLUE);
			 line(x,y,x,y+15);
  			 line(x+1,y+1,x+1,y+13);
 			 line(x+2,y+3,x+2,y+11);
 			 line(x+3,y+4,x+3,y+9);
			 line(x+4,y+5,x+4,y+9);
 			 line(x+5,y+7,x+5,y+10);
 			 line(x+6,y+8,x+6,y+10);
			 line(x+7,y+9,x+7,y+11);
			 line(x+8,y+11,x+8,y+11);
			 line(x+9,y+12,x+9,y+12);
		}
		break;
	}
}

/*************************************************************
��������mread(int *nx,int *ny,int *nbuttons)
��������������ַ*nx*ny,��ť״̬��ַ*nbuttons
����ֵ����
�������ܣ���ȡ�µļĴ�����Ϣ
**************************************************************/	
void mread(int *nx,int *ny,int *nbuttons)  
{
	regs.x.ax=3;
	int86(51,&regs,&regs);
	*nx = regs.x.cx;
	*ny = regs.x.dx;
	*nbuttons = regs.x.bx;
}
/*************************************************************
��������newmouse(int *nx,int *ny,int *nbuttons)
��������������ַ*nx*ny,��ť״̬��ַ*nbuttons
����ֵ����
�������ܣ����״̬�����仯��������
**************************************************************/	
void newmouse(int *nx,int *ny,int *nbuttons)
{
	int xn,yn,buttonsn;
	int x0=*nx,y0=*ny,buttons0=*nbuttons;
	mread(&xn,&yn,&buttonsn);
	*nx = xn;
	*ny = yn;
	*nbuttons = buttonsn;
	if(buttons0 == *nbuttons)
		*nbuttons = 0;    //ʹ������������
	if(xn == x0 && yn == y0 && buttonsn == buttons0)
		return;            //���״̬������ֱ�ӷ���S
	clrmous(x0,y0);        //˵�����״̬�����˸ı�
	save_bk_mou(*nx,*ny);
	drawmous(*nx,*ny);
}
/*************************************************************
��������save_bk_mou(int nx,int ny)
�������������nxny
����ֵ����
�������ܣ�����걳��
**************************************************************/	
void save_bk_mou(int nx,int ny)
{
	int size;

	size=imagesize(nx-1,ny-2,nx+11,ny+17);
	buffer=malloc(size);
	if(buffer!=NULL)
		getimage(nx-1,ny-2,nx+11,ny+17,buffer);
	else
		printf("Error");
}
/*************************************************************
��������clrmous(int nx,int ny)
�������������nxny
����ֵ����
�������ܣ�������
**************************************************************/	
void clrmous(int nx,int ny)
{
	if(flag==1)
	{
		setwritemode(XOR_PUT); 
		mouse(nx,ny);
		putimage(nx-1,ny-2,buffer,COPY_PUT);
		free(buffer);
		flag=0;
		setwritemode(COPY_PUT);
	}
}
/*************************************************************
��������drawmous(int nx,int ny)
�������������nxny
����ֵ����
�������ܣ������
**************************************************************/	
void drawmous(int nx,int ny)
{
	if(flag==0)
	{
		setwritemode(COPY_PUT);
	    mouse(nx,ny);
		flag=1;
	}
}

/*************************************************************
��������mouse_press(int x1, int y1, int x2, int y2)
�����������������Ͻ�����x1y1�����½�����x2y2
����ֵ��1:�ڿ��е�� 2���ڿ���δ��� 0�����ڿ���
�������ܣ��ж��������
**************************************************************/	
//����ڿ��е�����򷵻�1���ڿ���δ������򷵻�2�����ڿ����򷵻�0
int mouse_press(int x1, int y1, int x2, int y2)
{
	//�ڿ��е�����򷵻�1
	if(MouseX > x1 
	&&MouseX < x2
	&&MouseY > y1
	&&MouseY < y2
	&&press == 1)
	{
		return 1;
	}
	
	//�ڿ���δ������򷵻�2
	else if(MouseX > x1 
	&&MouseX < x2
	&&MouseY > y1
	&&MouseY < y2
	&&press == 0)
	{
		return 2;
	}
	
	//�ڿ��е���Ҽ����򷵻�3
	else if(MouseX > x1 
	&&MouseX < x2
	&&MouseY > y1
	&&MouseY < y2
	&&press == 2)
	{
		return 3;
	}
	
	else
	{
		return 0;
	}
}
/*************************************************************
��������mouse_presscircle(int x, int y, int r)
�����������Բ��Բ������x1y1,�뾶r
����ֵ��1:�ڿ��е�� 2���ڿ���δ��� 0�����ڿ���
�������ܣ��ж������Բ
**************************************************************/	
int mouse_presscircle(int x, int y, int r)
{
	if(((MouseX - x) * (MouseX - x) + (MouseY - y) * (MouseY - y)) < r*r && press == 1)
	{
		return 1;
	}
	else if(((MouseX - x) * (MouseX - x) + (MouseY - y) * (MouseY - y)) < r*r && press == 0)
	{
		return 2;
	}
	else if(((MouseX - x) * (MouseX - x) + (MouseY - y) * (MouseY - y)) < r*r && press == 2)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

int mouse_pressother(int x1,int y1,int x2,int y2)
{
	if((MouseX < x1 || MouseX > x2 || MouseY < y1 || MouseY > y2) && press == 1)
		return 1;
	else
		return 0;
}


