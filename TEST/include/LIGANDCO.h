#ifndef  _LIGHTANDCOVER_H__
#define  _LIGHTANDCOVER_H__
//�����ı���
void lightbutton_register(int x, int y, int x1, int y1, int color1, int color2, int flag);
//�ָ��ı���
void recoverbutton_register(int status);
//�����ı���
void light_login(int x, int y, int x1, int y1, int color1, int color2, int flag);
//��������
void lightbutton_tc(int x, int y, int x1, int y1, int color, int flag);
//�ָ�����
void recoverbutton_tc(void);
//�����������
void lightButton_Save(int n);
//������水ť�����ָ�
void RecoverButton_Save(int n);
//����������
void menu_z_recover(int yixin);
//�ָ�������
void light_menu_recover(int flag);
//�ָ��ӽ���
void light_menu(int flag);
//����
void cover(int x, int y,int color);
void cover_tips(int x, int y,int color);
void cover_TITLE(int x, int y,int color);
void cover_save(int x, int y,int color);

#endif