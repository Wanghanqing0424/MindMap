#ifndef  _FILE_H__
#define  _FILE_H__
#include "USER.h"
#define FILEMAX 10


typedef struct file
{
	char name[8];		
	int format;			
	char filetime[30];	
}File;


typedef struct Zfile
{
	char user[20];
	char name[8];		
	int format;			
	char filetime[30];	
}ZFile;

struct ZSdata {
	char user[20];
	char filename[20];
	char filetime[30];
	int history;
	int format;	
};
//
void SORT_filemenu(File *allfile, int format, int n);
//��ָ���ļ���������
void Output_File(char *u ,struct mpdata *mp,char * filename) ;
//�����ļ�
void Input_data(char *u , struct mpdata *mp);
//�����ļ�
void Input_filedata( char *u , struct mpdata *mp,char *filename)  ;
//��ȡ��ǰʱ��
void Get_filetime(char *filetime)  ; 
//����ļ����
int Judge_Filename(char *name, int x, int y);
//����ļ��Ƿ�����
int Check_SameFile(char *newname, File* allfile, int n);
//����ļ����
int Examine_Filename(USER *u, File* allfile, char *newname);  
//�����û��ļ���
void Createfolder(char *name);
//�����ļ���������
void Insert_filemenu(File *allfile, char *filename, int format, int n)  ;
//
void Insert_Cfilemenu(ZFile *allfile, char *filename, int format, int n, char*user)  ;
//
void Drawpoint(int x, int y) ;
//�����ļ�Ŀ¼
void Output_Filemenu(File *allfile, char *u) ;
//�����ļ�Ŀ¼
void Input_filemenu(File *allfile, char *u)  ; 
//��ӡ�ļ�Ŀ¼
void Print_Filemenu(File *allfile, int n)  ; 
//�ļ������뺯��
void EnterFileName(char*id, int x1, int y1, int charnum, int color);
//�����ļ�
void Outputdata(char *u ,struct mpdata *mp)   ;
//�����ݿ����û���Ϣ����ָ��
int Copy_infor_User(USER *user);
//���û�ע����Ϣд���ļ�
void inputtofile(char* name, char* tel, char* password);
//ɾ���ļ�����
void Delete_filedata(char *u, char *filename) ; 
//ɾ���ļ�Ŀ¼�����Ϣ
void Delete_filename(File *allfile, char *filename, int n)  ; 
//
int Change_format(char *filename, File *allfile, int n);
//
void Change_filemenu(File *allfile, char *filename, int format)  ;
//��ָ���ļ���������
void Output_Cfile(char *u ,struct comparedata *mp,char * filename)   ;
#endif