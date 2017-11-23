#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct person{
    int num;
    person* next;
}person;

void circle()
{
    int m,n;
    cin >> m;
    cin >> n;
    person* l=(person*)malloc(sizeof(person));
    l->num=1; l->next=NULL;
    person* p=l;
    for(int i=2;i<=m;++i)
    {
        person* t=(person*)malloc(sizeof(person));
        t->num=i;
        t->next=NULL;
        p->next=t;
        p=t;
    }
    p->next=l;
    while(p->next && p!=p->next)
    {
        for(int i=1;i<n;++i)
            p=p->next;
        person* t=p->next;
        p->next=t->next;
        cout.width(4);
        cout << left << t->num ;
        free(t);
    }
    cout << left << p->num ;
    free(p);
    p=NULL; l=NULL;
}

int main()
{
    circle();
    return 0;
}
