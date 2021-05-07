#include"common.h"
#include"mouse.h"
#include"USER.h"
#include "file.h"
#include"menufunc.h"
#include"mpfunc.h"
#include "compare.h"

/*************************************************************
��������void inputfilename(char *site, int x1, int y1, int x2, int y2)
�������ַ������飬���뷶Χ����
����ֵ����
�������ܣ��ļ������뺯��
**************************************************************/
void EnterFileName(char*id, int x1, int y1, int charnum, int color)
//������ַ����������xy��������ַ����ƣ���������ɫ
{
	int k = 0;
	int i = 0;
	char t;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(RED);
	settextstyle(SMALL_FONT, HORIZ_DIR, 6);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	//���
	while(bioskey(1))
	{
		k = bioskey(0);
		//����
	}
	while (1)
	{
	
		t = bioskey(0); 
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)
				//Esc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 20); 
					//�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1+5, id + i);
					//���t�ַ�(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)
				//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 20);
					//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 20);
					//�ڸ�����
					i--;//����һ���ַ�?
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
					//���ƹ��
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 20);
				//�ڸǹ��
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)
				//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 20);
					//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 20);
					//�ڸ�����
					i--;
					//����һ���ַ�
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
					//���ƹ��
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 20);//�ڸǹ��  
				break;
			}
		}
	}
}

/*************************************************************
��������int Check_SameFile(char *newname, File *allfile, int n)  
�������ļ��� , �ļ��ṹ��ָ��,����
����ֵ��0��1
�������ܣ�����ļ��Ƿ�����
**************************************************************/
int Check_SameFile(char *newname, File *allfile, int n)  
 //����ļ��Ƿ�����
{
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(allfile[i].name, newname) == 0)
			return 1;
	}
	return 0;
}

/*************************************************************
��������int Examine_Filename(USER *u, File *allfile, char *newname)     
�������û��ṹ��ָ��, �ļ��ṹ��ָ��,�ļ���
����ֵ��0��1
�������ܣ�����ļ����
**************************************************************/
int Examine_Filename(USER *u, File *allfile, char *newname)   
//����ļ������
{ 
	while(1)
	{	
		if(Judge_Filename(newname, 480, 310) == 1)
		{
			if(u->history == 0)
			{
				return 1; 
				//����ʷ 
			}
			
			if(Check_SameFile(newname, allfile, u->history) == 1)
			{
				return 2; 
				//���� 
			}
			else
			{
				if(u->history == 10)
				{
					puthz(480, 315, "������ļ���",16, 17, RED);
					break; 
				}
				else
				{
					return 3;
					//����ʷ������ 
				}
			}
		}
		else
			break;
	}
	return 0; 
}

/*************************************************************
��������int Judge_Filename(char *name, int x, int y)
�������ļ���,����λ��
����ֵ��0��1
�������ܣ�����ļ����
**************************************************************/
int Judge_Filename(char *name, int x, int y)
{
	if(strlen(name) > 6)
	{
		puthz(x,y,"�ļ���ӦС����λ",16,17,RED);
		return 0;
	}
	if(strlen(name) == 0)
	{
		puthz(x,y,"�ļ�������Ϊ��",16,17,RED);
		return 0;
	}
	else if((strlen(name) <= 6 ) && (strlen(name) != 6 ))
	{
		return 1;
	}
	return 0;
}

/*************************************************************
��������void createfolder(char *name) 
�������ļ���
����ֵ����
�������ܣ������û��ļ���
**************************************************************/
void createfolder(char *name) 
 //�����û��ļ���
{
	char path[50]= {".\\file\\"};
	strcat(path, name);
	mkdir(path);
	//������Ŀ¼
}

/*************************************************************
��������void Insert_filemenu(File *allfile, char *filename, int format, int n)  
�������ļ��ṹ��ָ��,�ļ���,�ļ���ʽ��Ϣ,����
����ֵ����
�������ܣ������ļ���������
**************************************************************/
void Insert_filemenu(File *allfile, char *filename, int format, int n)  

{
	int i,j;
	int k;
	File temp;
	//�õ����µ��ļ���Ϣ
	strcpy(allfile[n-1].name, filename);
	allfile[n-1].format = format;
	//��ȡ�ļ�����ʱ��
	Get_filetime(allfile[n-1].filetime);
	k = strlen(allfile[n-1].filetime);
	allfile[n-1].filetime[k-1] = '\0';
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			//����
			if(strcmp(allfile[j].name,allfile[j+1].name) > 0)
			{
				temp = allfile[j];
				allfile[j] = allfile[j+1];
				allfile[j+1] = temp;
			}
		}
	}
}

/*************************************************************
��������void Input_filemenu(File *allfile, char *u)  
�������ļ��ṹ��ָ��,�û���
����ֵ����
�������ܣ������ļ�Ŀ¼
**************************************************************/
void Input_filemenu(File *allfile, char *u)  
 
{
	int i;
	FILE *fp;
	
	char mpath[25]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(mpath,u);
	strcat(mpath,fenge);
	strcat(mpath,"m_");
	strcat(mpath,u);
	strcat(mpath,".dat");

	if((fp = fopen(mpath, "wb+")) == NULL)
	{
		printf("can not open mfile");
		delay(2000);
		
	}
	
	for(i=0; i<FILEMAX; i++)
	{
		fwrite(&allfile[i], sizeof(File), 1, fp);
	}
	if(fclose(fp) != 0)
	{
		printf("\n cannot close mfile");
		delay(2000);
		exit(1);
	}
}

void Drawpoint(int x, int y)  
//����
{
	setfillstyle(1,WHITE);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(BLUE);
	circle(x,y,2);
}

/*************************************************************
��������void Output_Filemenu(File *allfile, char *u)   
�������ļ��ṹ��ָ��,�û���
����ֵ����
�������ܣ������ļ�Ŀ¼
**************************************************************/
void Output_Filemenu(File *allfile, char *u)   
//�����ļ�Ŀ¼
{
	int i;
	FILE *fp;
	
	char mpath[25]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(mpath,u);
	strcat(mpath,fenge);
	strcat(mpath,"m_");
	strcat(mpath,u);
	strcat(mpath,".dat");

	if((fp = fopen(mpath, "rb")) == NULL)
	{
		printf("can not open mfile");
		delay(2000);
	
	}
	fseek(fp, 0, SEEK_SET);
	for(i=0; i<FILEMAX; i++)
	{
		fread(&allfile[i], sizeof(File), 1, fp);
	}
	
	if(fclose(fp) != 0)
	{
		printf("\n cannot close mfile");
		delay(2000);
		exit(1);
	}

}

/*************************************************************
��������void printt_Filemenu(File *allfile, char *u)   
�������ļ��ṹ��ָ��,�û���
����ֵ����
�������ܣ���ӡ�ļ�Ŀ¼
**************************************************************/
void Print_Filemenu(File *allfile, int n)   //��ӡ�ļ�Ŀ¼
{
	int i;
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	//����Ϊ���ޣ�����������
	if(n<=5)
	{
		for(i=0;i<n;i++)
		{
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
			//����
			Drawpoint(90, 100+10+40*i);
			//����ļ���
			outtextxy(105, 100+40*i, allfile[i].name);
			//�����ʽ
			switch(allfile[i].format)
			{
				case 1:
					puthz(90+165, 100+5+40*i,"��ʽһ",16,17,BLUE);
					break;
				case 2:
					puthz(90+165, 100+5+40*i,"��ʽ��",16,17,BLUE);
					break;
				case 3:
					puthz(90+165, 100+5+40*i,"�Ա�",16,17,BLUE);
					break;
			}
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			outtextxy(105+10, 100+25+40*i, allfile[i].filetime);
		}
	}
	else if(n>5)
	{
		for(i=0;i<5;i++)
		{
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
			//����
			Drawpoint(90, 100+10+40*i);
			//����ļ���
			outtextxy(105, 100+40*i, allfile[i].name);
			//�����ʽ
			switch(allfile[i].format)
			{
				case 1:
					puthz(90+165, 100+5+40*i,"��ʽһ",16,17,BLUE);
					break;
				case 2:
					puthz(90+165, 100+5+40*i,"��ʽ��",16,17,BLUE);
					break;
				case 3:
					puthz(90+165, 100+5+40*i,"��ʽ��",16,17,BLUE);
					break;
			}
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			outtextxy(105+10, 100+25+40*i, allfile[i].filetime);
		}
		for(i=5;i<n;i++)
		{
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
			Drawpoint(330, 100+10+40*(i-5));
			outtextxy(345, 100+40*(i-5), allfile[i].name);
			switch(allfile[i].format)
			{
				case 1:
					puthz(330+165, 100+5+40*(i-5),"��ʽһ",16,17,BLUE);
					break;
				case 2:
					puthz(330+165, 100+5+40*(i-5),"��ʽ��",16,17,BLUE);
					break;
				case 3:
					puthz(330+165, 100+5+40*(i-5),"��ʽ��",16,17,BLUE);
					break;
			}
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			outtextxy(345+10, 100+25+40*(i-5), allfile[i].filetime);
		}
	}
}
/*************************************************************
��������void Get_filetime(char *filetime)    
�������ļ���
����ֵ����
�������ܣ���ȡ��ǰʱ��
**************************************************************/
void Get_filetime(char *filetime)   
//��ȡ��ǰʱ��
{
	time_t timer;
	struct tm *tblock;
	timer = time(NULL);
	tblock = localtime(&timer);
	strcpy(filetime, asctime(tblock));
}

/*************************************************************
��������void Input_filedata( char *u , struct mpdata *mp,char *filename)   
�������û���,�ṹ��ָ��,�ļ���
����ֵ����
�������ܣ������ļ�
**************************************************************/
void Input_filedata( char *u , struct mpdata *mp,char *filename)   
 //���û�˼ά��ͼ���ݴ����ļ�
{
	int i,j;
	FILE *fp;
	char copath[50]= {".\\file\\"};
	char fpath[50]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(copath,u);
	strcat(copath,fenge);
	strcat(copath,"draw_");
	strcat(copath,filename);
	strcat(copath,".dat");
	strcat(fpath,u);
	strcat(fpath,fenge);
	strcat(fpath,"data_");
	strcat(fpath,filename);
	strcat(fpath,".dat");
	if((fp = fopen(copath, "wb")) == NULL)
	{
		printf("can not open drawfile");
		delay(2000);
	
	}
		for(i=0;i<5;i++)
	{
		for(j=0; j<6; j++)
		{
			fwrite(&mp->text[i][j],sizeof(struct bardata),1,fp);
		}
	}

	for(i=0; i< 40; i++)
	{
		fwrite(&mp->connect[i],sizeof(struct linedata),1,fp);
	}
	
	for(i=0;i<5;i++)
	{
		fwrite(&mp->amoofson[i],2,1,fp);
	}

	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
	
	if((fp = fopen(fpath,"wb")) == NULL)
	{
		printf("can not open ffile");
		delay(2000);
		
	}
		fwrite(&mp->amooflevel,2,1,fp);
		fwrite(&mp->amoofline,2,1,fp);
	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
}


/*************************************************************
��������void Input_data(char *u , struct mpdata *mp)  
�������û���,�ṹ��ָ��
����ֵ����
�������ܣ������ļ�
**************************************************************/
void Input_data(char *u , struct mpdata *mp)
{
	int i,j;
	FILE *fp;
	char copath[50]= {".\\file\\"};
	char fpath[50]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(copath,u);
	strcat(copath,fenge);
	strcat(copath,"draw_");
	strcat(copath,u);
	strcat(copath,".dat");
	strcat(fpath,u);
	strcat(fpath,fenge);
	strcat(fpath,"data_");
	strcat(fpath,u);
	strcat(fpath,".dat");
	if((fp = fopen(copath, "wb")) == NULL)
	{
		printf("can not open drawfile");
		delay(2000);
	
	}
	for(i=0;i<5;i++)
	{
		for(j=0; j<6; j++)
		{
			fwrite(&mp->text[i][j],sizeof(struct bardata),1,fp);
		}
	}

	for(i=0; i< 40; i++)
	{
		fwrite(&mp->connect[i],sizeof(struct linedata),1,fp);
	}
	
	for(i=0;i<5;i++)
	{
		fwrite(&mp->amoofson[i],2,1,fp);
	}
	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
	
	if((fp = fopen(fpath,"wb")) == NULL)
	{
		printf("can not open datafile");
		delay(2000);
	
	}
		fwrite(&mp->amooflevel,2,1,fp);
		fwrite(&mp->amoofline,2,1,fp);
	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
}

/*************************************************************
��������void Outputdata(char *u ,struct mpdata *mp)   
�������û���,�ṹ��ָ��
����ֵ����
�������ܣ������ļ�
**************************************************************/
void Outputdata(char *u ,struct mpdata *mp)   
//���û�˼ά��ͼ���ݴ��ļ��д���
{
	int i=0,j=0;
	FILE *fp;
	char copath[50]= {".\\file\\"};
	char fpath[50]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(copath,u);
	strcat(copath,fenge);
	strcat(copath,"draw_");
	strcat(copath,u);
	strcat(copath,".dat");
	strcat(fpath,u);
	strcat(fpath,fenge);
	strcat(fpath,"data_");
	strcat(fpath,u);
	strcat(fpath,".dat");
	
	if((fp = fopen(copath, "rb")) == NULL)
	{
		printf("can not open drawfile");
		delay(2000);
	
	}
	fseek(fp, 0, SEEK_SET);
	for(i=0;i<5;i++)
	{
		for(j=0; j<6; j++)
		{
			fread(&mp->text[i][j],sizeof(struct bardata),1,fp);
		}
	}

	for(i=0; i< 40; i++)
	{
		fread(&mp->connect[i],sizeof(struct linedata),1,fp);
	}
	
	for(i=0;i<5;i++)
	{
		fread(&mp->amoofson[i],2,1,fp);
	}
	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
	
	if((fp = fopen(fpath,"rb")) == NULL)
	{
		printf("can not open ffile");
		delay(2000);
	
	}

	fread(&mp->amooflevel,2,1,fp);
	fread(&mp->amoofline,2,1,fp);

	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
}



/*********************************************
������:void inputtofile(char* name, char* tel, char* password)
���ܣ����û�ע����Ϣд���ļ�
����:name,id,code
����ֵ:1/0
***********************************************/
void inputtofile(char* name, char* tel, char* password)
{
	FILE* fp;
	USER* u;
	char n;
	if ((fp = fopen(".\\USERS\\userdata.dat", "wb+" )) == NULL)
	//�������ݿ�
	{
		printf("cannot open file userdata.txt");
		delay(3000);
	
	}
	if ((u = (USER*)malloc(sizeof(USER))) == NULL)
	{
		printf("memoryallocation runs wrong in lgfunc.c");
		delay(3000);
	
	}
	memset(u,'\0',sizeof(USER));
	strcpy(u->user, name);
	strcpy(u->tel, tel);
	strcpy(u->password, password);
	fseek(fp, 0, SEEK_END);
	//��ת���ļ�ĩβ
	fwrite(u, sizeof(USER), 1, fp);
	//���û���Ϣд��
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
}

/*************************************************************
��������int Copy_infor_User(USER *user)  
�������û�ָ��
����ֵ��0,1
�������ܣ������ݿ����û���Ϣ����ָ��
**************************************************************/
int Copy_infor_User(USER *user)    

{
	int i;
	int num;
	FILE *fp;
	USER *p = NULL;
	if((fp = fopen(".\\USERS\\userdata.dat","rb")) == NULL) //���û����ݿ�
	{
		printf("File UserData.dat cannot be open");
		delay(2000);
	
	}
	fseek(fp, 0, SEEK_END);
	num = ftell(fp) / sizeof(USER);
	//�����û�����
	for(i = 0; i < num; i++)
	{
		if((p = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("not enough memory for userfunc.c8");
			delay(2000);
			
		}
		fseek(fp, i*sizeof(USER), SEEK_SET);
		//���û���Ϣ����ָ��
		fread(p, sizeof(USER), 1, fp);
		if(strcmp(p->user, user->user) == 0)
		{
			memset(user, '\0', sizeof(USER)); 
			 //����
			strcpy(user->user,p->user);
			strcpy(user->password,p->password);
			strcpy(user->tel,p->tel);
			user->history = p->history;
			user->format = p->format;
			user->num = p->num;
			if(p != NULL)
			{
				free(p);
				p = NULL;
			}
			if(fclose(fp) != 0)
			{
				printf("\n cannot close UserData.dat");
				delay(2000);
				exit(1);
			}
			return 1;
		}
		if (p != NULL)
		{
			free(p);
			p = NULL;
		}
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	if(fclose(fp) != 0)
	{
		printf("\n cannot close UserData.dat");
		delay(2000);
		exit(1);
	}
	return 0;
}



/*************************************************************
��������void Delete_filedata(char *u, char *filename)  
�������û���,�ļ���
����ֵ����
�������ܣ�ɾ���ļ�����
**************************************************************/
void Delete_filedata(char *u, char *filename)  
 //ɾ���ļ�����
{
	char copath[50]= {".\\file\\"};
	char fpath[50]=  {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(copath,u);
	strcat(copath,fenge);
	strcat(copath,"draw_");
	strcat(copath,filename);
	strcat(copath,".dat");
	strcat(fpath,u);
	strcat(fpath,fenge);
	strcat(fpath,"data_");
	strcat(fpath,filename);
	strcat(fpath,".dat");
	
	if(remove(copath) == -1)
	//ɾ���ļ�����
	{
		printf("can not delete");
		delay(2000);
		
	}
		
	if(remove(fpath) == -1)
	//ɾ���ļ�����
	{
		printf("can not delete");
		delay(2000);
		
	}
}

/*************************************************************
��������void Delete_filename(File *allfile, char *filename, int n)    
�������ļ��ṹ��ָ��,�ļ���,����
����ֵ����
�������ܣ�ɾ���ļ�Ŀ¼�����Ϣ
**************************************************************/
void Delete_filename(File *allfile, char *filename, int n)   
//ɾ���ļ�Ŀ¼�е��ļ���Ϣ
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(strcmp(allfile[i].name, filename) == 0)
			break;
	}
	if(i==n-1)
	{
		memset(&allfile[i],'\0',sizeof(File));
		return;
	}
	else
	{
		for(j=i ; j<n-1 ; j++)
		{
			allfile[j] = allfile[j+1];
		}
		memset(&allfile[n-1],'\0',sizeof(File));
		return;
	}
}




/*************************************************************
��������void Output_File(char *u ,struct mpdata *mp,char * filename)     
�������û������ṹ��ָ��,�ļ���
����ֵ����
�������ܣ���ָ���ļ���������
**************************************************************/

void Output_File(char *u ,struct mpdata *mp,char * filename)   
//��ָ��˼ά��ͼ���ݴ��ļ��д���
{
	int i=0,j=0;
	FILE *fp;
	char copath[50]= {".\\file\\"};
	char fpath[50]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(copath,u);
	strcat(copath,fenge);
	strcat(copath,"draw_");
	strcat(copath,filename);
	strcat(copath,".dat");
	strcat(fpath,u);
	strcat(fpath,fenge);
	strcat(fpath,"data_");
	strcat(fpath,filename);
	strcat(fpath,".dat");
	
	
	if((fp = fopen(copath, "rb")) == NULL)
	{
		printf("can not open drawfile");
		delay(2000);
	
	}
	fseek(fp, 0, SEEK_SET);
	for(i=0;i<5;i++)
	{
		for(j=0; j<6; j++)
		{
			fread(&mp->text[i][j],sizeof(struct bardata),1,fp);
		}
	}

	for(i=0; i< 40; i++)
	{
		fread(&mp->connect[i],sizeof(struct linedata),1,fp);
	}
	
	for(i=0;i<5;i++)
	{
		fread(&mp->amoofson[i],2,1,fp);
	}
	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
	
	if((fp = fopen(fpath,"rb")) == NULL)
	{
		printf("can not open ffile");
		delay(2000);
		
	}

	fread(&mp->amooflevel,2,1,fp);
	fread(&mp->amoofline,2,1,fp);

	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
}

/*************************************************************
��������void Output_CFile(char *u ,struct mpdata *mp,char * filename)     
�������û������ṹ��ָ��,�ļ���
����ֵ����
�������ܣ���ָ���ļ���������
**************************************************************/
void Output_Cfile(char *u ,struct comparedata *CMP,char * filename)
//��ָ��˼ά��ͼ���ݴ��ļ��д���
{
	int i=0,j=0;
	FILE *fp;
	char copath[50]= {".\\file\\"};
	char fpath[50]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(copath,u);
	strcat(copath,fenge);
	strcat(copath,"draw_");
	strcat(copath,filename);
	strcat(copath,".dat");
	strcat(fpath,u);
	strcat(fpath,fenge);
	strcat(fpath,"data_");
	strcat(fpath,filename);
	strcat(fpath,".dat");
	
	
	if((fp = fopen(copath, "rb")) == NULL)
	{
		printf("can not open drawfile");
		delay(2000);
	
	}
	fseek(fp, 0, SEEK_SET);
    fread((*CMP).theme,2*18*sizeof(char),1,fp);
	fread((*CMP).similar,6*20*sizeof(char),1,fp);
	fread((*CMP).differ1,6*20*sizeof(char),1,fp);
    fread((*CMP).differ2,6*20*sizeof(char),1,fp);
    

	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
	
	if((fp = fopen(fpath,"rb")) == NULL)
	{
		printf("can not open ffile");
		delay(2000);
		exit(1);
	}
		fread(&(*CMP).si_num,2,1,fp);
		fread(&(*CMP).dif1_num,2,1,fp);
        fread(&(*CMP).dif2_num,2,1,fp);
	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
    fclose(fp);
}

