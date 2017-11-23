/*
ʹ�ýṹ�崢��ѧ�����ݣ�sub�����ͷ���ݡ�
��Ϊ�Ӻ��������ڶ࣬����ͨ�����ýṹ��ָ������pstu��Ϊ�������д��������Ч�ʡ�
�������ð�����򣬲��Ҳ���˳����ҡ�
�����ҵ�����λ�ú�ԭ���ݺ���һλ��
�����߶�ȡ��д�����ļ���
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#define MAX_STUDENT 100

struct student{
	long number;
	char name[20];
	int sex;
	double c1;
	double c2;
	double c3;
	double c4;
	double sum;
	double average;
};

typedef struct student student;

void main_menu();       //���˵�
void search_menu();     //���ݲ�ѯ�˵�
void sat_menu();        //����ͳ�Ʋ˵�
int Key();              //���뺯��
void xian();            //����ָ���
void sort(int b,int m); //��������b��0Ϊ�ܷ�����1Ϊѧ������2Ϊ�������� ��m��0��������� ��1�������
void sub_class(int s);  //�γ̵ȼ��ٷֱȺ�����s��ʾ�����s+1�ſγ̵����
void sub_sat();         //�γ�ƽ����
void save();            //���ݴ���
void load();            //���ݵ���
void change(int i);     //�����޸ĺ��� ,iΪ�޸����ݵ������±�
void print();           //����̨���
void add_menu();        //������ݲ˵�
void insert();          //����
void add();             //׷��
void fcopy();           //����

char sub[4][10]={'\0'};  //����γ�����
char* psub=sub[0];
student* pstu[MAX_STUDENT];  //�ṹ��ָ�����飬���ڶԽṹ����в���
int n=0,f=0;       //nΪѧ��������f�ж��Ƿ��������

void load()
{
	FILE* fp=NULL;
	int count=0,i;
	if((fp=fopen("student.dat","rb"))==NULL) return;  //���û�������ļ����ͷ���
	//��ȡ�γ���
	for(i=0;i<4;++i)
	if(fread(psub+10*i,10*sizeof(char),1,fp)!=1)
	{
		printf("�����ļ�����\n"); xian(); return;
	}
	//��ȡѧ������
	while(1)
	{
		pstu[count]=(student*)malloc(sizeof(student));
		if(fread(pstu[count],sizeof(student),1,fp)!=1)
        {
            if(feof(fp)) {fclose(fp); break;}
            printf("�����ļ�����\n"); xian(); return;
        }
		++count; //��������������� ����ѧ������
	}

	n=count;
	if(n) f=1;
}

int Key()
{
    char M[20]="student";
    char mima[20];
    int t=0;

    while(t<3)
    {
    	int count=0;
	    printf("���룺");
        while(mima[count]=getch())
        {
	        if(mima[count]=='\r') break;
	        if(mima[count]=='\b')
	    {
		    if(count>0)
	        {printf("\b \b"); count--;}
	         continue;
	    }
	        printf("*"); count++;
        }
        mima[count]='\0';
        printf("\n");

        if(strcmp(mima,M)==0)
        {printf("������ȷ��\n"); xian(); return 1;}
        else {printf("�������\n"); ++t;}
    }

    printf("\n������������������󣬳����Զ��˳���\n"); getchar();
    return 0;
}

void xian()
{
	printf("***********************************************************************************\n\n\n");
}

void print()
{
    if(f==0)
    {
        printf("���������ݣ�\n"); return;
    }
    printf("name\tnum\tsex\t%s\t%s\t%s\t%s\tsum\taverage\n",sub[0],sub[1],sub[2],sub[3]);
    for(int i=0;i<n;++i)
    printf("%-s\t%-ld\t%-d\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\n"
                ,pstu[i]->name,pstu[i]->number,pstu[i]->sex,pstu[i]->c1,pstu[i]->c2,pstu[i]->c3,pstu[i]->c4,pstu[i]->sum,pstu[i]->average);
}

void input()
{
	if(f)     //�ж��Ƿ��������
	{
		printf("��ӵ�����ݣ��Ƿ��������룿��YΪ�ǣ�������Ϊ��\n");
		char t=getchar(); getchar();
		if(toupper(t)!='Y') {xian(); return;}
	}

	r_input:
	int i;
	printf("�༶������");
	scanf("%d",&n);
	getchar();
	if(n<1||n>MAX_STUDENT) {printf("���������쳣,����������!\n"); goto r_input;}

	//����γ�����
	for(i=0;i<4;++i)
	{
		printf("�γ�%d���ƣ�",i+1);
		gets(psub+10*i);
	}
	//����ѧ������
	printf("name\tnum\tsex\t%s\t%s\t%s\t%s\n",sub[0],sub[1],sub[2],sub[3]);
	for(i=0;i<n;i++)
	{
        pstu[i]=(student*)malloc(sizeof(student));
		scanf("%s %ld %d %lf %lf %lf %lf",pstu[i]->name,&pstu[i]->number,&pstu[i]->sex,&pstu[i]->c1,&pstu[i]->c2,&pstu[i]->c3,&pstu[i]->c4);
		pstu[i]->sum=pstu[i]->c1+pstu[i]->c2+pstu[i]->c3+pstu[i]->c4;
		pstu[i]->average=pstu[i]->sum/4.0;
	}
	getchar();
	printf("���ѳɹ�����ɼ���\n"); xian();

	save();
	f=1;
}

void sort(int t,int m)
{
	int i,j;
	student* pt=NULL;

	for(i=0;i<n-1;++i)
	for(j=0;j<n-i-1;++j)
	{
		//�ܷ�����
	   if((pstu[j]->sum<pstu[j+1]->sum)&&(t==0))
	   {
		pt=pstu[j];
		pstu[j]=pstu[j+1];
		pstu[j+1]=pt;
	   }
	   //ѧ������
	   if((pstu[j]->number<pstu[j+1]->number)&&(t==1))
	   {
	   	pt=pstu[j];
		pstu[j]=pstu[j+1];
		pstu[j+1]=pt;
	   }
	   //��������
	   if((strcmp(pstu[j+1]->name,pstu[j]->name)>0)&&(t==2))
	   {
	   	pt=pstu[j];
		pstu[j]=pstu[j+1];
		pstu[j+1]=pt;
	   }
	}
	//�����������
	if(m!=0)
	{
		char ch;
		sort:
	    printf("1.��С����\t2.�Ӵ�С\t3.������һ�˵�\n");
	    scanf("%c",&ch); getchar();
	    if(ch=='1')
	    for(i=0;i<n/2;++i)
	    {pt=pstu[i]; pstu[i]=pstu[n-1-i]; pstu[n-1-i]=pt;}

	    if(ch=='3') return;
	    if((ch<'1')||(ch>'3')) {printf("��������ȷ��ѡ�\n\n"); goto sort;}
        print();        //�������
	    xian();
	}
}

void change(int i)
{
	r_change:
	char ch;
	student* pt=NULL;
	printf("�Ƿ�Դ��˵����ݽ��в�����\n1.�޸�����\t2.ɾ������\t3.������һ�˵�\n");
	ch=getchar(); getchar();

	if(ch=='1')
	{
		char key1;

		printf("�����������������\n");
		printf("name\tnum\tsex\t%s\t%s\t%s\t%s\n",sub[0],sub[1],sub[2],sub[3]);
		printf("%-s\t%-ld\t%-d\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\n",pstu[i]->name,pstu[i]->number,pstu[i]->sex,pstu[i]->c1,pstu[i]->c2,pstu[i]->c3,pstu[i]->c4);

		pt=(student*)malloc(sizeof(student));
		scanf("%s %ld %d %lf %lf %lf %lf",pt->name,&pt->number,&pt->sex,&pt->c1,&pt->c2,&pt->c3,&pt->c4);
		getchar();
		printf("�Ƿ�ȷ���޸ģ�(YΪ�ǣ���������Ϊ��)\n");

		key1=getchar(); getchar();
		if(toupper(key1)=='Y')
		{
			pt->sum=pt->c1+pt->c2+pt->c3+pt->c4;
		    pt->average=pt->sum/4.0;
		    free(pstu[i]);
		    pstu[i]=pt; pt=NULL;
		    printf("�����޸ĳɹ���\n");
		    xian();
		}
		else {xian(); return;}
	}
	else if(ch=='2')
	{
		char key2;
		printf("�Ƿ�ȷ��ɾ����(YΪ�ǣ���������Ϊ��)\n");
		key2=getchar(); getchar();
		if(toupper(key2)=='Y')
		{
			free(pstu[i]);
			printf("����ɾ���ɹ���\n");  xian();
			--n;                           //����ѧ������
			if(n<1) {f=0; return;}         //��֤����ѧ������
			for(int j=i;j<n;++j)
			pstu[j]=pstu[j+1];
		}
		else {xian(); return;}
	}
	else if(ch=='3') {xian(); return;}
	else {printf("��������ȷ��ѡ�\n\n"); goto r_change;}
}

void search1()                           //��������ѯ
{
	int i,f_n=-1;                       //f_n�ж��Ƿ��д���
	char s[20];
	printf("������");
	gets(s);
	for(i=0;i<n;++i)
	if(strcmp(s,pstu[i]->name)==0)
	{
		printf("%-s\t%-ld\t%-d\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\n\n"
	                                    ,pstu[i]->name,pstu[i]->number,pstu[i]->sex,pstu[i]->c1,pstu[i]->c2,pstu[i]->c3,pstu[i]->c4,pstu[i]->sum,pstu[i]->average);
	    f_n=i;
	}
	if(f_n==-1) {printf("���Ҳ������ˣ��Զ�Ϊ�㷵����һ�˵���\n"); xian(); return;}
	else change(f_n);
}

void search2()                    //��ѧ�Ų�ѯ
{
	int i,d,f_n=-1;
	printf("ѧ�ţ�");
	scanf("%d",&d); getchar();
	for(i=0;i<n;++i)
	if(d==pstu[i]->number)
	{
		printf("%-s\t%-ld\t%-d\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\n\n"
	                                    ,pstu[i]->name,pstu[i]->number,pstu[i]->sex,pstu[i]->c1,pstu[i]->c2,pstu[i]->c3,pstu[i]->c4,pstu[i]->sum,pstu[i]->average);
	    f_n=i;
	}
	if(f_n==-1) {printf("���Ҳ������ˣ��Զ�Ϊ�㷵����һ�˵���\n"); xian(); return;}
	else change(f_n);
}

void search_menu()
{
	if(!f) {printf("�����ڳɼ����ݣ����Ƚ��гɼ����룡\n"); xian(); input();}
	r_search:
	printf("1.��������ѯ\t2.��ѧ�Ų�ѯ\t3.�������˵�\n");
	char ch = getchar(); getchar();
	switch (ch)
	{
	case '1':search1(); break;
	case '2':search2(); break;
	case '3':return;
	default:printf("��������ȷ��ѡ�\n\n"); goto r_search;
	}
}

void sat_menu()
{
	if(!f) {printf("�����ڳɼ����ݣ����Ƚ��гɼ����룡\n"); xian(); input();}
	r_sat:
	printf("1.����\t2.�γ̵ȼ�����\t3.�γ�ƽ����\t4.�������˵�\n");
	char ch = getchar();
	getchar();
	if (ch == '1')
	{
		r_sat1:
		printf("1.���ܷ�����\t2.��ѧ������\t3.����������\t4.������һ�˵�\n");
		char c = getchar(); getchar();
		switch (c)
		{
		case '1':sort(0,1); break;
		case '2':sort(1,1); break;
		case '3':sort(2,1); break;
		case '4':goto r_sat; break;
		default:printf("��������ȷ��ѡ�\n\n"); goto r_sat1;
		}
	}
	else if(ch=='2')
	{
		r_sat2:
	    printf("������¿γ���ѡ��\n");
	    printf("1.%s\t2.%s\t3.%s\t4.%s\t5.������һ�˵�\n",sub[0],sub[1],sub[2],sub[3]);
	    char c=getchar(); getchar();
	    switch(c)
	    {
	    	case '1': sub_class(1); break;
	    	case '2': sub_class(2); break;
	    	case '3': sub_class(3); break;
	    	case '4': sub_class(4); break;
	    	case '5': goto r_sat; break;
	    	default: {printf("��������ȷ��ѡ�\n"); goto r_sat2;}
	    }
	}
	else if(ch=='3') sub_sat();
	else if(ch=='4') {xian(); return;}
	else {printf("��������ȷ��ѡ�\n\n"); goto r_sat;}
}

void sub_class(int s)
{
	int A=0,B=0,C=0,D=0,E=0,i;
	double grade[n];                     //�������鴢��ɼ�
	if(s==1) for(i=0;i<n;++i) grade[i]=pstu[i]->c1;
	else if(s==2) for(i=0;i<n;++i) grade[i]=pstu[i]->c2;
	else if(s==3) for(i=0;i<n;++i) grade[i]=pstu[i]->c3;
	else if(s==4) for(i=0;i<n;++i) grade[i]=pstu[i]->c4;
	//�ȼ�ͳ��
	for(i=0;i<n;++i)
	{
		if(grade[i]>=90.0) ++A;
		else if(grade[i]>=80.0) ++B;
		else if(grade[i]>=70.0) ++C;
		else if(grade[i]>=60.0) ++D;
		else ++E;
	}
	printf("�ȼ�\t����\t�ٷֱ�\n");
	printf("A\t%d\t%.2lf%%\n",A,A*100.0/n);
	printf("B\t%d\t%.2lf%%\n",B,B*100.0/n);
	printf("C\t%d\t%.2lf%%\n",C,C*100.0/n);
	printf("D\t%d\t%.2lf%%\n",D,D*100.0/n);
	printf("E\t%d\t%.2lf%%\n",E,E*100.0/n);
	xian();
}

void sub_sat()
{
	double sub_sum[4]={0.0};   //�������鴢��γ̳ɼ��ܺ�
	int i;
	for(i=0;i<n;++i) sub_sum[0]+=pstu[i]->c1;
	for(i=0;i<n;++i) sub_sum[1]+=pstu[i]->c2;
	for(i=0;i<n;++i) sub_sum[2]+=pstu[i]->c3;
	for(i=0;i<n;++i) sub_sum[3]+=pstu[i]->c4;
	for(i=0;i<4;++i)
	{
		if(i) printf("\n");
		printf("%s:%.2lf",sub[i],sub_sum[i]/n);
	}
	printf("\n"); xian();
}

void save()
{
	int i;
	FILE* fp=NULL;
	if((fp=fopen("student.dat","wb"))==NULL)
	{printf("���ݵ�������\n"); return;}
	//����γ�����
	for(i=0;i<4;++i)
	if(fwrite(psub+10*i,10*sizeof(char),1,fp)!=1)
	{printf("���ݵ�������\n"); return;}
	//����ѧ������
	for(i=0;i<n;++i)
		if(fwrite(pstu[i],sizeof(student),1,fp)!=1)
	    {printf("���ݵ�������\n"); return;}
	fclose(fp);
}

void add_menu()
{
    if(!f) {printf("�����ڳɼ����ݣ����Ƚ��гɼ����룡\n"); xian(); input();}
	r_add:
	printf("1.����ɼ�\t2.׷�ӳɼ�\t3.�������˵�\n");
	char ch = getchar(); getchar();
	switch (ch)
	{
	case '1':insert(); break;
	case '2':add(); break;
	case '3':return;
	default:printf("��������ȷ��ѡ�\n\n"); goto r_add;
	}
}

void insert()
{
    print();
    printf("�������λ��:");
    int index;
    scanf("%d",&index);
    char key;
    student* pt=(student*)malloc(sizeof(student));
    printf("����Ҫ���������\n");
    printf("name\tnum\tsex\t%s\t%s\t%s\t%s\n",sub[0],sub[1],sub[2],sub[3]);
    scanf("%s %ld %d %lf %lf %lf %lf",pt->name,&pt->number,&pt->sex,&pt->c1,&pt->c2,&pt->c3,&pt->c4);
    getchar();
    printf("�Ƿ�ȷ�ϲ��룿(YΪ�ǣ���������Ϊ��)\n");

    key=getchar(); getchar();
    if(toupper(key)=='Y')
    {
        pt->sum=pt->c1+pt->c2+pt->c3+pt->c4;
        pt->average=pt->sum/4.0;
        for(int i=n;i>index-1;--i)
            pstu[i]=pstu[i-1];
        pstu[index-1]=pt;
        ++n;
        printf("���ݲ���ɹ���\n");
        print();
        xian();
    }
    else {xian(); return;}
}

void add()
{
    char key;
    student* pt=(student*)malloc(sizeof(student));
    printf("������Ҫ׷�ӵ�����\n");
    printf("name\tnum\tsex\t%s\t%s\t%s\t%s\n",sub[0],sub[1],sub[2],sub[3]);
    scanf("%s %ld %d %lf %lf %lf %lf",pt->name,&pt->number,&pt->sex,&pt->c1,&pt->c2,&pt->c3,&pt->c4);
    getchar();
    printf("�Ƿ�ȷ��׷�ӣ�(YΪ�ǣ���������Ϊ��)\n");

    key=getchar(); getchar();
    if(toupper(key)=='Y')
    {
        pt->sum=pt->c1+pt->c2+pt->c3+pt->c4;
        pt->average=pt->sum/4.0;
        pstu[n]=pt;
        ++n;
        printf("����׷�ӳɹ���\n");
        print();
        xian();
    }
    else {xian(); return;}
}

void fcopy()
{
    FILE* fp1=NULL;
	if((fp1=fopen("student.dat","rb"))==NULL)
	{
	    printf("�ļ������ڣ�\n"); return;     //���û�������ļ����ͷ���
	}
	FILE* fp2=NULL;
	if((fp2=fopen("student_copy.dat","wb"))==NULL)
	{printf("���ݵ�������\n"); return;}
	//����γ�����
	for(int i=0;i<4;++i)
	if(fwrite(psub+10*i,10*sizeof(char),1,fp2)!=1)
	{printf("���ݵ�������\n"); return;}
	//��ȡѧ������
	while(1)
	{
		student* pt=(student*)malloc(sizeof(student));
		if(fread(pt,sizeof(student),1,fp1)!=1)
        {
            if(feof(fp1)) {fclose(fp1); break;}
            printf("�����ļ�����\n"); xian(); return;
        }
        //����ѧ������
        if(fwrite(pt,sizeof(student),1,fp2)!=1)
	    {printf("���ݵ�������\n"); return;}
	    free(pt);
	}
	printf("�����ɹ���\n");
	fclose(fp2);
}

void main_menu()
{
		while(1)
	{
		printf("1.�ɼ�����\t2.�ɼ����\t3.�ɼ���ѯ\t4.�ɼ�ͳ��\t5.��ӳɼ�\t6.�ļ�����\t7.�˳�ϵͳ\n");
		char ch=getchar();
		getchar();
		if(ch=='7')  break;
			switch(ch)
		{
			case '1':input(); break;
			case '2':print(); xian(); break;
			case '3':search_menu(); break;
			case '4':sat_menu(); break;
			case '5':add_menu(); break;
			case '6':fcopy();   break;
			default:printf("��������ȷ��ѡ�\n"); xian(); break;
		}
	}
}

int main()
{
	printf("�ɼ�����ϵͳ\n");
	if(Key())
	{
		load();
	    main_menu();
	    save();
	}

	return 0;
}
