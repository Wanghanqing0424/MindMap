#ifndef _SAVE_H_
#define _SAVE_H_
#include "user.h"
#define FILEMAXNUM 100
#include "file.h"
//���Ʊ������
void DrawSave();
//����������
void SaveFunc(int *func,USER *u,struct mpdata *mp,int statue);
//������ʷ
void Input_history(char *u, int n) ;
//���°�ʽ
void Input_format(char *u, int n) ;
//�����ϴ��ļ���
void Input_num(char *u, int n) ; 
//�����ļ�Ŀ¼
void Input_Cfilemenu(File *allfile, char *u)  ;
//�����ļ�Ŀ¼
void Output_CFilemenu(File *allfile, char *u)   ;
//����ϴ��ļ��Ƿ��Ѿ��ϴ���
int check_cfile(USER *u,char *filename);
#endif