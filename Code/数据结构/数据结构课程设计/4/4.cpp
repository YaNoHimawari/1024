/*
1.先读入文件1的表头并写入文件3，再用getline函数逐行读取数据并写入文件3。读完文件1后读文件2，读取文件2表头但不写入文件3，之后操作同前面。
2.读取文件3，如果出现分数低于60的学生，就写入文件4。
3.先将数据读入程序并储存在stu数组中，对stu进行排序（选择排序，冒泡排序），排序完后写入文件。
4.从头遍历stu数组进行顺序查找。先对stu进行姓名排序，再进行折半查找。
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef struct student{
    string* sname;
    string* sno;
    int grade[3];
}student;
student stu[100];
int length=0;

void display()              //显示函数
{
    for(int i=0;i<length;++i)
    {
        cout << *(stu[i].sname) << "\t" << *(stu[i].sno);
        for(int j=0;j<3;++j)
            cout << "\t" << stu[i].grade[j];
        cout << endl;
    }
}

string read()                 //读入文件
{
    ifstream f1("3.txt");
    if(!f1)
    {
        cout <<"文件不存在！" << endl;
        return "";
    }
    string title;
    getline(f1,title);

    int num=0;
    string name;            //储存姓名
    string no;             //储存学号
    while(f1 >> name)
    {
        stu[num].sname=new string(name);
        f1 >> no;
        stu[num].sno=new string(no);
        for(int i=0;i<3;++i)
            f1 >> stu[num].grade[i];
        ++num;
    }
    length=num;
    return title;
}

void sort1()                //选择排序法
{
    int sum[length]={0};        //存储总分
    for(int i=0;i<length;++i)
        sum[i]+=stu[i].grade[0]+stu[i].grade[1]+stu[i].grade[2];

    for(int i=0;i<length-1;++i)
    {
        int maxindex=i;             //j记录最大值下标
        for(int j=maxindex;j<length;++j)
            if(sum[maxindex]<sum[j])
                maxindex=j;
        if(i!=maxindex)             //进行交换
        {
            int temp=sum[i];
            sum[i]=sum[maxindex];
            sum[maxindex]=temp;
            student st=stu[i];
            stu[i]=stu[maxindex];
            stu[maxindex]=st;
        }
    }
}

void sort2()        //冒泡排序法
{
    int sum[length]={0};        //存储总分
    for(int i=0;i<length;++i)
        sum[i]+=stu[i].grade[0]+stu[i].grade[1]+stu[i].grade[2];

    int i=length-1;
    int index;        //每次循环最后一次交换的下标
    while(i>0)
    {
        index=0;
        for(int j=0;j<i;++j)
            if(sum[j]<sum[j+1])
            {
                index=j;
                int temp=sum[j];
                sum[j]=sum[j+1];
                sum[j+1]=temp;
                student st=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=st;
            }
        i=index;
    }
}

void search1(string name)           //顺序查找
{
    bool b=false;                   //判断是否查找成功
    for(int i=0;i<length;++i)
        if(name==*(stu[i].sname))
        {
            cout << *(stu[i].sname) << "\t" << *(stu[i].sno);
            for(int j=0;j<3;++j)
                cout << "\t" << stu[i].grade[j];
            cout << endl;
            b=true;
            break;
        }
    if(!b)
        cout << "查找失败！" << endl;
}

void search2(string name)               //折半查找法
{
    //先对姓名进行排序
    int i=length-1;
    int index;        //每次循环最后一次交换的下标
    while(i>0)
    {
        index=0;
        for(int j=0;j<i;++j)
            if(*(stu[j].sname)>*(stu[j+1].sname))
            {
                index=j;
                student st=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=st;
            }
        i=index;
    }
    //查找
    int low=0,high=length;
    bool b=false;
    while(true)
    {
        int t=(low+high)/2;
        if(name==*(stu[t].sname))
        {
            cout << *(stu[t].sname) << "\t" << *(stu[t].sno);
            for(int j=0;j<3;++j)
                cout << "\t" << stu[t].grade[j];
            cout << endl;
            b=true;
            break;
        }
        else if(low==high)
            break;
        else if(name<*(stu[t].sname))   //在左边
            high=t-1;
        else                            //在右边
            low=t+1;
    }
    if(!b)
        cout << "查找失败！" << endl;
}

void q1()
{
    ifstream f1("1.txt");
    ifstream f2("2.txt");
    ofstream f3("3.txt");
    if(!f1||!f2)
    {
        cout <<"文件不存在！" << endl;
        return;
    }
    if(!f3)
	{
		cout<<"创建文件失败！"<<endl;
		return;
	}
	string title;
    getline(f1,title);
    getline(f2,title);
    f3 << title << endl;            //写入表头
    string line;
    while (getline (f1, line))      //写入文件1
        f3 << line << endl;
    while (getline(f2,line))        //写入文件2
        f3 << line << endl;
    cout << "文件合并成功！" << endl;
    f1.close();
    f2.close();
    f3.close();
}

void q2()
{
    ifstream f1("3.txt");
    ofstream f2("4.txt");
    if(!f1)
    {
        cout <<"文件读取错误！" << endl;
        return;
    }
    if(!f2)
    {
        cout<<"创建文件失败！"<<endl;
		return;
    }
    string title;
    getline(f1,title);
    f2 << title << endl;

    string name;            //储存姓名
    while(f1 >> name)
    {
        string sno;         //储存学号
        int grade[3];       //储存成绩
        bool b=false;
        f1 >> sno;
        for(int i=0;i<3;++i)
        {
            f1 >> grade[i];
            if(grade[i]<60)    b=true;      //判断是否需要补考
        }
        if(b)                               //如果有补考，则写入文件
        {
            f2 << name << "\t" << sno;
            for(int i=0;i<3;++i)
                f2 << "\t" << grade[i];
            f2 << endl;
        }
    }
    f1.close();
    f2.close();
    cout << "生成文件“4.txt”成功！" << endl;
}

void q3()
{
    string title=read();                     //读入数据，返回表头
    cout << "排序前：" << endl << title << endl;
    display();
    sort1();                                //选择排序
    //sort2();                              //冒泡排序
    cout << "排序后：" << endl << title << endl;
    display();

    ofstream f("3.txt");
    if(!f)
    {
        cout << "写入失败！" << endl;
        return;
    }
    //写入文件
    f << title << endl;
    for(int i=0;i<length;++i)
    {
        f << *(stu[i].sname) << "\t" << *(stu[i].sno);
        for(int j=0;j<3;++j)
            f << "\t" << stu[i].grade[j];
        f << endl;
    }
    f.close();
    cout << "排序成功！" << endl;
}

void q4()
{
    string title=read();        //读入数据
    string name;
    cin >> name;
    //search1(name);            //顺序查找
    //search2(name);            //折半查找
}

int main()
{
    q1();
    q2();
    q3();
    q4();
    return 0;
}
