#include <stdio.h>

//1.17
void a(int k,int m)
{
    if(m<k)
    {
        printf("�������");
        return;
    }
    int f[100]={0},s=(m==k)?1:0;
    f[k-1]=1;
    for(int i=k;i<m;++i)
    {
        for(int j=i-k;j<i;++j)
            f[i]+=f[j];
        if(i>=m-k) s+=f[i];
    }
    printf("%d\n",s);

}

int main()
{
    int k,m;
    scanf("%d%d",&k,&m);
    a(k,m);
    return 0;
}


/*1.18
void student(Data* p)   //�������ݵ�ͷָ��
{
    double boy_s[5]={0.0},girl_s[5]={0.0},sum[5]={0.0};
    while(p[i]��Ϊ��)    //�����Ժ��Ů�ܷ�
    {
        switch(p[i]->У��)
        {
        case "A":
            if(p[i]->�Ա�=="��") boy_s[0]+=p[i]->�÷�;
            else girl_s[0]+=p[i]->�÷�;   break;
        case "B":
            if(p[i]->�Ա�=="��") boy_s[1]+=p[i]->�÷�;
            else girl_s[0]+=p[i]->�÷�;   break;
        case "C":
            if(p[i]->�Ա�=="��") boy_s[2]+=p[i]->�÷�;
            else girl_s[0]+=p[i]->�÷�;   break;
        case "D":
            if(p[i]->�Ա�=="��") boy_s[3]+=p[i]->�÷�;
            else girl_s[0]+=p[i]->�÷�;   break;
        case "E":
            if(p[i]->�Ա�=="��") boy_s[4]+=p[i]->�÷�;
            else girl_s[0]+=p[i]->�÷�;   break;
        }
    }
    for(int i=0;i<5;++i) sum[i]=boy_s[i]+girl_s[i];  //�����Ժ�Ŷ��ܷ�
    for(int i=0;i<5;++i)                             //���
        printf("�У�%lf Ů��%lf �ܣ�%lf\n",boy_s[i],girl_s[i],sum[i]);
}
*/
