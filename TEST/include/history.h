#ifndef _HISTORY_H_
#define _HISTORY_H_
#include "USER.h"
#include "file.h"
#include "compare.h"
void DrawHistory();
//������ʷ����
void History_Func(int *func,USER *u,struct mpdata *mp,int statue,struct comparedata *CMP);
//������ʷ����
void Printfilemenu_History(File *allfile, int n);   //打印文件�?�?
//��ӡ�ļ�Ŀ¼
int getfileformat(char *username, char *filename);
//�õ�ָ���ļ���ʽ
#endif