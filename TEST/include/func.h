#ifndef  _FUNC_H__
#define  _FUNC_H__

void inputadmin(char* id, int x1, int y1, int charnum, int color);
//�����˺ſ���
void inputpassword(char* id, int x1, int y1, int charnum, int color);
//�����������
void panduan(char* s, int* jud, int x, int y,int color);
//s�ж��Ƿ�����
int Search_S_user(char * name,int z);
//�ж��Ƿ��ظ�
int judge_name(char* s, int x, int y);
//�ж��û����Ƿ����6λ��С��12λ
int judge_ispasswordsame(char* s1, char* s2, int x, int y);
//�ж������Ƿ����6λС��12λ
int judge_tel(char* s, int x, int y,int z);
//�жϵ绰�����Ƿ���ϸ�ʽ

#endif