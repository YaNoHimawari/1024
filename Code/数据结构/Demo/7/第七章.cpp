#include <iostream>
#include <stack>
#include <cstdlib>
#define MAX_SIZE 20

using namespace std;

typedef struct ArcNode{     //���ṹ��
    int adjvex;             //����ָ����λ��
    ArcNode* nextarc;
    bool visited;
}ArcNode;

typedef struct VNode{       //����ṹ��
    char data;
    ArcNode* firstarc;      //��һ�������ö���Ļ�ָ��
}VNode;

typedef struct ALGraph{     //ͼ�ṹ��
    int vexnum;             //�������
    int arcnum;             //����
    VNode* Ghead;           //�׸����ָ��
}ALGraph;

void setALGraph(ALGraph *G)         //�����α�ͼ7.23,����ͷ����Ϊ����
{
    VNode* p=(VNode*)malloc(MAX_SIZE*sizeof(VNode));
    for(int i=0;i<7;++i)
    {
        p[i].firstarc=(ArcNode*)malloc(sizeof(ArcNode));
        p[i].firstarc->nextarc=(ArcNode*)malloc(sizeof(ArcNode));
        p[i].firstarc->nextarc->nextarc=NULL;
    }
    p[0].data='*';
    p[0].firstarc->adjvex=1;
    p[0].firstarc->nextarc->adjvex=3;
    p[1].data='+';
    p[1].firstarc->adjvex=2;
    p[1].firstarc->nextarc->adjvex=3;
    p[2].data='*';
    p[2].firstarc->adjvex=4;
    p[2].firstarc->nextarc->adjvex=5;
    p[3].data='*';
    p[3].firstarc->adjvex=6;
    p[3].firstarc->nextarc->adjvex=7;
    p[4].data='+';
    p[4].firstarc->adjvex=8;
    p[4].firstarc->nextarc->adjvex=9;
    p[5].data='*';
    p[5].firstarc->adjvex=9;
    p[5].firstarc->nextarc->adjvex=6;
    p[6].data='+';
    p[6].firstarc->adjvex=10;
    p[6].firstarc->nextarc->adjvex=11;
    p[7].data='e';
    p[7].firstarc=NULL;
    p[8].data='a';
    p[8].firstarc=NULL;
    p[9].data='b';
    p[9].firstarc=NULL;
    p[10].data='c';
    p[10].firstarc=NULL;
    p[11].data='d';
    p[11].firstarc=NULL;

    G->vexnum=12;
    G->arcnum=14;
    G->Ghead=p;
}

void display(ALGraph *G)        //��ʾͼ
{
    cout << "���������" << G->vexnum << endl;
    cout << "��������" << G->arcnum << endl;
    for(int i=0;i<G->vexnum;++i)
    {
        cout << i << "\t" << G->Ghead[i].data << ":";
        ArcNode* t=G->Ghead[i].firstarc;
        while(t)
        {
            cout << t->adjvex << "\t";
            t=t->nextarc;
        }
        cout << endl;
    }
}

void freeGraph(ALGraph *G)      //�ͷ��ڴ�
{
    for(int i=0;i<G->vexnum;++i)
    {
        ArcNode* arct=G->Ghead[i].firstarc;
        while(arct)
        {
            ArcNode* temp=arct;
            arct=arct->nextarc;
            free(temp);         //�ͷŻ��ڴ�
        }
    }
    free(G->Ghead);             //�ͷŶ����ڴ�
    free(G);                    //�ͷ�ͼ�ڴ�
}

int VNodeindex(ALGraph* G,VNode* v)     //���ض��������±�
{
    for(int i=0;i<G->vexnum;++i)
    {
        bool b=true;
        VNode vt=G->Ghead[i];
        if(v->data!=vt.data)
            b=false;
        ArcNode *v1=v->firstarc;
        ArcNode *v2=vt.firstarc;
        while(v1||v2)
        {
            if(!(v1&&v2))                       //��������ͬ
            {
                b=false;    break;
            }
            else if(v1->adjvex!=v2->adjvex)     //��ָ��ͬ
            {
                b=false;    break;
            }
            else{
                v1=v1->nextarc;
                v2=v2->nextarc;
            }
        }
        if(b)                                   //ƥ��ɹ�
            return i;
    }
    return -1;                                  //ƥ��ʧ��
}

//7.16
void InsertVex(ALGraph *G,VNode *v)
{
    G->Ghead[G->vexnum]=*v;
    G->vexnum++;
    int arccount=0;             //��¼�ö��㻡����
    ArcNode* p=v->firstarc;
    while(p)
    {
        ++arccount;
        p=p->nextarc;
    }
    G->arcnum+=arccount;
}

void InsertArc(ALGraph *G,VNode *v,VNode *w)    //vָ��w
{
    int vindex=VNodeindex(G,v);
    int windex=VNodeindex(G,w);
    if(vindex==-1 || windex==-1)    return;     //���㲻����

    ArcNode *t=(ArcNode*)malloc(sizeof(ArcNode));
    t->adjvex=windex;
    ArcNode *p=G->Ghead[vindex].firstarc;
    bool b=false;                                //�жϻ��Ƿ��Ѳ���
    if(!p)                                      //����Ϊ0
    {
        t->nextarc=NULL;
        G->Ghead[vindex].firstarc=t;
        b=true;
    }
    else if(windex>p->adjvex)
    {
        t->nextarc=p;
        G->Ghead[vindex].firstarc=t;
        b=true;
    }
    else{
        while(p->nextarc)
        {
            if(windex>p->nextarc->adjvex)
            {
                t->nextarc=p->nextarc;
                p->nextarc=t;
                b=true;
            }
            else
                p=p->nextarc;
        }
    }
    if(!b)              //����λ����ĩβ
    {
        p->nextarc=t;
        t->nextarc=NULL;
    }
    G->arcnum++;
}

void DeleteVex(ALGraph *G,VNode *v)
{
    int vindex=VNodeindex(G,v);
    if(vindex==-1)  return;             //���㲻����
    int arccount=0;                     //��¼Ҫɾ���Ļ�����
    ArcNode* p=G->Ghead[vindex].firstarc;
    while(p)
    {
        ++arccount;
        ArcNode *temp=p;
        p=p->nextarc;
        free(temp);
    }
    G->vexnum--;
    for(int i=vindex;i<G->vexnum;++i)
        G->Ghead[i]=G->Ghead[i+1];

    for(int i=0;i<G->vexnum;++i)        //ɾ��������������Ļ�
    {
        ArcNode* p=G->Ghead[i].firstarc;
        if(!p)     continue;            //û�л�
        if(p->adjvex==vindex)           //ɾ�����ǵ�һ����
        {
            G->Ghead[i].firstarc=p->nextarc;
            free(p);
            ++arccount;
            continue;
        }
        while(p->nextarc)
        {
            ArcNode* temp=p->nextarc;
            if(temp->adjvex==vindex)
            {
                if(temp->nextarc)
                    p->nextarc=p->nextarc->nextarc;
                else
                    p->nextarc=NULL;
                free(temp);
                ++arccount;
                break;
            }
            p=p->nextarc;
        }
    }
    G->arcnum-=arccount;
}

void DeleteArc(ALGraph *G,VNode *v,VNode *w)    //ɾ��vָ��w�Ļ�
{
    int vindex=VNodeindex(G,v);
    int windex=VNodeindex(G,w);
    if(vindex==-1 || windex==-1)    return;     //���㲻����

    ArcNode* p=G->Ghead[vindex].firstarc;
    bool b=false;                               //�ж��Ƿ�ɾ���ɹ�
    if(!p)
    {
        cout << "Ҫɾ���Ļ������ڣ�" << endl;
        return;
    }
    if(p->adjvex==windex)
    {
        if(p->nextarc)
            G->Ghead[vindex].firstarc=p->nextarc;
        else
            G->Ghead[vindex].firstarc=NULL;
        b=true;
    }
    else
    {
        while(p->nextarc)
        {
            ArcNode* temp=p->nextarc;
            if(temp->adjvex==vindex)
            {
                if(temp->nextarc)
                    p->nextarc=p->nextarc->nextarc;
                else
                    p->nextarc=NULL;
                free(temp);
                b=true;
                break;
            }
            p=p->nextarc;
        }
    }
    if(b)   G->arcnum--;
    else
        cout << "Ҫɾ���Ļ������ڣ�" << endl;
}

//7.22
bool b;                //��¼��ͨ״̬
void DFS(ALGraph *G,int vindex,int windex)      //�ݹ��㷨
{
    if(b)   return;
    ArcNode* p=G->Ghead[vindex].firstarc;
    while(p)
    {
        if(p->adjvex==windex)
        {
            b=true; return;
        }
        DFS(G,p->adjvex,windex);
        p=p->nextarc;
    }
}
void q22(ALGraph *G,VNode* v,VNode* w)      //��V��w�Ƿ���ͨ
{
    int vindex=VNodeindex(G,v);
    int windex=VNodeindex(G,w);
    if(vindex==-1 || windex==-1)
    {
        cout << "���㲻���ڣ�" << endl;
        return;
    }
    b=false;                                //Ĭ��δ��ͨ
    DFS(G,vindex,windex);
    if(!b)
        cout << "��";
    cout << "��ͨ" <<endl;
}

//7.24
void q24(ALGraph *G)
{
    int vnum=G->vexnum;
    bool *visited=(bool*)malloc(vnum*sizeof(bool));     //��¼����ķ���״̬
    for(int i=0;i<vnum;++i)                             //��ʼ��
        visited[i]=false;
    stack<VNode> s;
    s.push(G->Ghead[0]);                                //��0�±����ʼ����
    visited[0]=true;
    cout << "���ʴ���" << "0 ";
    while(!s.empty())
    {
        bool b=true;                                   //true��ʾ�ö�����ָ�ĵ㶼������
        VNode vt=s.top();
        ArcNode* p=vt.firstarc;
        while(p)
        {
            if(!visited[p->adjvex])                     //δ������
            {
                s.push(G->Ghead[p->adjvex]);
                visited[p->adjvex]=true;
                cout << p->adjvex << " ";
                b=false;
                break;
            }
            p=p->nextarc;
        }
        if(b)   s.pop();
    }
    free(visited);
}

//7.38
void RPN(ALGraph* G,int vindex)         //vindexΪ���������±�
{
    VNode vt=G->Ghead[vindex];
    ArcNode *p;
    p=vt.firstarc;
    while(p)
    {
        if(!p->visited)
        {
            p->visited=true;            //����Ϊ�ѷ���
            ArcNode* t=G->Ghead[p->adjvex].firstarc;
            while(t)                    //����ָ���������ָ���Ļ����ó�δ����
            {
                t->visited=false;
                t=t->nextarc;
            }
            RPN(G,p->adjvex);
        }
        p=p->nextarc;
    }
    cout << vt.data << " ";
}
void q38(ALGraph *G)
{
    for(int i=0;i<G->vexnum;++i)                //���л�����Ϊδ����
    {
        ArcNode* p=G->Ghead[i].firstarc;
        while(p)
        {
            p->visited=false;
            p=p->nextarc;
        }
    }
    cout << "�沨��ʽ��";
    RPN(G,0);                                   //�ݹ����
}


int main()
{
    ALGraph *G=(ALGraph*)malloc(sizeof(ALGraph));
    G->vexnum=0;  G->arcnum=0;
    G->Ghead=NULL;
    setALGraph(G);      //����ͼ
    //��Ӷ���
//    VNode* v=(VNode*)malloc(sizeof(VNode));
//    v->data='x';
//    v->firstarc=NULL;
//    InsertVex(G,v);
    //ɾ������
//    DeleteVex(G,v);
    //��ӻ�
//    InsertArc(G,v,v);
    //ɾ����
//    VNode* w=&G->Ghead[11];
//    DeleteArc(G,v,w);
    display(G);         //���������
    //7.22
//    while(true)
//    {
//        int vstart,vend;
//        cout << "��ʼ���±꣺";
//        cin >> vstart;
//        cout << "�������±꣺";
//        cin >> vend;
//        VNode *v1=&G->Ghead[vstart];
//        VNode *v2=&G->Ghead[vend];
//        q22(G,v1,v2);
//    }
    //7.24
//    for(int i=7;i<G->vexnum;++i)
//        InsertArc(G,&G->Ghead[i],&G->Ghead[0]);
//    q24(G);
    //7.38
//    q38(G);
    freeGraph(G);       //�ͷ��ڴ�
    return 0;
}
