#ifndef  _FORGET_H__
#define  _FORGET_H__


//�һ������������й��ܵĵ���
void forget_func(int *func);
//�ж��Ƿ���Ը���������
int forgetpass_match(char* u, char* tel, char* password);
//�ж��˺������֤�Ƿ�ƥ�� �ж���������������Ƿ���ͬ ��ƥ������ͬ��д��������
int name_id(char* name, char* tel, char* password);
//�����һ��������
void draw_forget(void);

#endif