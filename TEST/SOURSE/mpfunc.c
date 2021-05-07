#include "popup.h"
#include"common.h"
#include"input.h"
#include"mpfunc.h"

/*************************************************************
��������redrawbar(struct mpdata mp)
������˼ά��ͼ�ṹ��mp
����ֵ����
�������ܣ����»��������ı���
**************************************************************/
void redrawbar(struct mpdata mp)
{
	int i;
	int j;
	//����
	cleardevice();
	
	//����
	for (i = 0; i < mp.amooflevel; i++)
	{
		for (j = 0; j < mp.amoofson[i]; j++)
		{	
			if (mp.text[i][j].state == 1)
			{
				//������ɫ
				setfillstyle(SOLID_FILL, mp.text[i][j].barcolor);
				bar(mp.text[i][j].barX, mp.text[i][j].barY, mp.text[i][j].barX + barlength, mp.text[i][j].barY + barwidth);
			}	
		}
	}
}
/*************************************************************
��������redrawline(int state, struct mpdata mp)
������˼ά��ͼ��ʽstate,˼ά��ͼ�ṹ��mp
����ֵ����
�������ܣ����»�������������
**************************************************************/
void redrawline(int state, struct mpdata mp)
{
	int i;
	int j;
	int x1;
	int x2;
	int y1;
	int y2;
	char a[10];
	//������
    setlinestyle(SOLID_LINE, 0, 1);
	//���Զ����ɵ���
	for (i = 0; i < mp.amoofline; i++)
	{
		if (mp.connect[i].state1 == 1 && mp.connect[i].state2 == 1)
		{
			//������ɫ
			setcolor(mp.connect[i].linecolor);
			if (state == 1)
			{
				x1 = mp.text[mp.connect[i].flevel][mp.connect[i].fnum].barX + barlength;
				y1 = mp.text[mp.connect[i].flevel][mp.connect[i].fnum].barY + barwidth / 2;
				x2 = mp.text[mp.connect[i].slevel][mp.connect[i].snum].barX;
				y2 = mp.text[mp.connect[i].slevel][mp.connect[i].snum].barY + barwidth / 2;
			}
			if (state == 2)
			{
				x1 = mp.text[mp.connect[i].flevel][mp.connect[i].fnum].barX + barlength/ 2;
				y1 = mp.text[mp.connect[i].flevel][mp.connect[i].fnum].barY + barwidth;
				x2 = mp.text[mp.connect[i].slevel][mp.connect[i].snum].barX + barlength / 2;
				y2 = mp.text[mp.connect[i].slevel][mp.connect[i].snum].barY;
			}	
			line(x1, y1, x2, y2);		
		}		
	}
	//sprintf(a,"%d",mp.amoofline);
	//put_all(50, 50, a, 10, CYAN);
	//���û��Լ����ӵ���
	setcolor(DARKGRAY);
	for (j = 0; j < mp.amooflink; j++)
	{
		if (mp.link[j].state1 == 1 && mp.link[j].state2 == 1)
		{
			if (state == 1)
			{
				x1 = mp.text[mp.link[j].flevel][mp.link[j].fnum].barX + barlength;
				y1 = mp.text[mp.link[j].flevel][mp.link[j].fnum].barY + barwidth / 2;
				x2 = mp.text[mp.link[j].slevel][mp.link[j].snum].barX;
				y2 = mp.text[mp.link[j].slevel][mp.link[j].snum].barY + barwidth / 2;
			}
			if (state == 2)
			{
				x1 = mp.text[mp.link[j].flevel][mp.link[j].fnum].barX + barlength/ 2;
				y1 = mp.text[mp.link[j].flevel][mp.link[j].fnum].barY + barwidth;
				x2 = mp.text[mp.link[j].slevel][mp.link[j].snum].barX + barlength / 2;
				y2 = mp.text[mp.link[j].slevel][mp.link[j].snum].barY;
			}	
			line(x1, y1, x2, y2);	
		}		
	}
}
/*************************************************************
��������mpinputhz(int state, struct mpdata *mp)
������˼ά��ͼ��ʽstate,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ��༭�ı�����������������
**************************************************************/	
void mpinputhz(int state, struct mpdata *mp)
{
    int i;
    int j;
    if (press == 1)
    {
        for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth && (*mp).text[i][j].state == 1)
				{	
                    clrmous(MouseX, MouseY);
					memset((*mp).text[i][j].hz, '\0', sizeof((*mp).text[i][j].hz));
					redrawbar(*mp);
					redrawstar(*mp);
					redrawnode(state, *mp);
					redrawline(state, *mp);
					printhz(*mp);
					//��ҳ��
					draw_menu(*mp);
                    hz_input((*mp).text[i][j].barX, (*mp).text[i][j].barY, (*mp).text[i][j].barX + barlength, (*mp).text[i][j].barY + barwidth, (*mp).text[i][j].hz, 0, (*mp).text[i][j].hzcolor);
                }
            }
        }
    }
}
/*************************************************************
��������printhz(struct mpdata mp)
������˼ά��ͼ�ṹ��mp
����ֵ����
�������ܣ���ӡ�����ı���ĺ���
**************************************************************/	
void printhz(struct mpdata mp)
{
    int i;
    int j;
    for (i = 0; i < mp.amooflevel; i++)
	{
		for (j = 0; j < mp.amoofson[i]; j++)
		{
            put_all(mp.text[i][j].barX, mp.text[i][j].barY, mp.text[i][j].hz, 5, mp.text[i][j].hzcolor);
        }
    }
}
/*************************************************************
��������deletemp(int state, struct mpdata *mp)
������˼ά��ͼ��ʽstate,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ�ѡ������ɾ�����ı���
**************************************************************/	
void deletemp(int state, struct mpdata *mp)
{
    int i;
    int j;
	int m;
	int n;
	int k;
    //�ж�ѡ�п�ı��
	if (press == 1)
	{
		for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth && (*mp).text[i][j].state == 1)
				{	
					//�ָ��ı���������ߵ��۵�״̬
					recovernode(mp);
					/*if ((*mp).text[i][j].num > 0)
					{
						deleterecord(i, j, mp);
					}*/
					deleterecord(i, j, mp);
					clrmous(MouseX, MouseY);
					//���»��ı���
					redrawbar(*mp);
					redrawnode(state, *mp);
					redrawstar(*mp);
					//���»�������
					redrawline(state, *mp);
					//�������
					printhz(*mp);
					//��ҳ��
					draw_menu(*mp);
					delay(100);
					break;
				}
			}
		}
	}
}

/*************************************************************
��������addmp(int state, struct mpdata *mp)
������˼ά��ͼ��ʽstate,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ�ѡ����������ı���ĸ���
**************************************************************/	
void addmp(int state, struct mpdata *mp)
{	
	int i;
	int j;
	//�жϱ�����ı���ı��
	if (press == 1)
	{
		for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth && (*mp).text[i][j].state == 1)
				{	
					//�ָ��ı���������ߵ��۵�״̬
					recovernode(mp);
					//���¼�����������
					addrecord(i, j, state, mp);
					//���»��ı���
					redrawbar(*mp);
					redrawnode(state, *mp);
					redrawstar(*mp);
					//���»�������
					redrawline(state, *mp);
					//�������
					printhz(*mp);
					//��ҳ��
					draw_menu(*mp);
					delay(100);
					break;
				}
			}
		}
	}
}
/*************************************************************
��������initmp(int state, struct mpdata *mp)
������˼ά��ͼ��ʽstate,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ���ʼ��˼ά��ͼ�ṹ�������
**************************************************************/	
void initmp(int state, struct mpdata *mp)
{
	int i;
	int m;
	int n;
	int k;
	int l;
	if (state == 1)
	{
		(*mp).text[0][0].barX = initbarX1;
		(*mp).text[0][0].barY = initbarY1;
	}	
	if (state == 2)
	{
		(*mp).text[0][0].barX = initbarX2;
		(*mp).text[0][0].barY = initbarY2;
	}
	(*mp).text[0][0].barcolor = CYAN;
	(*mp).text[0][0].hzcolor = DARKGRAY;
	(*mp).text[0][0].state = 1;
	(*mp).bkcolor = WHITE;
	(*mp).amoofson[0] = 1;
	for (m = 0; m < 10; m++)
	{
		for (n = 0; n < 10; n++)
		{
			for (k = 0; k < 32; k++)
			{
				(*mp).text[m][n].hz[k] = '\0';
			}
			(*mp).text[m][n].num = 0;
			(*mp).text[m][n].starstate1 = 0;
			(*mp).text[m][n].starstate2 = 1;
		}
	}
	for (i = 1; i < 10; i++)
	{
		(*mp).amoofson[i] = 0;
	}
	(*mp).amooflevel = 1;
	(*mp).amoofline = 0;
	(*mp).amooflink = 0;
}
/*************************************************************
��������addrecord(int i, int j, int state, struct mpdata *mp)
������������¿�ĸ�����ij,˼ά��ͼ��ʽstate,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ����¼�����������ı������ڲ����п������,����Զ����ɵ�������
**************************************************************/	
void addrecord(int i, int j, int state, struct mpdata *mp)
{
	int k;
	//�ж��Ƿ񳬳�����
	if (i == 9)
	{	
		Popup_Func(8);
		return;
	}
	else
	{	
		//�ж���һ���Ƿ�Ϊ��һ��
		if ((*mp).amoofson[i + 1] == 0)
		{
			(*mp).amooflevel++;			
		}
	}
	//�ж��Ƿ񳬳�����
	if ((*mp).amoofson[i + 1] == 10)
	{
		Popup_Func(8);
		return;
	}
	else
	{
		(*mp).amoofson[i + 1]++;
		(*mp).text[i][j].num++;
	}
	//�������겢�洢
	if (state == 1)
	{
		for (k = 0; k < (*mp).amoofson[i + 1]; k++)
		{
			(*mp).text[i + 1][k].barX = (i + 1) * (barlength + spacelength) + (*mp).text[0][0].barX;
			(*mp).text[i + 1][k].barY = 24 + (480 - 24 - (*mp).amoofson[i + 1] * barwidth - ((*mp).amoofson[i + 1] - 1) * spacewidth) / 2 + k * (spacewidth + barwidth);
		}
	}
	//�������겢�洢
	if (state == 2)
	{
		for (k = 0; k < (*mp).amoofson[i + 1]; k++)
		{
			(*mp).text[i + 1][k].barX = (640 - 24 - (*mp).amoofson[i + 1] * barlength - ((*mp).amoofson[i + 1] - 1) * spacelength) / 2 + k * (spacelength + barlength);
			(*mp).text[i + 1][k].barY = (i + 1) * (barwidth + spacewidth) + (*mp).text[0][0].barY;
		}
	}
	
	//��ʼ����ɫ
	(*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].barcolor = CYAN;
	(*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].hzcolor = DARKGRAY;
	(*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].state = 1;
	(*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].nodestate = 0;
	//�洢��Ҫ���ӵĸ��ڵ���ӽڵ�
	(*mp).amoofline++;
	(*mp).connect[(*mp).amoofline - 1].linecolor = CYAN;
	(*mp).connect[(*mp).amoofline - 1].state1 = 1;
	(*mp).connect[(*mp).amoofline - 1].state2 = 1;
	(*mp).connect[(*mp).amoofline - 1].flevel = i;
	(*mp).connect[(*mp).amoofline - 1].fnum = j;
	(*mp).connect[(*mp).amoofline - 1].slevel = i + 1;
	(*mp).connect[(*mp).amoofline - 1].snum = (*mp).amoofson[i + 1] - 1;
	mpsort(i, j, mp);
}
/*************************************************************
��������deleterecord(int i, int j, struct mpdata *mp)
����������ɾ���Ŀ���ij,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ�ɾ����ѡ�е��ı��������ı���
**************************************************************/	
void deleterecord(int i, int j, struct mpdata *mp)
{
	int g;
	int h;
	int k;
	int l;
	int m;
	int n;
	int count;
	//���ѡ�п�û���ӿ�
	if ((*mp).text[i][j].num == 0)
	{	
		//�ҵ�ѡ�п���Ϊ�ӿ����
		for (k = 0; k < (*mp).amoofline; k++)
		{
			if ((*mp).connect[k].slevel == i && (*mp).connect[k].snum == j && (*mp).connect[k].state1 == 1)
			{
				//����������
				(*mp).connect[k].state1 = 0;
				//������ӿ�����1
				(*mp).text[i - 1][(*mp).connect[k].fnum].num--;
			}
		}
		//�ҵ�ѡ�п�����Ŀ�
		for (g = j + 1; g < (*mp).amoofson[i]; g++)
		{
			strcpy((*mp).text[i][g - 1].hz, (*mp).text[i][g].hz);
			(*mp).text[i][g - 1].hzcolor = (*mp).text[i][g].hzcolor;
			(*mp).text[i][g - 1].barcolor = (*mp).text[i][g].barcolor;
			(*mp).text[i][g - 1].num = (*mp).text[i][g].num;
			(*mp).text[i][g - 1].starstate1 = (*mp).text[i][g].starstate1;
			(*mp).text[i][g - 1].starstate2 = (*mp).text[i][g].starstate2;
			(*mp).text[i][g - 1].state = (*mp).text[i][g].state;
			(*mp).text[i][g - 1].nodestate = (*mp).text[i][g].nodestate;
			for (h = 0; h < (*mp).amoofline; h++)
			{
				//�ҵ�ѡ�п�����Ŀ���Ϊ�������
				if ((*mp).connect[h].flevel == i && (*mp).connect[h].fnum == g && (*mp).connect[h].state1 == 1)
				{
					(*mp).connect[h].fnum--;
				}
				//�ҵ�ѡ�п�����Ŀ���Ϊ�ӿ����
				if ((*mp).connect[h].slevel == i && (*mp).connect[h].snum == g && (*mp).connect[h].state1 == 1)
				{
					(*mp).connect[h].snum--;
				}
			}			
		}
		//ѡ�п����ڲ�Ŀ�����1
		(*mp).amoofson[i]--;
		//���ѡ�п�Ϊ���ڲ�Ψһ��
		if ((*mp).amoofson[i] == 0)
		{
			//˼ά��ͼ������1
			(*mp).amooflevel--;
		}		 
	}
	//���ѡ�п����ӿ�
	/*if ((*mp).text[i][j].num > 0)
	{
		for (l = 0; l < (*mp).amoofline; l++)
		{
			if ((*mp).connect[l].flevel == i && (*mp).connect[l].fnum == j && (*mp).connect[l].state1 == 1)
			{
				//����ӿ����ӿ�
				if((*mp).text[i + 1][(*mp).connect[l].snum].num > 0)
				{
					deleterecord(i + 1, (*mp).connect[l].snum, mp);
				}
				deleterecord(i + 1, (*mp).connect[l].snum, mp);;
			}
		}

	}
	*/
}
/*************************************************************
��������changestar(int state, struct mpdata *mp)
������˼ά��ͼ��ʽ,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ�ѡ������ı��ע״̬���ı���
**************************************************************/	
void changestar(int state, struct mpdata *mp)
{
	int i;
	int j;
	//�ж�ѡ�п�ı��
	//������Ϊ���
	if (press == 1)
	{
		for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth && (*mp).text[i][j].state == 1)
				{	
					
					//�ı��ע״̬
					starstate(1, i, j, mp);
					redrawbar(*mp);
					redrawnode(state, *mp);
                    redrawline(state, *mp);
					redrawstar(*mp);
                    printhz(*mp);
					//��ҳ��
					draw_menu(*mp);
					delay(100);
					break;
				}
										
			}
		}
	}
	//�ж�ѡ�п�ı��
	//����Ҽ�Ϊɾ��
	if (press == 2)
	{
		for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth && (*mp).text[i][j].state == 1)
				{	
					
					//�ı��ע״̬
					starstate(2, i, j, mp);
					redrawbar(*mp);
					redrawnode(state, *mp);
                    redrawline(state, *mp);
					redrawstar(*mp);
                    printhz(*mp);
					//��ҳ��
					draw_menu(*mp);
					delay(100);
					break;
				}
										
			}
		}
	}		
}
/*************************************************************
��������starstate(int state, int i, int j, struct mpdata *mp)
�������ж�ɾ��������ӵı�־state,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ��ı��ע״̬
**************************************************************/	
void starstate(int state, int i, int j, struct mpdata *mp)
{
	if (state == 1)
	{
		if((*mp).text[i][j].starstate1 == 0)
		{
			(*mp).text[i][j].starstate1 =1;
		}	
	}
	if (state == 2)
	{
		if((*mp).text[i][j].starstate1 == 1)
		{
			(*mp).text[i][j].starstate1 =0;
		}	
	}
}
/*************************************************************
��������redrawstar(struct mpdata mp)
������˼ά��ͼ�ṹ��mp
����ֵ����
�������ܣ����»��Ʊ�ע����
**************************************************************/		
void redrawstar(struct mpdata mp)
{
	int i;
	int j;
	int x;
	int y;
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, 3);
	for (i = 0; i < mp.amooflevel; i++)
	{
		for (j = 0; j < mp.amoofson[i]; j++)
		{
			if (mp.text[i][j].starstate1 == 1 && mp.text[i][j].starstate2 == 1)
			{
				x = mp.text[i][j].barX + barlength + 2;
				y = mp.text[i][j].barY + barwidth - 10;
				line(x, y + 5, x + 10, y + 5);
				line(x, y, x + 10, y + 10);
				line(x + 5, y, x + 5, y + 10);
				line(x + 10, y, x, y + 10);
			}
		}
	}
}
/*************************************************************
��������mpsort(int i, int j, struct mpdata *mp)
������˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ���������ı���֮���������򣬷�ֹ���ֽ�����
**************************************************************/	
void mpsort(int i, int j, struct mpdata *mp)
{
    int m;
    int n;
	int h;
	int l;
	int count = 0;
	struct bardata temp;
	//���������ĸ��������ڲ��������
    if (j != (*mp).amoofson[i] - 1)
	{	
		//���������ĸ�������Ŀ����ӿ�
		for (m = j + 1; m < (*mp).amoofson[i]; m++)
		{
			if ((*mp).text[i][m].num > 0)
			{
				strcpy(temp.hz,(*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].hz);
				temp.hzcolor = (*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].hzcolor;
				temp.barcolor = (*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].barcolor;
				temp.num = (*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].num;
				temp.starstate1 = (*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].starstate1;
				temp.starstate2 = (*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].starstate2;
				temp.state = (*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].state;
				temp.nodestate = (*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].nodestate;
				for (l = 0; l < j; l++)
				{
					count = count + (*mp).text[i][l].num;
				}
				//Ų������
				for (n = (*mp).amoofson[i + 1] - 2; n >= 0 + count + (*mp).text[i][j].num - 1; n--)
				{
					strcpy((*mp).text[i + 1][n + 1].hz, (*mp).text[i + 1][n].hz);
					(*mp).text[i + 1][n + 1].hzcolor = (*mp).text[i + 1][n].hzcolor;
					(*mp).text[i + 1][n + 1].barcolor = (*mp).text[i + 1][n].barcolor;
					(*mp).text[i + 1][n + 1].num = (*mp).text[i + 1][n].num;
					(*mp).text[i + 1][n + 1].starstate1 = (*mp).text[i + 1][n].starstate1;
					(*mp).text[i + 1][n + 1].starstate2 = (*mp).text[i + 1][n].starstate2;
					(*mp).text[i + 1][n + 1].state = (*mp).text[i + 1][n].state;
					(*mp).text[i + 1][n + 1].nodestate = (*mp).text[i + 1][n].nodestate;

					for (h = 0; h < (*mp).amoofline; h++)
					{
						//�ҵ�������ĸ����������ӿ���Ϊ�������
						if ((*mp).connect[h].flevel == i + 1 && (*mp).connect[h].fnum == n && (*mp).connect[h].state1 == 1)
						{
							(*mp).connect[h].fnum++;
						}
						//�ҵ�������ĸ����������ӿ���Ϊ�ӿ����
						if ((*mp).connect[h].slevel == i + 1 && (*mp).connect[h].snum == n && (*mp).connect[h].state1 == 1)
						{
							(*mp).connect[h].snum++;
						}
					}
				}
				strcpy((*mp).text[i + 1][0 + count + (*mp).text[i][j].num - 1].hz, temp.hz);
				(*mp).text[i + 1][0 + count + (*mp).text[i][j].num - 1].hzcolor = temp.hzcolor;
				(*mp).text[i + 1][0 + count + (*mp).text[i][j].num - 1].barcolor = temp.barcolor;
				(*mp).text[i + 1][0 + count + (*mp).text[i][j].num - 1].num = temp.num;
				(*mp).text[i + 1][0 + count + (*mp).text[i][j].num - 1].starstate1 = temp.starstate1;
				(*mp).text[i + 1][0 + count + (*mp).text[i][j].num - 1].starstate2 = temp.starstate2;
				(*mp).text[i + 1][0 + count + (*mp).text[i][j].num - 1].state = temp.state;
				(*mp).text[i + 1][0 + count + (*mp).text[i][j].num - 1].nodestate = temp.nodestate;
				(*mp).connect[(*mp).amoofline - 1].snum = 0 + count + (*mp).text[i][j].num - 1;
				break;
			}
		}	
	}
}
/*************************************************************
��������mpup(int state, struct mpdata *mp)
������˼ά��ͼ��ʽstate,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ�ʹ����˼ά��ͼ����
**************************************************************/	
void mpup(int state, struct mpdata *mp)
{
	int i;
	int j;
	for (i = 0; i < (*mp).amooflevel; i++)
	{
		for (j = 0; j < (*mp).amoofson[i]; j++)
		{
			(*mp).text[i][j].barY = (*mp).text[i][j].barY - 100; 
		}
	}
	redrawbar(*mp);
	redrawnode(state, *mp);
    redrawline(state, *mp);
	redrawstar(*mp);
    printhz(*mp);
	//��ҳ��
	draw_menu(*mp);
	delay(100);

}
/*************************************************************
��������mpdown(int state, struct mpdata *mp)
������˼ά��ͼ��ʽstate,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ�ʹ����˼ά��ͼ����
**************************************************************/	
void mpdown(int state, struct mpdata *mp)
{
	int i;
	int j;
	for (i = 0; i < (*mp).amooflevel; i++)
	{
		for (j = 0; j < (*mp).amoofson[i]; j++)
		{
			(*mp).text[i][j].barY = (*mp).text[i][j].barY + 100; 
		}
	}
	redrawbar(*mp);
	redrawnode(state, *mp);
    redrawline(state, *mp);
	redrawstar(*mp);
    printhz(*mp);
	//��ҳ��
	draw_menu(*mp);
	delay(100);

}
/*************************************************************
������: mpleft(int state, struct mpdata *mp)
������˼ά��ͼ��ʽstate,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ�ʹ����˼ά��ͼ����
**************************************************************/	
void mpleft(int state, struct mpdata *mp)
{
	int i;
	int j;
	for (i = 0; i < (*mp).amooflevel; i++)
	{
		for (j = 0; j < (*mp).amoofson[i]; j++)
		{
			(*mp).text[i][j].barX = (*mp).text[i][j].barX - 150; 
		}
	}
	redrawbar(*mp);
	redrawnode(state, *mp);
    redrawline(state, *mp);
	redrawstar(*mp);
    printhz(*mp);
	//��ҳ��
	draw_menu(*mp);
	delay(100);

}
/*************************************************************
������: mpright(int state, struct mpdata *mp)
������˼ά��ͼ��ʽstate,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ�ʹ����˼ά��ͼ����
**************************************************************/	
void mpright(int state, struct mpdata *mp)
{
	int i;
	int j;
	for (i = 0; i < (*mp).amooflevel; i++)
	{
		for (j = 0; j < (*mp).amoofson[i]; j++)
		{
			(*mp).text[i][j].barX = (*mp).text[i][j].barX + 150;
		}
	}
	redrawbar(*mp);
	redrawnode(state, *mp);
    redrawline(state, *mp);
	redrawstar(*mp);
    printhz(*mp);
	//��ҳ��
	draw_menu(*mp);
	delay(100);

}
/*************************************************************
������: mplink(int state, struct mpdata *mp)
������˼ά��ͼ��ʽstate,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ�ѡ����Ҫ�������ӵ��ı���
**************************************************************/	
void mplink(int state, struct mpdata *mp)
{
	int i;
	int j;
	//�ж�ѡ�п�ı��
	//���ѡ���һ����
	if (press == 1)
	{
		for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth && (*mp).text[i][j].state == 1)
				{	
					
					//������
					linkinput(1, i, j, mp);
					break;
				}
										
			}
		}
	}
	//�Ҽ�ѡ��ڶ�����
	if (press == 2)
	{
		for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth)
				{	
					
					//������
					linkinput(2, i, j, mp);
					redrawbar(*mp);
					redrawnode(state, *mp);
        			redrawline(state, *mp);
					redrawstar(*mp);
        			printhz(*mp);
					//��ҳ��
					draw_menu(*mp);
					delay(100);
					break;
				}
										
			}
		}
	}

}
/*************************************************************
������: linkinput(int state, int i, int j, struct mpdata *mp)
�������жϵ������������Ҽ��ı�־state,������ı���ı��ij,state,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ������ݴ��뵽˼ά��ͼ�ṹ��
**************************************************************/	
void linkinput(int state, int i, int j, struct mpdata *mp)
{

	int k;
	if (state == 1)
	{
		(*mp).link[(*mp).amooflink].flevel = i;
		(*mp).link[(*mp).amooflink].fnum = j;
	}
	if (state == 2)
	{
		(*mp).link[(*mp).amooflink].slevel = i;
		(*mp).link[(*mp).amooflink].snum = j;
		(*mp).link[(*mp).amooflink].state1 = 1;
		(*mp).link[(*mp).amooflink].state2 = 1;
		(*mp).amooflink++;
	}
	
}
/*************************************************************
������:linkstate(int state, int flag, struct mpdata *mp)
������˼ά��ͼ��ʽstate,�û����ߵ�״̬flag,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ��ı��û����ߵ�״̬
**************************************************************/	
void linkstate(int state, int flag, struct mpdata *mp)
{
	int i;
	if (flag == 2)
	{
		for (i = 0; i < (*mp).amooflink; i++)
		{
			(*mp).link[i].state1 = 0;
		}
	}
	if (flag == 1)
	{
		for (i = 0; i < (*mp).amooflink; i++)
		{
			(*mp).link[i].state1 = 1;
		}
	}	
	redrawbar(*mp);
	redrawnode(state, *mp);
    redrawline(state, *mp);
	redrawstar(*mp);
    printhz(*mp);
	//��ҳ��
	draw_menu(*mp);
	delay(100);
}
/*************************************************************
������: nodestate(int i, int j, struct mpdata *mp)
������ѡ�п�ı��ij,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ��ı�ѡ�п��ӿ���۵�״̬
**************************************************************/	
void nodestate(int i, int j, struct mpdata *mp)
{
	int g;
	int h;
	int k;
	int l;
	int count = 0;
	//�ҵ�ѡ�п��ӿ�ı��
	for (g = 0; g < j; g++)
	{
		count = count + (*mp).text[i][g].num;
	}
	for (h = 0; h < (*mp).text[i][j].num; h++)
	{
		//�ݹ�ʹ��
		nodestate(i + 1, count + h, mp);	
	}
	//�۵�ѡ�п�
	(*mp).text[i][j].state = 0;
	(*mp).text[i][j].starstate2 = 0;
	//�۵�ѡ�п���Ϊ�������
	for (k = 0; k < (*mp).amoofline; k++)
	{
		if ((*mp).connect[k].flevel == i && (*mp).connect[k].fnum == j && (*mp).connect[k].state2 == 1)
		{
			(*mp).connect[k].state2 = 0;
		}
	}
	for (l = 0; l < (*mp).amooflink; l++)
	{
		if ((*mp).link[l].flevel == i && (*mp).link[l].fnum == j && (*mp).link[l].state2 == 1)
		{
			(*mp).link[l].state2 = 0;
		}
	}
	
}
/*************************************************************
������: mpnode(int state, struct mpdata *mp)
������˼ά��ͼ��ʽstate,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ�ѡ����Ҫ�۵��Ŀ�
**************************************************************/	
void mpnode(int state, struct mpdata *mp)
{
	int i;
	int j;
	//�жϱ�����ı���ı��
	if (press == 1)
	{
		for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth && (*mp).text[i][j].state == 1)
				{	
					//�ı��ı����������ߵ��۵�״̬
					nodestate(i, j, mp);
					//�ָ�ѡ�п���۵�״̬
					(*mp).text[i][j].state = 1;
					(*mp).text[i][j].nodestate = 1;
					//���»��ı���
					redrawbar(*mp);
					//���»��Ʊ�־��
					redrawstar(*mp);
					//���»����۵�����
					redrawnode(state, *mp);
					//���»�������
					redrawline(state, *mp);
					//�������
					printhz(*mp);
					//��ҳ��
					draw_menu(*mp);
					delay(100);
					break;
				}
			}
		}
	}
}
/*************************************************************
������: recovernode(struct mpdata *mp)
������˼ά��ͼ��ʽstate,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ��ָ��ı���������ߵ��۵�״̬
**************************************************************/	
void recovernode(struct mpdata *mp)
{
	int g;
	int h;
	int l;
	int m;	
	for (g = 0; g < (*mp).amooflevel; g++)
	{
		for (h = 0; h < (*mp).amoofson[g]; h++)
		{
			//�ָ��ı�����۵�״̬
			if((*mp).text[g][h].state == 0)
			{
				(*mp).text[g][h].state = 1;
			}
			//�ָ��۵����ŵ�״̬
			if ((*mp).text[g][h].nodestate == 1)
			{
				(*mp).text[g][h].nodestate = 0;
			}
			//�ָ���ע������״̬
			if ((*mp).text[g][h].starstate2 == 0)
			{
				(*mp).text[g][h].starstate2 = 1;
			}
		}
	}
	//�ָ������ߵ��۵�״̬
	for (l = 0; l < (*mp).amoofline; l++)
	{
		if ((*mp).connect[l].state2 == 0)
		{
			(*mp).connect[l].state2 = 1;
		}
	}
	for (m = 0; m < (*mp).amooflink; m++)
	{
		if ((*mp).link[l].state2 == 0)
		{
			(*mp).link[l].state2 = 1;
		}
	}
	
}
/*************************************************************
������: redrawnode(int state, struct mpdata *mp)
������˼ά��ͼ��ʽstate,˼ά��ͼ�ṹ��ĵ�ַ*mp
����ֵ����
�������ܣ������۵�����
**************************************************************/	
void redrawnode(int state, struct mpdata mp)
{
	int x;
	int y;
	int i;
	int j;
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE, 0, 1);
	for (i = 0; i < mp.amooflevel; i++)
	{
		for (j = 0; j < mp.amoofson[i]; j++)
		{
			if(mp.text[i][j].state == 1 && mp.text[i][j].nodestate == 1)
			{
				if(state == 1)
				{
					x = mp.text[i][j].barX + barlength + 5;
					y = mp.text[i][j].barY + barwidth / 2;
				}
				if(state == 2)
				{
					x = mp.text[i][j].barX + barlength / 2;
					y = mp.text[i][j].barY + barwidth + 5;
				}			
				circle(x, y, 5);
				line(x - 5, y, x + 5, y);
				line(x, y - 5, x, y + 5);
			}
		}
	}
}