#ifndef _MPFUNC_H__
#define _MPFUNC_H__



//�ı���
#define barlength 90
//�ı����
#define barwidth 30
//��϶��
#define spacewidth 30
//��϶��
#define spacelength 50
//��ʽ1�ĳ�ʼ������
#define initbarX1 5
#define initbarY1 237
//��ʽ2�ĳ�ʼ������
#define initbarX2 263
#define initbarY2 29
//�ı�������
struct bardata
{
	//������
	int barX;
	//������
	int barY;
	//�ı�����ɫ
	int barcolor;
	//������ɫ
	int hzcolor;
	//��ע״̬
	int starstate1;
	//��ע������״̬
	int starstate2;
	//���溺������
	char hz[32];
	//�ӿ����
	int num;
	//�۵�״̬
	int state;
	//�۵�����״̬
	int nodestate;
};
//�Զ������ߵ�����
struct linedata
{
	//������
	int flevel;
	int fnum;
	//�ӿ���
	int slevel;
	int snum;
	//�ߵ���ɫ
	int linecolor;
	//��ʾ״̬
	int state1;
	//�۵�״̬
	int state2;
};
//�û������ߵ�����
struct linkdata
{
	//������
	int flevel;
	int fnum;
	//�ӿ���
	int slevel;
	int snum;
	//��ʾ״̬
	int state1;
	//�۵�״̬
	int state2;
};
//˼ά��ͼ����
struct mpdata
{
	//��໭100����
	struct bardata text[10][10];
	//����Զ�����100����
	struct linedata connect[100];
	//�û������50����
	struct linkdata link[50];
	//ÿ��˼ά��ͼ���ӿ����
	int amoofson[10];
	//˼ά��ͼ����
	int amooflevel;
	//�Զ�����������
	int amoofline;
	//�û�����������
	int amooflink;
	//������ɫ
	int bkcolor;
};
//ѡ������ɾ�����ı���
void deletemp(int state, struct mpdata *mp);
//ѡ����������ı���ĸ���
void addmp(int state, struct mpdata *mp);
//��ʼ��˼ά��ͼ�ṹ�������
void initmp(int state, struct mpdata *mp);
//���¼�����������ı������ڲ����п������,����Զ����ɵ�������
void addrecord(int i, int j, int state, struct mpdata *mp);
//ɾ����ѡ�е��ı��������ı���
void deleterecord(int i, int j, struct mpdata *mp);
//�༭�ı�����������������
void mpinputhz(int state, struct mpdata *mp);
//��ӡ�����ı���ĺ���
void printhz(struct mpdata mp);
//���»�������������
void redrawline(int state, struct mpdata mp);
//���»��������ı���
void redrawbar(struct mpdata mp);
//��������ı���֮���������򣬷�ֹ���ֽ�����
void mpsort(int i, int j, struct mpdata *mp);
//���»��Ʊ�ע����
void redrawstar(struct mpdata mp);
//�ı��ע״̬
void starstate(int state, int i, int j, struct mpdata *mp);
//ѡ������ı��ע״̬���ı���
void changestar(int state, struct mpdata *mp);
//ʹ����˼ά��ͼ����
void mpup(int state, struct mpdata *mp);
//ʹ����˼ά��ͼ����
void mpdown(int state, struct mpdata *mp);
//ʹ����˼ά��ͼ����
void mpleft(int state, struct mpdata *mp);
//ʹ����˼ά��ͼ����
void mpright(int state, struct mpdata *mp);
//�����ݴ��뵽˼ά��ͼ�ṹ��
void linkinput(int state, int i, int j, struct mpdata *mp);
//ѡ����Ҫ�������ӵ��ı���
void mplink(int state, struct mpdata *mp);
//�ı��û����ߵ�״̬
void linkstate(int state, int flag, struct mpdata *mp);
//�ı�ѡ�п��ӿ���۵�״̬
void nodestate(int i, int j, struct mpdata *mp);
//ѡ����Ҫ�۵��Ŀ�
void mpnode(int state, struct mpdata *mp);
//�ָ��ı���������ߵ��۵�״̬
void recovernode(struct mpdata *mp);
//�����۵�����
void redrawnode(int state, struct mpdata mp);
#endif
