#ifndef  _COMMUNIT_H__
#define  _COMMUNIT_H__
#include "file.h"

typedef struct community
{
	char username[8];
	int history;	
    
}COM;

//�����û��ղؽ���
void Draw_Community();
//
void ZSinputtofile(char* name);
//�ղع��ܵ���
void Community_func(int *func, USER *u,struct mpdata *mp,struct comparedata *CMP);
//
void drawlock1(int x,int y);
//
void drawlock2(int x,int y);
//
void Output_ZSdata(File *allfile);
//
void Insert_ZSfilemenu(File *allfile, char *filename, int n);
//
void Input_zchistory(int n);
//
void Input_zsfilemenu(File *allfile);



#endif
