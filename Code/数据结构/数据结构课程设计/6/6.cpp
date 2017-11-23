/*
����ͼ������Ӧ�Ľṹ��Map���ڽӾ���Link��
ʹ��˳�������������顣
���·�����ø��������㷨��
���·��ʱ����������Ѱ�������ֱ�������Ҵ������·���Ķ���i���ƶ�������i���ظ�����������֪��iΪ�յ����ѭ����
*/
#include <stdio.h>
#include <string.h>
#define COUNT 11        //�������
#define MAX_LENGTH 100  //���㲻ֱ����ͨʱ��·������


typedef struct Unit{
    char name[20];
    char profile[100];  //������
}Unit;
Unit Map[COUNT];        //��ž���
int Link[COUNT][COUNT]; //�ڽӾ���

void display()
{
    printf("100��ʾ�����\n\n");
    for(int i=0;i<COUNT;++i)
    {
        printf("%-14s:",Map[i].name);
        for(int j=0;j<COUNT;++j)
            printf("%d\t",Link[i][j]);
        printf("\n");
    }
}

void linkmap(int i,int j,int weight)    //�����������ϵ
{
    Link[i][j]=weight;
    Link[j][i]=weight;
}

bool setMap()
{
    //���뾰������
    strcpy(Map[0].name,"������");
    strcpy(Map[0].profile,"�����ﾶ����У�˻�ٰ쳡����");
    strcpy(Map[1].name,"һ��");
    strcpy(Map[1].profile,"��һ���������˼۸�ʵ�ݡ�");
    strcpy(Map[2].name,"ʦ���������");
    strcpy(Map[2].profile,"ʦ������������");
    strcpy(Map[3].name,"������");
    strcpy(Map[3].profile,"�����˶�������");
    strcpy(Map[4].name,"����");
    strcpy(Map[4].profile,"��������¥��");
    strcpy(Map[5].name,"ͼ���");
    strcpy(Map[5].profile,"��ϰ��ѡ������");
    strcpy(Map[6].name,"�߽�");
    strcpy(Map[6].profile,"���߽���¥��");
    strcpy(Map[7].name,"ѧ�������");
    strcpy(Map[7].profile,"ѧ�����������ٰ졣");
    strcpy(Map[8].name,"һ��");
    strcpy(Map[8].profile,"��һ����¥��");
    strcpy(Map[9].name,"������");
    strcpy(Map[9].profile,"500W�Ĵ��š�");
    strcpy(Map[10].name,"�Ƽ���");
    strcpy(Map[10].profile,"�Ƽ�չʾ������");
    //�������ӹ�ϵ
    for(int i=0;i<COUNT;++i)        //��ʼ��
        for(int j=0;j<COUNT;++j)
            Link[i][j]=MAX_LENGTH;
    linkmap(0,1,3);
    linkmap(0,3,7);
    linkmap(1,2,10);
    linkmap(1,4,5);
    linkmap(2,6,4);
    linkmap(2,7,4);
    linkmap(3,4,5);
    linkmap(3,9,12);
    linkmap(4,5,3);
    linkmap(4,8,6);
    linkmap(5,8,5);
    linkmap(5,6,3);
    linkmap(6,7,2);
    linkmap(6,8,6);
    linkmap(7,10,8);
    linkmap(8,9,1);
    linkmap(8,10,7);
    linkmap(9,10,9);
    return true;
}

void searchUnit()           //��ѯ������Ϣ
{
    printf("��ѯ��������ƣ�");
    char sname[20];
    gets(sname);
    for(int i=0;i<COUNT;++i)
        if(strcmp(sname,Map[i].name)==0)
        {
            puts(Map[i].profile);   //���������
            break;
        }
}

int getindex(char* s)       //��ȡ���������±�
{
    for(int i=0;i<COUNT;++i)
            if(strcmp(s,Map[i].name)==0)
                return i;
    return -1;
}

void minlength()            //���·�������������㷨
{
    char start[20];
    char end[20];
    printf("��㣺");
    gets(start);
    printf("�յ㣺");
    gets(end);
    if(strcmp(start,end)==0)
    {
        printf("������Ч��\n");
        return;
    }
    int vs=getindex(start);
    int ve=getindex(end);
    int D[COUNT][COUNT];            //�����ĳ���
    bool P[COUNT][COUNT][COUNT]={false}; //���·���а����Ķ���
    int v,w,u;
    for(v=0;v<COUNT;++v)        //��ʼ��
        for(w=0;w<COUNT;++w)
        {
            D[v][w]=Link[v][w];
            if(D[v][w]<MAX_LENGTH)
            {
                P[v][w][v]=true;
                P[v][w][w]=true;
            }
        }
    for(u=0;u<COUNT;++u)                                //���������㷨
        for(v=0;v<COUNT;++v)
            for(w=0;w<COUNT;++w)
                if(D[v][u]+D[u][w]<D[v][w])
                {
                    D[v][w]=D[v][u]+D[u][w];
                    for(int i=0;i<COUNT;++i)
                        P[v][w][i]=P[v][u][i] || P[u][w][i];
                }
        //���·��
        bool visited[COUNT]={false};
        int t=vs;                                          //��¼��ǰ�ߵ���λ��
        printf("%s",Map[vs].name);
        visited[t]=true;
        while(t!=ve)
        {
            for(int i=0;i<COUNT;++i)
            {
                if(!P[vs][ve][i] || visited[i])           //�ж�i�Ƿ������·����
                    continue;
                int b=false;                              //��¼���i����j��·���Ƿ񻹴����������
                for(int j=0;j<COUNT;++j)
                    if(j!=t && j!=i && P[t][i][j])
                    {
                        b=true;
                        break;
                    }
                if(!b)                                  //t->i�������·��
                {
                    t=i;
                    printf(" -> %s",Map[t].name);       //t�ƶ���i
                    visited[t]=true;                    //��i��Ϊ�ѷ���
                    break;
                }
            }
        }
        printf("\n");
}

int main()
{
    if(setMap())
    {
        display();
        printf("\n");
        searchUnit();
        printf("\n");
        while(1)
            minlength();
    }
    return 0;
}
