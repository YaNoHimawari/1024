#include <stdio.h>

//1.17
void a(int k,int m)
{
    if(m<k)
    {
        printf("输入错误");
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
void student(Data* p)   //传入数据的头指针
{
    double boy_s[5]={0.0},girl_s[5]={0.0},sum[5]={0.0};
    while(p[i]不为空)    //计算各院男女总分
    {
        switch(p[i]->校名)
        {
        case "A":
            if(p[i]->性别=="男") boy_s[0]+=p[i]->得分;
            else girl_s[0]+=p[i]->得分;   break;
        case "B":
            if(p[i]->性别=="男") boy_s[1]+=p[i]->得分;
            else girl_s[0]+=p[i]->得分;   break;
        case "C":
            if(p[i]->性别=="男") boy_s[2]+=p[i]->得分;
            else girl_s[0]+=p[i]->得分;   break;
        case "D":
            if(p[i]->性别=="男") boy_s[3]+=p[i]->得分;
            else girl_s[0]+=p[i]->得分;   break;
        case "E":
            if(p[i]->性别=="男") boy_s[4]+=p[i]->得分;
            else girl_s[0]+=p[i]->得分;   break;
        }
    }
    for(int i=0;i<5;++i) sum[i]=boy_s[i]+girl_s[i];  //计算各院团队总分
    for(int i=0;i<5;++i)                             //输出
        printf("男：%lf 女：%lf 总：%lf\n",boy_s[i],girl_s[i],sum[i]);
}
*/
