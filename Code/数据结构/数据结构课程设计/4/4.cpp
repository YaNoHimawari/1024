/*
1.�ȶ����ļ�1�ı�ͷ��д���ļ�3������getline�������ж�ȡ���ݲ�д���ļ�3�������ļ�1����ļ�2����ȡ�ļ�2��ͷ����д���ļ�3��֮�����ͬǰ�档
2.��ȡ�ļ�3��������ַ�������60��ѧ������д���ļ�4��
3.�Ƚ����ݶ�����򲢴�����stu�����У���stu��������ѡ������ð�����򣩣��������д���ļ���
4.��ͷ����stu�������˳����ҡ��ȶ�stu�������������ٽ����۰���ҡ�
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

void display()              //��ʾ����
{
    for(int i=0;i<length;++i)
    {
        cout << *(stu[i].sname) << "\t" << *(stu[i].sno);
        for(int j=0;j<3;++j)
            cout << "\t" << stu[i].grade[j];
        cout << endl;
    }
}

string read()                 //�����ļ�
{
    ifstream f1("3.txt");
    if(!f1)
    {
        cout <<"�ļ������ڣ�" << endl;
        return "";
    }
    string title;
    getline(f1,title);

    int num=0;
    string name;            //��������
    string no;             //����ѧ��
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

void sort1()                //ѡ������
{
    int sum[length]={0};        //�洢�ܷ�
    for(int i=0;i<length;++i)
        sum[i]+=stu[i].grade[0]+stu[i].grade[1]+stu[i].grade[2];

    for(int i=0;i<length-1;++i)
    {
        int maxindex=i;             //j��¼���ֵ�±�
        for(int j=maxindex;j<length;++j)
            if(sum[maxindex]<sum[j])
                maxindex=j;
        if(i!=maxindex)             //���н���
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

void sort2()        //ð������
{
    int sum[length]={0};        //�洢�ܷ�
    for(int i=0;i<length;++i)
        sum[i]+=stu[i].grade[0]+stu[i].grade[1]+stu[i].grade[2];

    int i=length-1;
    int index;        //ÿ��ѭ�����һ�ν������±�
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

void search1(string name)           //˳�����
{
    bool b=false;                   //�ж��Ƿ���ҳɹ�
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
        cout << "����ʧ�ܣ�" << endl;
}

void search2(string name)               //�۰���ҷ�
{
    //�ȶ�������������
    int i=length-1;
    int index;        //ÿ��ѭ�����һ�ν������±�
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
    //����
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
        else if(name<*(stu[t].sname))   //�����
            high=t-1;
        else                            //���ұ�
            low=t+1;
    }
    if(!b)
        cout << "����ʧ�ܣ�" << endl;
}

void q1()
{
    ifstream f1("1.txt");
    ifstream f2("2.txt");
    ofstream f3("3.txt");
    if(!f1||!f2)
    {
        cout <<"�ļ������ڣ�" << endl;
        return;
    }
    if(!f3)
	{
		cout<<"�����ļ�ʧ�ܣ�"<<endl;
		return;
	}
	string title;
    getline(f1,title);
    getline(f2,title);
    f3 << title << endl;            //д���ͷ
    string line;
    while (getline (f1, line))      //д���ļ�1
        f3 << line << endl;
    while (getline(f2,line))        //д���ļ�2
        f3 << line << endl;
    cout << "�ļ��ϲ��ɹ���" << endl;
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
        cout <<"�ļ���ȡ����" << endl;
        return;
    }
    if(!f2)
    {
        cout<<"�����ļ�ʧ�ܣ�"<<endl;
		return;
    }
    string title;
    getline(f1,title);
    f2 << title << endl;

    string name;            //��������
    while(f1 >> name)
    {
        string sno;         //����ѧ��
        int grade[3];       //����ɼ�
        bool b=false;
        f1 >> sno;
        for(int i=0;i<3;++i)
        {
            f1 >> grade[i];
            if(grade[i]<60)    b=true;      //�ж��Ƿ���Ҫ����
        }
        if(b)                               //����в�������д���ļ�
        {
            f2 << name << "\t" << sno;
            for(int i=0;i<3;++i)
                f2 << "\t" << grade[i];
            f2 << endl;
        }
    }
    f1.close();
    f2.close();
    cout << "�����ļ���4.txt���ɹ���" << endl;
}

void q3()
{
    string title=read();                     //�������ݣ����ر�ͷ
    cout << "����ǰ��" << endl << title << endl;
    display();
    sort1();                                //ѡ������
    //sort2();                              //ð������
    cout << "�����" << endl << title << endl;
    display();

    ofstream f("3.txt");
    if(!f)
    {
        cout << "д��ʧ�ܣ�" << endl;
        return;
    }
    //д���ļ�
    f << title << endl;
    for(int i=0;i<length;++i)
    {
        f << *(stu[i].sname) << "\t" << *(stu[i].sno);
        for(int j=0;j<3;++j)
            f << "\t" << stu[i].grade[j];
        f << endl;
    }
    f.close();
    cout << "����ɹ���" << endl;
}

void q4()
{
    string title=read();        //��������
    string name;
    cin >> name;
    //search1(name);            //˳�����
    //search2(name);            //�۰����
}

int main()
{
    q1();
    q2();
    q3();
    q4();
    return 0;
}
