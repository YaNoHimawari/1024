/*
根据图构建相应的结构体Map和邻接矩阵Link。
使用顺序查找输出景点简介。
最短路径采用弗洛伊德算法。
输出路径时从起点出发，寻找与起点直接相连且处于最短路径的顶点i，移动顶点至i，重复上述操作，知道i为终点结束循环。
*/
#include <stdio.h>
#include <string.h>
#define COUNT 11        //景点个数
#define MAX_LENGTH 100  //两点不直接连通时的路径长度


typedef struct Unit{
    char name[20];
    char profile[100];  //景点简介
}Unit;
Unit Map[COUNT];        //存放景点
int Link[COUNT][COUNT]; //邻接矩阵

void display()
{
    printf("100表示无穷大\n\n");
    for(int i=0;i<COUNT;++i)
    {
        printf("%-14s:",Map[i].name);
        for(int j=0;j<COUNT;++j)
            printf("%d\t",Link[i][j]);
        printf("\n");
    }
}

void linkmap(int i,int j,int weight)    //建立两点的联系
{
    Link[i][j]=weight;
    Link[j][i]=weight;
}

bool setMap()
{
    //导入景点数据
    strcpy(Map[0].name,"体育场");
    strcpy(Map[0].profile,"西北田径场，校运会举办场所。");
    strcpy(Map[1].name,"一餐");
    strcpy(Map[1].profile,"第一餐厅，饭菜价格实惠。");
    strcpy(Map[2].name,"师生事务大厅");
    strcpy(Map[2].profile,"师生事务处理场所。");
    strcpy(Map[3].name,"体育馆");
    strcpy(Map[3].profile,"室内运动场所。");
    strcpy(Map[4].name,"六教");
    strcpy(Map[4].profile,"第六教研楼。");
    strcpy(Map[5].name,"图书馆");
    strcpy(Map[5].profile,"自习首选场所。");
    strcpy(Map[6].name,"七教");
    strcpy(Map[6].profile,"第七教研楼。");
    strcpy(Map[7].name,"学生活动中心");
    strcpy(Map[7].profile,"学生活动都在这里举办。");
    strcpy(Map[8].name,"一教");
    strcpy(Map[8].profile,"第一教研楼。");
    strcpy(Map[9].name,"正大门");
    strcpy(Map[9].profile,"500W的大门。");
    strcpy(Map[10].name,"科技馆");
    strcpy(Map[10].profile,"科技展示场所。");
    //建立连接关系
    for(int i=0;i<COUNT;++i)        //初始化
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

void searchUnit()           //查询景点信息
{
    printf("查询景点的名称：");
    char sname[20];
    gets(sname);
    for(int i=0;i<COUNT;++i)
        if(strcmp(sname,Map[i].name)==0)
        {
            puts(Map[i].profile);   //输出景点简介
            break;
        }
}

int getindex(char* s)       //获取景点所在下标
{
    for(int i=0;i<COUNT;++i)
            if(strcmp(s,Map[i].name)==0)
                return i;
    return -1;
}

void minlength()            //最短路径，弗洛伊德算法
{
    char start[20];
    char end[20];
    printf("起点：");
    gets(start);
    printf("终点：");
    gets(end);
    if(strcmp(start,end)==0)
    {
        printf("输入无效！\n");
        return;
    }
    int vs=getindex(start);
    int ve=getindex(end);
    int D[COUNT][COUNT];            //两点间的长度
    bool P[COUNT][COUNT][COUNT]={false}; //最短路径中包含的顶点
    int v,w,u;
    for(v=0;v<COUNT;++v)        //初始化
        for(w=0;w<COUNT;++w)
        {
            D[v][w]=Link[v][w];
            if(D[v][w]<MAX_LENGTH)
            {
                P[v][w][v]=true;
                P[v][w][w]=true;
            }
        }
    for(u=0;u<COUNT;++u)                                //弗洛伊德算法
        for(v=0;v<COUNT;++v)
            for(w=0;w<COUNT;++w)
                if(D[v][u]+D[u][w]<D[v][w])
                {
                    D[v][w]=D[v][u]+D[u][w];
                    for(int i=0;i<COUNT;++i)
                        P[v][w][i]=P[v][u][i] || P[u][w][i];
                }
        //输出路径
        bool visited[COUNT]={false};
        int t=vs;                                          //记录当前走到的位置
        printf("%s",Map[vs].name);
        visited[t]=true;
        while(t!=ve)
        {
            for(int i=0;i<COUNT;++i)
            {
                if(!P[vs][ve][i] || visited[i])           //判断i是否在最短路径上
                    continue;
                int b=false;                              //记录结点i与结点j的路径是否还存在其他结点
                for(int j=0;j<COUNT;++j)
                    if(j!=t && j!=i && P[t][i][j])
                    {
                        b=true;
                        break;
                    }
                if(!b)                                  //t->i处于最短路径
                {
                    t=i;
                    printf(" -> %s",Map[t].name);       //t移动到i
                    visited[t]=true;                    //将i置为已访问
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
