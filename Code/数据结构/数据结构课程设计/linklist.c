#define true 1
#define false 0
#include <stdio.h>
#include <stdlib.h>

typedef struct  LNode {
      int      data;  // 数据域
      struct LNode   *next;  // 指针域
   } LNode, *LinkList;

/*int compare(int c1,int c2) // c1等于c2
 {
   if(c1==c2)
     return 1;
   else
     return 0;
 }*/

int InitList_Link(LinkList L) {
  // 构造一个空的线性表
   L = (LinkList)malloc(sizeof(LNode));
   if (!L) exit(-1);
   L->next = NULL;
   return true;
} // InitList_Sq

int CreateList_L(LinkList L, int a[],int n) {
	int i;
	LNode *p;
	L = (LinkList) malloc (sizeof (LNode));
	L->next = NULL;    // 先建立一个带头结点的单链表
	for (i = n-1; i >= 0; --i) {
	    p = (LinkList) malloc (sizeof (LNode));
	    //scanf(p->data);    // 输入元素值
	    p->data=a[i];
	    p->next = L->next; L->next = p;  //插入
	}
	return true;
} // CreateList_L

int GetElem_L(LinkList L, int pos, int e) {
	LNode *p = L->next;   // p 指向第一个结点
	//p = L;   // p 指向第一个结点
	int j = 1;  // j 为计数器
    while (p && j<pos) { p=p->next;  ++j; }
        // 顺指针向后查找，直到 p 指向第 pos 个元素或 p 为空
     if ( !p || j>pos )
          return -1;//ERROR;    //  第pos个元素不存在
     e = p->data;                //  取第pos个元素
     return e;//OK;
} // GetElem_L

void Display_L(LinkList L)  /*显示LinkList      */
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
         { p = p->next;  ++j; }   // 寻找第pos-1个结点
      if (!p || j > pos-1)
           return -1;       // pos小于1或者大于表长
      LNode *s = (LinkList) malloc ( sizeof (LNode)); // 生成新结点
      s->data = e;  s->next = p->next;        // 插入L中
      p->next = s;
      return 0;
   } // LinstInsert_L

int ListDelete_L(LinkList L, int pos, int e) {
    LNode *p = L;   int j = 0;
    while (p->next && j < pos-1)
       {  p = p->next;    ++j;    }
                                 // 寻找第pos个结点，并令p指向其前趋
    if (!(p->next) || j > pos-1)
       return -1;  // 删除位置不合理
    LNode *q = p->next;   p->next = q->next;  // 删除并释放结点
    e = q->data;   free(q);
    return e;
  } // ListDelete_L

int ClearList(LinkList L) {
   // 将单链表重新置为一个空表
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
