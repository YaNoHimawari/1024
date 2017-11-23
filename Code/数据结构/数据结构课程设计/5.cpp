/*
��ȡҪ��ȡ���ļ����ƣ�Ȼ��������ݴ���data�С�
ͳ��ÿ���ַ����ֵĴ�����c_count�У�c_count����Ϊ256���ַ������飬�ַ���ӦASCIIֵ��Ϊ�±꣬���־�++���顣
�Գ��ֵ��ַ�������㣬���ִ�����ΪȨֵ����������������
����������������ÿ���ַ���Ӧ�Ĺ������������pcode�ṹ���С�
��data���б������ù�������������ַ���
���������ݴ���t_code�У�����ö����Ʒ�ʽд��dat�ļ��С�
*/
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>

using namespace std;

//���
typedef struct point{
    char c;                 //����
    int weight;             //Ȩ
    int parent,lc,rc;       //���Һ���
}point;

//����������
typedef struct pcode{
    char c;
    string* code;           //���ݶ�Ӧ�Ĺ���������
}pcode;

//����Ӣ������
bool fread(string & data,char* filename)
{
    char s[20];
    //��ȡ�ļ���
    strcpy(s,filename);
    strcat(s,".txt");
    ifstream in(s);
    string line;

    if(!in)
    {
        cout <<"�ļ������ڣ�" << endl;
        return false;
    }

    data="";                        //���data
    while (getline (in, line))      // line�в�����ÿ�еĻ��з�
        data+=line+'\n';
    return true;                    //��ʾ����ɹ�
}

//ͳ���ַ����ָ���
int* c_count(const string & data)
{
    int* c_n=(int*)malloc(256*sizeof(int));     //c_n���ڴ���ÿ���ַ����ֵĴ���
    for(int i=0;i<256;++i)                      //��ʼ��c_n
        c_n[i]=0;

    for(int i=0;i<data.length();++i)
            ++c_n[(int)data.at(i)];
    return c_n;
}

//������������
bool select(point* & root,int n,int & s1,int & s2)
{
    bool first=true;                 //�ж��Ƿ�Ϊ��һ�δﵽ����
    for(int i=1;i<n;++i)
        if(root[i].parent==0)       //�ж��Ƿ��Ѽ����������
        {
            if(!first)
            {
                if(s1==s2)          //�ڶ��δﵽ����
                {
                    if(root[i].weight<root[s1].weight)
                    {
                        s2=s1;  s1=i;
                    }
                    else
                        s2=i;
                    continue;
                }
                else if(root[i].weight<=root[s1].weight)
                {
                    s2=s1;  s1=i;
                }
                else if(root[i].weight<=root[s2].weight)
                    s2=i;
            }
            else
            {
                s1=s2=i;    first=false;
            }
        }
    if(s1==s2) return false;
    if(root[s1].c==0 && root[s2].c!=0)                   // �½�������ұ�
    {
        int t=s1; s1=s2; s2=t;
    }
    return true;
}

point* setTree(int* c_n,int & len)
{
    len=0;
    point* root=(point*)malloc(256*sizeof(point));

    for(int i=0;i<256;++i)              //�������
        if(c_n[i])                      //ͳ���ַ������ಢ��ʼ�����
        {
            ++len;
            root[len].c=(char)i;
            root[len].lc=0;
            root[len].rc=0;
            root[len].parent=0;
            root[len].weight=c_n[i];
        }

    root=(point*)realloc(root,2*len*sizeof(point));     //���·����ڴ�
    for(int i=len+1;i<2*len;++i)
    {
        root[i].c=0;
        root[i].lc=0;
        root[i].rc=0;
        root[i].parent=0;
        root[i].weight=0;
    }

    int s1=1,s2=1;
    for(int i=len+1;i<2*len;++i)
    {
        if(select(root,i,s1,s2))
        {
            root[s1].parent=i;
            root[s2].parent=i;
            root[i].lc=s1;
            root[i].rc=s2;
            root[i].weight=root[s1].weight+root[s2].weight;
        }
        else break;
    }

    return root;
}

//���ɹ���������
pcode* Huffmancode(point* root,int len)
{

    pcode* HC=(pcode*)malloc((len+1)*sizeof(pcode));
    string stemp="";
    int p=2*len-1;
    int l=0;
    for(int i=0;i<=p;++i) root[i].weight=0;

    while(p)
    {
        if(root[p].weight==0)           //��һ�η��ʽ��
        {

            root[p].weight=1;
            if(root[p].lc!=0)
            {
                p=root[p].lc; stemp+='0';
            }
            else if(root[p].rc==0)
            {
                ++l;
                HC[l].c=root[p].c;
                HC[l].code=new string(stemp);
            }
        }
        else if(root[p].weight==1)      //�ڶ��η��ʽ��
        {
            root[p].weight=2;
            if(root[p].rc!=0)
            {
                p=root[p].rc;
                stemp+='1';
            }
        }
        else{                           //�����η��ʽ��
            root[p].weight=0;
            p=root[p].parent;
            stemp = stemp.substr(0, stemp.length()-1);
        }
    }
    return HC;
}

//����
string coding(pcode* HC,const string & data,int len)
{
    string s="";                    //�������µĹ�����������
    for(int i=0;i<data.length();++i)
        for(int j=1;j<=len;++j)
            if(HC[j].c==data.at(i))
            {
                s+=*HC[j].code;
                break;
            }
    return s;
}

//����
bool encoding(string & code,string & t_code,pcode* HC,int len)  //code���������£�t_code��������������
{
    t_code="";
    int index=0;
    while(index<code.length())
    {
        int clength=0;          //��¼ƥ����ַ��Ĺ��������볤�ȣ���������Ĺ���������ƥ�䣩
        int falg=0;             //��¼����ƥ����ַ��±�
        for(int i=1;i<=len;++i)
        {
            string hc=*HC[i].code;
            if(hc.length()<=clength || hc.at(0)!=code.at(index))
                continue;

            string temp=code.substr(index,hc.length());
            if(temp==hc)
            {
                clength=hc.length();
                falg=i;
            }
        }

        if(falg)        //ƥ��ɹ�
        {
            t_code+=HC[falg].c;
            index+=(*HC[falg].code).length();
        }
        else
            return false;
    }
    return true;
}

//ѹ�������ļ�
bool write(string & code,const char* filename)
{
    char s[20];
    strcpy(s,filename);
    strcat(s,"_code.dat");
    ofstream out(s,ios::binary);
    if(!out)
        return false;
    out.write((char*)&code,sizeof(code));
    out.close();
    return true;
}

//�������������
void display(pcode* HC,int len)
{
    cout << "���ַ��Ĺ��������룺" << endl;
    for(int i=1;i<=len;++i)
    {
        char c=HC[i].c;
        if(c==' ')
            cout << "space";
        else if(c=='\n')
            cout << "\\n";
        else
            cout << HC[i].c;
        cout << ":" << *HC[i].code << endl;
    }
    cout << endl;
}

//ѹ����
void compressibility(const char* filename)
{
    char s1[20];
    char s2[20];
    strcpy(s1,filename);
    strcat(s1,".txt");
    strcpy(s2,filename);
    strcat(s2,"_code.dat");
    ifstream f1(s1);
    ifstream f2(s2,ios::binary);
    f1.seekg(0,ios::end);
    long l1=f1.tellg();
    f1.close();
    f2.seekg(0,ios::end);
    long l2=f2.tellg();
    f2.close();
    cout << "ѹ��ǰ��" << l1 << "�ֽ�" << endl;
    cout << "ѹ����" << l2 << "�ֽ�" << endl;
    cout << "ѹ����:" << setprecision(2) << (double)l2/l1*100 << "%" << endl;
}

//���HC
void delHC(pcode* HC,int len)
{
    for(int i=1;i<=len;++i)
        delete HC[i].code;
    free(HC);
    HC=NULL;
}

int main()
{
    string data;
    char filename[20];
    cout << "����Ҫ��ȡ���ļ�����������׺����:";
    gets(filename);

    if(fread(data,filename))                        //��ȡ�ļ�
        cout << "ԭ�ģ�" << endl << data << endl;
    else
        exit(1);

    int len=0;
    int* c_n=c_count(data);                         //�ַ�����

    point* root=setTree(c_n,len);                   //��������
    free(c_n);

    pcode* HC=Huffmancode(root,len);                //����������
    display(HC,len);
    free(root);

    string code=coding(HC,data,len);                //���±���
    cout << "�����" << endl << code << endl << endl;

    string t_code;
    if(encoding(code,t_code,HC,len))                //����
        cout << "�����" << endl << t_code << endl;

    if(write(code,filename))                                 //д���ļ�
            cout << "�ɹ����棡" << endl << endl;

    compressibility(filename);                              //ѹ����

    delHC(HC,len);                                  //���HC

    return 0;
}
