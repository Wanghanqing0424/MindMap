#include"common.h"
#include"forget.h"
#include"login.h"
#include"register.h"
#include"drawmenu.h"
#include"USER.h"
#include"mouse.h"
#include"save.h"
#include"history.h"
#include"help.h"
#include"menufunc.h"
#include"mpfunc.h"
#include "visitor.h"
#include "compare.h"
#include "communit.h"
#include"outline.h"

/*************************************************************
��������main()
��������
����ֵ����
�������ܣ��������ݽṹ,��ʼ��ͼ�ν���,��תҳ��
**************************************************************/	
void main()
{		
    int func=0;
    int statue = 0;
    int tate=3;
    int gm,gd;
    int judge=0;
    int MY,MX,BUTTON;
    //������������Ҫ�����ݽṹ
    struct mpdata mp;
    struct mpdata visitor;
    struct comparedata CMP; 
    COM zs;
    USER u;
	gm=VGA;
    gd=VGAHI;
    memset(&u,'\0',sizeof(USER));
    initgraph(&gm,&gd,".\\BORLANDC\\BGI");
    mouseinit();
    welcome();
    //��תҳ��
    while(1)
    {
        switch(func)
        {

            //��½ҳ��
		    case 0:
            Userslogin_func(&func,&u,&visitor,&judge);
            break;

            //ע��ҳ��
			case 1:
			zhuce_func(&func);
			break;
			
            //�һ�����ҳ��
			case 2:
			forget_func(&func);
			break;
			
            //ѡ��˼ά��ͼ��ʽҳ��
			case 3:
            select(&func,&mp,&statue,&u,judge,&tate);		
            break;
            
            //����ҳ��
            case 4:
			SaveFunc(&func,&u,&mp,statue);
            break;

            //��ʷҳ��
            case 5:
            History_Func(&func,&u,&mp,statue,&CMP);
            break;

            //����ҳ��
			case 6:
            Help_Func(&func,statue);
            break;

            //����ҳ��
            case 7:
            About_func(&func,statue);
            break;

            //��ʽ1��������
            case 8:
			menu_func(1,&func,&mp,&u);
			break;

            //��ʽ2��������
            case 9:
            menu_func(2,&func,&mp,&u);
            break;

            //�οͷ��ʵ�������
            case 10 :
            Visitor_Func(1,&func,&visitor);
            break;

            //�Ա�ģʽ��������
            case 11:
			comparefunc(&func,&u,&CMP,tate);
            break;
            
            //������������
            case 12:
            Community_func(&func,&u,&mp,&CMP);
            break;

            //
            case 13:
            DRAW(&func,&CMP);
            break;

            //��ʽ1�Ĵ��ģʽ
            case 14:
            outline_func(1, &func, mp);
            break;

            //��ʽ2�Ĵ��ģʽ
            case 15:
            outline_func(2, &func, mp);
            break;
        }
    }
    getch();
	closegraph();
}


