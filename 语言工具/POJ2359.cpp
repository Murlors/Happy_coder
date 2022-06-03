/*
URL:http://poj.org/problem?id=2359
完成日期:2022.6.3
题目大意:输入一个EOD终止字符串，约瑟夫环按1999取最后一个字符
所用方法:约瑟夫环倒推,f(n,m)=(f(n-1,m)+m)%n
*/
#include "cstdio"
using namespace std;
char in,str[30010];
int len,cnt;
int main() {
    while (in = getchar(), in != EOF)
        if (in != '\n') str[len++] = in;
    for (int i = 2; i <= len; ++i)
        cnt = (cnt + 1999) % i;
    if (str[cnt] == '?') printf("Yes\n");
    else if (str[cnt] == ' ') printf("No\n");
    else printf("No comments\n");
    return 0;
}