#ifndef _INPUT_H_
#define _INPUT_H_

int hz_input(int x1,int y1,int x2,int y2,char *s,int len,int color);
//�������뷨
int input_method(int x,int y,char *str,int value,char *py) ;
//�������뷨����
char *itostr(int a,char *s);
//���ֱ��
void pyFrm(int x1,int y1,int x2,int y2);
// /���뷨С��
int xouttextxy(int x,int y,char *s,int color);
//�ַ����뷨
void hz_int(int x1,int y1,int x2,int y2,char *s,int color);
//�����ַ�������ʾ

#endif
