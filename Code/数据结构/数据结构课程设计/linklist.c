#define true 1
#define false 0
#include <stdio.h>
#include <stdlib.h>

typedef struct  LNode {
      int      data;  // ������
      struct LNode   *next;  // ָ����
   } LNode, *LinkList;

/*int compare(int c1,int c2) // c1����c2
 {
   if(c1==c2)
     return 1;
   else
     return 0;
 }*/

int InitList_Link(LinkList L) {
  // ����һ���յ����Ա�
   L = (LinkList)malloc(sizeof(LNode));
   if (!L) exit(-1);
   L->next = NULL;
   return true;
} // InitList_Sq

int CreateList_L(LinkList L, int a[],int n) {
	int i;
	LNode *p;
	L = (LinkList) malloc (sizeof (LNode));
	L->next = NULL;    // �Ƚ���һ����ͷ���ĵ�����
	for (i = n-1; i >= 0; --i) {
	    p = (LinkList) malloc (sizeof (LNode));
	    //scanf(p->data);    // ����Ԫ��ֵ
	    p->data=a[i];
	    p->next = L->next; L->next = p;  //����
	}
	return true;
} // CreateList_L

int GetElem_L(LinkList L, int pos, int e) {
	LNode *p = L->next;   // p ָ���һ�����
	//p = L;   // p ָ���һ�����
	int j = 1;  // j Ϊ������
    while (p && j<pos) { p=p->next;  ++j; }
        // ˳ָ�������ң�ֱ�� p ָ��� pos ��Ԫ�ػ� p Ϊ��
     if ( !p || j>pos )
          return -1;//ERROR;    //  ��pos��Ԫ�ز�����
     e = p->data;                //  ȡ��pos��Ԫ��
     return e;//OK;
} // GetElem_L

void Display_L(LinkList L)  /*��ʾLinkList      */
{
    LNode *p=L;
    p=p->next;
    while (p)
    {  	
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int ListInsert_L(LinkList L, int pos, int e) {
     LNode *p = L;    int j = 0;
     while (p && j < pos-1)
         { p = p->next;  ++j; }   // Ѱ�ҵ�pos-1�����
      if (!p || j > pos-1)
           return -1;       // posС��1���ߴ��ڱ�
      LNode *s = (LinkList) malloc ( sizeof (LNode)); // �����½��
      s->data = e;  s->next = p->next;        // ����L��
      p->next = s;
      return 0;
   } // LinstInsert_L

int ListDelete_L(LinkList L, int pos, int e) {
    LNode *p = L;   int j = 0;
    while (p->next && j < pos-1)
       {  p = p->next;    ++j;    }
                                 // Ѱ�ҵ�pos����㣬����pָ����ǰ��
    if (!(p->next) || j > pos-1)
       return -1;  // ɾ��λ�ò�����
    LNode *q = p->next;   p->next = q->next;  // ɾ�����ͷŽ��
    e = q->data;   free(q);
    return e;
  } // ListDelete_L

int ClearList(LinkList L) {
   // ��������������Ϊһ���ձ�
   LNode *p;
    while (L->next) {
        p=L->next;    L->next=p->next;
		free(p);
    }
    return true;
} // ClearList

int main(){
  int x;
  LinkList L;
  //L = (LinkList)malloc(sizeof(LNode));
  //InitList_Link(L);
  int a[]={1,2,3,4,5,6,7,8,9,10};
  //printf("%d",a[1]);
  CreateList_L(L,a,10);
  Display_L(L);
  ListInsert_L(L, 6, 11);
  printf("%d\n",GetElem_L(L, 8,x));
  Display_L(L);
  printf("%d\n",ListDelete_L (L, 4,x));
  Display_L(L);
}
