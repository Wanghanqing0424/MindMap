#ifndef _mouse_h_
#define _mouse_h_
//�ж��������
int mouse_press(int x1, int y1, int x2, int y2);
//����ͬ��̬�����
void mouse(int,int);
//����ʼ��
void mouseinit(void);
//
void mread(int *,int *,int*);
//����걳��
void save_bk_mou(int x,int y);
//������
void clrmous(int x,int y);
//�����
void drawmous(int x,int y);
//���״̬�����仯��������
void newmouse(int *nx,int *ny,int *nbuttons);   
//�ж������Բ
int mouse_presscircle(int x, int y, int r);

int mouse_pressother(int x1,int y1,int x2,int y2);

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;
extern union REGS regs;
#endif
