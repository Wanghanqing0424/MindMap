#ifndef  _COMPARE_H__
#define  _COMPARE_H__
#include "user.h"
//���ƶԱ�ģʽ
void draw_input_compare();
//�Աȹ��ܵ���
void comparefunc(int *func,USER *u,struct comparedata *CMP ,int tate);
//�����ı���
void Light_Compare(int x, int y, int x1, int y1, int color1, int color2);
//���ƶԱ�ģʽ
void DRAW(int *func ,struct comparedata *CMP);
//�����ļ�
void Input_Cfiledata( char *u, char theme[][18],char similar[][20],char differ1[][20]
                    ,char differ2[][20],int si_num,int dif1_num,int dif2_num,char *filename);   

struct comparedata
{
    char theme[2][18];  
	char differ1[6][20];
    char differ2[6][20];
    char similar[6][20];
    int si_num;
	int dif1_num;
    int dif2_num;  
};

#endif
