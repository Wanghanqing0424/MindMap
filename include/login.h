#ifndef  _LOGIN_H__
#define  _LOGIN_H__
#include "USER.h"

//��¼����Ĺ���ѡ��
void Userslogin_func(int *func,USER*u, struct mpdata *mp,int * judge) ;
//��¼����Ļ���
void draw_login(void) ;
//�����жϵ�¼��Ϣ�Ƿ�������ȫ����ȷ
int login_complete(char* u, char* p);
//�ж��û����������Ƿ�ƥ��
int login(char* name, char*password);
#endif