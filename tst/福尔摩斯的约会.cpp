/*
����̽����Ħ˹�ӵ�һ����ֵ�������������Լ��ɣ� 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm����
����̽�ܿ�������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�䡰������ 14:04����
��Ϊǰ�����ַ����е�1����ͬ�Ĵ�дӢ����ĸ����Сд�����֣��ǵ�4����ĸ'D'�����������ģ�
��2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ������һ����ĵ�14����ͷ������һ���0�㵽23��������0��9���Լ���д��ĸA��N��ʾ����
�������ַ�����1����ͬ��Ӣ����ĸ's'�����ڵ�4��λ�ã���0��ʼ�������ϣ������4���ӡ�
�ָ��������ַ��������������Ħ˹����õ�Լ���ʱ�䡣

��������:
������4���зֱ����4���ǿա��������ո��ҳ��Ȳ�����60���ַ�����

�������:
��һ�������Լ���ʱ�䣬��ʽΪ��DAY HH:MM����
���С�DAY����ĳ���ڵ�3�ַ���д����MON��ʾ����һ��TUE��ʾ���ڶ���WED��ʾ��������THU��ʾ�����ģ�FRI��ʾ�����壬SAT��ʾ��������SUN��ʾ�����ա�
��Ŀ���뱣֤ÿ�����Դ���Ψһ�⡣
*/

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

const string weekday[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main()
{
    string s[4];
    string day;
    int h,m;
    for(int i=0;i<4;++i)
        cin >> s[i];
    int k =0;
    for(int i=0;i<=s[0].length();++i)
         if(s[0][i]==s[1][i])
        {
            char c=s[0][i];
            if(k==0&&isupper(c))
            {
                day = weekday[s[0][i]-'A'];
                ++k;
                continue;
            }
            if(k==1)
            {
                if(c>='0'&&c<='9')
                {h=c-'0'; break;}
                else if(isupper(c))
                {h = c-'A'+10; break;}
            }
        }
    for(int i=0;i<s[2].length();++i)
         if(s[2][i]==s[3][i])
        {
            if(islower(s[2][i]))
            {
                m = i;
                break;
            }
        }
    string time;
    time+=(h<10)?("0"+to_string(h)):to_string(h);
    time+=":";
    time+=(m<10)?("0"+to_string(m)):to_string(m);

    cout << day << " " << time << endl;
    return 0;
}
