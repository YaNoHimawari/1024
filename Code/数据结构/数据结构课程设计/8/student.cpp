/*
使用结构体储存学生数据，sub储存表头数据。
因为子函数数量众多，所以通过采用结构体指针数组pstu作为参数进行传递来提高效率。
排序采用冒泡排序，查找采用顺序查找。
插入找到插入位置后，原数据后移一位。
拷贝边读取边写入新文件。
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

void main_menu();       //主菜单
void search_menu();     //数据查询菜单
void sat_menu();        //数据统计菜单
int Key();              //密码函数
void xian();            //输出分割线
void sort(int b,int m); //排序函数，b：0为总分排序，1为学号排序，2为姓名排序 。m：0不输出排序 ，1输出排序
void sub_class(int s);  //课程等级百分比函数，s表示输出第s+1门课程的情况
void sub_sat();         //课程平均分
void save();            //数据储存
void load();            //数据导入
void change(int i);     //数据修改函数 ,i为修改数据的数组下标
void print();           //控制台输出
void add_menu();        //添加数据菜单
void insert();          //插入
void add();             //追加
void fcopy();           //拷贝

char sub[4][10]={'\0'};  //储存课程名称
char* psub=sub[0];
student* pstu[MAX_STUDENT];  //结构体指针数组，用于对结构体进行操作
int n=0,f=0;       //n为学生人数，f判断是否存在数据

void load()
{
	FILE* fp=NULL;
	int count=0,i;
	if((fp=fopen("student.dat","rb"))==NULL) return;  //如果没有数据文件，就返回
	//读取课程名
	for(i=0;i<4;++i)
	if(fread(psub+10*i,10*sizeof(char),1,fp)!=1)
	{
		printf("读入文件错误\n"); xian(); return;
	}
	//读取学生数据
	while(1)
	{
		pstu[count]=(student*)malloc(sizeof(student));
		if(fread(pstu[count],sizeof(student),1,fp)!=1)
        {
            if(feof(fp)) {fclose(fp); break;}
            printf("读入文件错误\n"); xian(); return;
        }
		++count; //计算读入数据组数 ，即学生个数
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
	    printf("密码：");
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
        {printf("密码正确！\n"); xian(); return 1;}
        else {printf("密码错误！\n"); ++t;}
    }

    printf("\n由于你多次输入密码错误，程序自动退出。\n"); getchar();
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
        printf("不存在数据！\n"); return;
    }
    printf("name\tnum\tsex\t%s\t%s\t%s\t%s\tsum\taverage\n",sub[0],sub[1],sub[2],sub[3]);
    for(int i=0;i<n;++i)
    printf("%-s\t%-ld\t%-d\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\n"
                ,pstu[i]->name,pstu[i]->number,pstu[i]->sex,pstu[i]->c1,pstu[i]->c2,pstu[i]->c3,pstu[i]->c4,pstu[i]->sum,pstu[i]->average);
}

void input()
{
	if(f)     //判断是否存在数据
	{
		printf("已拥有数据，是否重新输入？（Y为是，其他键为否）\n");
		char t=getchar(); getchar();
		if(toupper(t)!='Y') {xian(); return;}
	}

	r_input:
	int i;
	printf("班级人数：");
	scanf("%d",&n);
	getchar();
	if(n<1||n>MAX_STUDENT) {printf("输入人数异常,请重新输入!\n"); goto r_input;}

	//输入课程名称
	for(i=0;i<4;++i)
	{
		printf("课程%d名称：",i+1);
		gets(psub+10*i);
	}
	//输入学生数据
	printf("name\tnum\tsex\t%s\t%s\t%s\t%s\n",sub[0],sub[1],sub[2],sub[3]);
	for(i=0;i<n;i++)
	{
        pstu[i]=(student*)malloc(sizeof(student));
		scanf("%s %ld %d %lf %lf %lf %lf",pstu[i]->name,&pstu[i]->number,&pstu[i]->sex,&pstu[i]->c1,&pstu[i]->c2,&pstu[i]->c3,&pstu[i]->c4);
		pstu[i]->sum=pstu[i]->c1+pstu[i]->c2+pstu[i]->c3+pstu[i]->c4;
		pstu[i]->average=pstu[i]->sum/4.0;
	}
	getchar();
	printf("你已成功输入成绩！\n"); xian();

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
		//总分排序
	   if((pstu[j]->sum<pstu[j+1]->sum)&&(t==0))
	   {
		pt=pstu[j];
		pstu[j]=pstu[j+1];
		pstu[j+1]=pt;
	   }
	   //学号排序
	   if((pstu[j]->number<pstu[j+1]->number)&&(t==1))
	   {
	   	pt=pstu[j];
		pstu[j]=pstu[j+1];
		pstu[j+1]=pt;
	   }
	   //姓名排序
	   if((strcmp(pstu[j+1]->name,pstu[j]->name)>0)&&(t==2))
	   {
	   	pt=pstu[j];
		pstu[j]=pstu[j+1];
		pstu[j+1]=pt;
	   }
	}
	//排序输出部分
	if(m!=0)
	{
		char ch;
		sort:
	    printf("1.从小到大\t2.从大到小\t3.返回上一菜单\n");
	    scanf("%c",&ch); getchar();
	    if(ch=='1')
	    for(i=0;i<n/2;++i)
	    {pt=pstu[i]; pstu[i]=pstu[n-1-i]; pstu[n-1-i]=pt;}

	    if(ch=='3') return;
	    if((ch<'1')||(ch>'3')) {printf("请输入正确的选项！\n\n"); goto sort;}
        print();        //排序输出
	    xian();
	}
}

void change(int i)
{
	r_change:
	char ch;
	student* pt=NULL;
	printf("是否对此人的数据进行操作？\n1.修改数据\t2.删除数据\t3.返回上一菜单\n");
	ch=getchar(); getchar();

	if(ch=='1')
	{
		char key1;

		printf("请重新输入此人数据\n");
		printf("name\tnum\tsex\t%s\t%s\t%s\t%s\n",sub[0],sub[1],sub[2],sub[3]);
		printf("%-s\t%-ld\t%-d\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\n",pstu[i]->name,pstu[i]->number,pstu[i]->sex,pstu[i]->c1,pstu[i]->c2,pstu[i]->c3,pstu[i]->c4);

		pt=(student*)malloc(sizeof(student));
		scanf("%s %ld %d %lf %lf %lf %lf",pt->name,&pt->number,&pt->sex,&pt->c1,&pt->c2,&pt->c3,&pt->c4);
		getchar();
		printf("是否确认修改？(Y为是，其他按键为否)\n");

		key1=getchar(); getchar();
		if(toupper(key1)=='Y')
		{
			pt->sum=pt->c1+pt->c2+pt->c3+pt->c4;
		    pt->average=pt->sum/4.0;
		    free(pstu[i]);
		    pstu[i]=pt; pt=NULL;
		    printf("数据修改成功！\n");
		    xian();
		}
		else {xian(); return;}
	}
	else if(ch=='2')
	{
		char key2;
		printf("是否确认删除？(Y为是，其他按键为否)\n");
		key2=getchar(); getchar();
		if(toupper(key2)=='Y')
		{
			free(pstu[i]);
			printf("数据删除成功！\n");  xian();
			--n;                           //减少学生个数
			if(n<1) {f=0; return;}         //保证存在学生数据
			for(int j=i;j<n;++j)
			pstu[j]=pstu[j+1];
		}
		else {xian(); return;}
	}
	else if(ch=='3') {xian(); return;}
	else {printf("请输入正确的选项！\n\n"); goto r_change;}
}

void search1()                           //按姓名查询
{
	int i,f_n=-1;                       //f_n判断是否有此人
	char s[20];
	printf("姓名：");
	gets(s);
	for(i=0;i<n;++i)
	if(strcmp(s,pstu[i]->name)==0)
	{
		printf("%-s\t%-ld\t%-d\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\n\n"
	                                    ,pstu[i]->name,pstu[i]->number,pstu[i]->sex,pstu[i]->c1,pstu[i]->c2,pstu[i]->c3,pstu[i]->c4,pstu[i]->sum,pstu[i]->average);
	    f_n=i;
	}
	if(f_n==-1) {printf("查找不到此人，自动为你返回上一菜单。\n"); xian(); return;}
	else change(f_n);
}

void search2()                    //按学号查询
{
	int i,d,f_n=-1;
	printf("学号：");
	scanf("%d",&d); getchar();
	for(i=0;i<n;++i)
	if(d==pstu[i]->number)
	{
		printf("%-s\t%-ld\t%-d\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\n\n"
	                                    ,pstu[i]->name,pstu[i]->number,pstu[i]->sex,pstu[i]->c1,pstu[i]->c2,pstu[i]->c3,pstu[i]->c4,pstu[i]->sum,pstu[i]->average);
	    f_n=i;
	}
	if(f_n==-1) {printf("查找不到此人，自动为你返回上一菜单。\n"); xian(); return;}
	else change(f_n);
}

void search_menu()
{
	if(!f) {printf("不存在成绩数据，请先进行成绩输入！\n"); xian(); input();}
	r_search:
	printf("1.按姓名查询\t2.按学号查询\t3.返回主菜单\n");
	char ch = getchar(); getchar();
	switch (ch)
	{
	case '1':search1(); break;
	case '2':search2(); break;
	case '3':return;
	default:printf("请输入正确的选项！\n\n"); goto r_search;
	}
}

void sat_menu()
{
	if(!f) {printf("不存在成绩数据，请先进行成绩输入！\n"); xian(); input();}
	r_sat:
	printf("1.排序\t2.课程等级数据\t3.课程平均分\t4.返回主菜单\n");
	char ch = getchar();
	getchar();
	if (ch == '1')
	{
		r_sat1:
		printf("1.按总分排序\t2.按学号排序\t3.按姓名排序\t4.返回上一菜单\n");
		char c = getchar(); getchar();
		switch (c)
		{
		case '1':sort(0,1); break;
		case '2':sort(1,1); break;
		case '3':sort(2,1); break;
		case '4':goto r_sat; break;
		default:printf("请输入正确的选项！\n\n"); goto r_sat1;
		}
	}
	else if(ch=='2')
	{
		r_sat2:
	    printf("请从以下课程中选择：\n");
	    printf("1.%s\t2.%s\t3.%s\t4.%s\t5.返回上一菜单\n",sub[0],sub[1],sub[2],sub[3]);
	    char c=getchar(); getchar();
	    switch(c)
	    {
	    	case '1': sub_class(1); break;
	    	case '2': sub_class(2); break;
	    	case '3': sub_class(3); break;
	    	case '4': sub_class(4); break;
	    	case '5': goto r_sat; break;
	    	default: {printf("请输入正确的选项！\n"); goto r_sat2;}
	    }
	}
	else if(ch=='3') sub_sat();
	else if(ch=='4') {xian(); return;}
	else {printf("请输入正确的选项！\n\n"); goto r_sat;}
}

void sub_class(int s)
{
	int A=0,B=0,C=0,D=0,E=0,i;
	double grade[n];                     //建立数组储存成绩
	if(s==1) for(i=0;i<n;++i) grade[i]=pstu[i]->c1;
	else if(s==2) for(i=0;i<n;++i) grade[i]=pstu[i]->c2;
	else if(s==3) for(i=0;i<n;++i) grade[i]=pstu[i]->c3;
	else if(s==4) for(i=0;i<n;++i) grade[i]=pstu[i]->c4;
	//等级统计
	for(i=0;i<n;++i)
	{
		if(grade[i]>=90.0) ++A;
		else if(grade[i]>=80.0) ++B;
		else if(grade[i]>=70.0) ++C;
		else if(grade[i]>=60.0) ++D;
		else ++E;
	}
	printf("等级\t人数\t百分比\n");
	printf("A\t%d\t%.2lf%%\n",A,A*100.0/n);
	printf("B\t%d\t%.2lf%%\n",B,B*100.0/n);
	printf("C\t%d\t%.2lf%%\n",C,C*100.0/n);
	printf("D\t%d\t%.2lf%%\n",D,D*100.0/n);
	printf("E\t%d\t%.2lf%%\n",E,E*100.0/n);
	xian();
}

void sub_sat()
{
	double sub_sum[4]={0.0};   //建立数组储存课程成绩总和
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
	{printf("数据导出错误\n"); return;}
	//储存课程名称
	for(i=0;i<4;++i)
	if(fwrite(psub+10*i,10*sizeof(char),1,fp)!=1)
	{printf("数据导出错误\n"); return;}
	//储存学生数据
	for(i=0;i<n;++i)
		if(fwrite(pstu[i],sizeof(student),1,fp)!=1)
	    {printf("数据导出错误\n"); return;}
	fclose(fp);
}

void add_menu()
{
    if(!f) {printf("不存在成绩数据，请先进行成绩输入！\n"); xian(); input();}
	r_add:
	printf("1.插入成绩\t2.追加成绩\t3.返回主菜单\n");
	char ch = getchar(); getchar();
	switch (ch)
	{
	case '1':insert(); break;
	case '2':add(); break;
	case '3':return;
	default:printf("请输入正确的选项！\n\n"); goto r_add;
	}
}

void insert()
{
    print();
    printf("输入插入位置:");
    int index;
    scanf("%d",&index);
    char key;
    student* pt=(student*)malloc(sizeof(student));
    printf("输入要插入的数据\n");
    printf("name\tnum\tsex\t%s\t%s\t%s\t%s\n",sub[0],sub[1],sub[2],sub[3]);
    scanf("%s %ld %d %lf %lf %lf %lf",pt->name,&pt->number,&pt->sex,&pt->c1,&pt->c2,&pt->c3,&pt->c4);
    getchar();
    printf("是否确认插入？(Y为是，其他按键为否)\n");

    key=getchar(); getchar();
    if(toupper(key)=='Y')
    {
        pt->sum=pt->c1+pt->c2+pt->c3+pt->c4;
        pt->average=pt->sum/4.0;
        for(int i=n;i>index-1;--i)
            pstu[i]=pstu[i-1];
        pstu[index-1]=pt;
        ++n;
        printf("数据插入成功！\n");
        print();
        xian();
    }
    else {xian(); return;}
}

void add()
{
    char key;
    student* pt=(student*)malloc(sizeof(student));
    printf("请输入要追加的数据\n");
    printf("name\tnum\tsex\t%s\t%s\t%s\t%s\n",sub[0],sub[1],sub[2],sub[3]);
    scanf("%s %ld %d %lf %lf %lf %lf",pt->name,&pt->number,&pt->sex,&pt->c1,&pt->c2,&pt->c3,&pt->c4);
    getchar();
    printf("是否确认追加？(Y为是，其他按键为否)\n");

    key=getchar(); getchar();
    if(toupper(key)=='Y')
    {
        pt->sum=pt->c1+pt->c2+pt->c3+pt->c4;
        pt->average=pt->sum/4.0;
        pstu[n]=pt;
        ++n;
        printf("数据追加成功！\n");
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
	    printf("文件不存在！\n"); return;     //如果没有数据文件，就返回
	}
	FILE* fp2=NULL;
	if((fp2=fopen("student_copy.dat","wb"))==NULL)
	{printf("数据导出错误\n"); return;}
	//储存课程名称
	for(int i=0;i<4;++i)
	if(fwrite(psub+10*i,10*sizeof(char),1,fp2)!=1)
	{printf("数据导出错误\n"); return;}
	//读取学生数据
	while(1)
	{
		student* pt=(student*)malloc(sizeof(student));
		if(fread(pt,sizeof(student),1,fp1)!=1)
        {
            if(feof(fp1)) {fclose(fp1); break;}
            printf("读入文件错误\n"); xian(); return;
        }
        //储存学生数据
        if(fwrite(pt,sizeof(student),1,fp2)!=1)
	    {printf("数据导出错误\n"); return;}
	    free(pt);
	}
	printf("拷贝成功！\n");
	fclose(fp2);
}

void main_menu()
{
		while(1)
	{
		printf("1.成绩输入\t2.成绩输出\t3.成绩查询\t4.成绩统计\t5.添加成绩\t6.文件拷贝\t7.退出系统\n");
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
			default:printf("请输入正确的选项！\n"); xian(); break;
		}
	}
}

int main()
{
	printf("成绩管理系统\n");
	if(Key())
	{
		load();
	    main_menu();
	    save();
	}

	return 0;
}
