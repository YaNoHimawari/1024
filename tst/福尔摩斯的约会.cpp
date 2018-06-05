/*
大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，
因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；
第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；
后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。
现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入描述:
输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出描述:
在一行中输出约会的时间，格式为“DAY HH:MM”，
其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。
题目输入保证每个测试存在唯一解。
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
