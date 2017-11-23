/*
获取要读取的文件名称，然后读入内容存在data中。
统计每个字符出现的储存在c_count中，c_count定义为256个字符的数组，字符对应ASCII值作为下标，出现就++数组。
对出现的字符构建结点，出现次数作为权值，构建哈夫曼树。
遍历哈夫曼树，将每个字符对应的哈夫曼编码存入pcode结构体中。
对data进行遍历，用哈夫曼编码代替字符。
编译后的数据存在t_code中，最后用二进制方式写入dat文件中。
*/
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>

using namespace std;

//结点
typedef struct point{
    char c;                 //数据
    int weight;             //权
    int parent,lc,rc;       //左右孩子
}point;

//哈夫曼编码
typedef struct pcode{
    char c;
    string* code;           //数据对应的哈夫曼编码
}pcode;

//读入英文文章
bool fread(string & data,char* filename)
{
    char s[20];
    //获取文件名
    strcpy(s,filename);
    strcat(s,".txt");
    ifstream in(s);
    string line;

    if(!in)
    {
        cout <<"文件不存在！" << endl;
        return false;
    }

    data="";                        //清空data
    while (getline (in, line))      // line中不包括每行的换行符
        data+=line+'\n';
    return true;                    //表示读入成功
}

//统计字符出现个数
int* c_count(const string & data)
{
    int* c_n=(int*)malloc(256*sizeof(int));     //c_n用于储存每个字符出现的次数
    for(int i=0;i<256;++i)                      //初始化c_n
        c_n[i]=0;

    for(int i=0;i<data.length();++i)
            ++c_n[(int)data.at(i)];
    return c_n;
}

//构建哈夫曼树
bool select(point* & root,int n,int & s1,int & s2)
{
    bool first=true;                 //判断是否为第一次达到条件
    for(int i=1;i<n;++i)
        if(root[i].parent==0)       //判断是否已加入哈夫曼树
        {
            if(!first)
            {
                if(s1==s2)          //第二次达到条件
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
    if(root[s1].c==0 && root[s2].c!=0)                   // 新建结点在右边
    {
        int t=s1; s1=s2; s2=t;
    }
    return true;
}

point* setTree(int* c_n,int & len)
{
    len=0;
    point* root=(point*)malloc(256*sizeof(point));

    for(int i=0;i<256;++i)              //创建结点
        if(c_n[i])                      //统计字符的种类并初始化结点
        {
            ++len;
            root[len].c=(char)i;
            root[len].lc=0;
            root[len].rc=0;
            root[len].parent=0;
            root[len].weight=c_n[i];
        }

    root=(point*)realloc(root,2*len*sizeof(point));     //重新分配内存
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

//生成哈夫曼编码
pcode* Huffmancode(point* root,int len)
{

    pcode* HC=(pcode*)malloc((len+1)*sizeof(pcode));
    string stemp="";
    int p=2*len-1;
    int l=0;
    for(int i=0;i<=p;++i) root[i].weight=0;

    while(p)
    {
        if(root[p].weight==0)           //第一次访问结点
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
        else if(root[p].weight==1)      //第二次访问结点
        {
            root[p].weight=2;
            if(root[p].rc!=0)
            {
                p=root[p].rc;
                stemp+='1';
            }
        }
        else{                           //第三次访问结点
            root[p].weight=0;
            p=root[p].parent;
            stemp = stemp.substr(0, stemp.length()-1);
        }
    }
    return HC;
}

//编码
string coding(pcode* HC,const string & data,int len)
{
    string s="";                    //储存文章的哈夫曼编码结果
    for(int i=0;i<data.length();++i)
        for(int j=1;j<=len;++j)
            if(HC[j].c==data.at(i))
            {
                s+=*HC[j].code;
                break;
            }
    return s;
}

//译码
bool encoding(string & code,string & t_code,pcode* HC,int len)  //code编码后的文章，t_code储存译码后的文章
{
    t_code="";
    int index=0;
    while(index<code.length())
    {
        int clength=0;          //记录匹配的字符的哈夫曼编码长度（优先与最长的哈夫曼编码匹配）
        int falg=0;             //记录最终匹配的字符下标
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

        if(falg)        //匹配成功
        {
            t_code+=HC[falg].c;
            index+=(*HC[falg].code).length();
        }
        else
            return false;
    }
    return true;
}

//压缩储存文件
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

//输出哈夫曼编码
void display(pcode* HC,int len)
{
    cout << "各字符的哈夫曼编码：" << endl;
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

//压缩率
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
    cout << "压缩前：" << l1 << "字节" << endl;
    cout << "压缩后：" << l2 << "字节" << endl;
    cout << "压缩率:" << setprecision(2) << (double)l2/l1*100 << "%" << endl;
}

//清除HC
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
    cout << "输入要读取的文件名（不含后缀名）:";
    gets(filename);

    if(fread(data,filename))                        //读取文件
        cout << "原文：" << endl << data << endl;
    else
        exit(1);

    int len=0;
    int* c_n=c_count(data);                         //字符个数

    point* root=setTree(c_n,len);                   //哈夫曼树
    free(c_n);

    pcode* HC=Huffmancode(root,len);                //哈夫曼编码
    display(HC,len);
    free(root);

    string code=coding(HC,data,len);                //文章编码
    cout << "编码后：" << endl << code << endl << endl;

    string t_code;
    if(encoding(code,t_code,HC,len))                //译码
        cout << "译码后：" << endl << t_code << endl;

    if(write(code,filename))                                 //写入文件
            cout << "成功储存！" << endl << endl;

    compressibility(filename);                              //压缩率

    delHC(HC,len);                                  //清除HC

    return 0;
}
