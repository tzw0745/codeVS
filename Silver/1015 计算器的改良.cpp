//没有考虑未知数系数省略的情况，即3x+x=4，当然题目的数据也没考虑
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char a[512],ch;
    int unknown=0,number=0;
    int i=0,j=0,len;
    gets(a);

    for(len=0;a[len]!='=';len++) ;
    while(i<len)
    {
        //i跳到数字开头
        while(i<len&&a[i]!='-'&&!isdigit(a[i])) i++;
        //j跳到数字末尾的下一个字符
        j=i+1;
        while(j<len&&isdigit(a[j])) j++;
        //判断此数字是不是未知数的系数
        if(j<len&&isalpha(a[j]))
        {
            ch=a[j];
            unknown-=atoi(a+i);
        }
        else
        {
            number+=atoi(a+i);
        }
        //i跳到此数字的结尾
        i=j;
    }

    i=len+1;
    len=strlen(a);
    while(i<len)
    {
        //i跳到数字开头
        while(i<len&&a[i]!='-'&&!isdigit(a[i])) i++;
        //j跳到数字末尾的下一个字符
        j=i+1;
        while(j<len&&isdigit(a[j])) j++;
        //判断此数字是不是未知数的系数
        if(j<len&&isalpha(a[j]))
        {
            ch=a[j];
            unknown+=atoi(a+i);
        }
        else
        {
            number-=atoi(a+i);
        }
        //i跳到此数字的结尾
        i=j;
    }
    printf("%c=%.3f",ch,(fabs(number/(float)unknown-0)<0.001?0:number/(float)unknown));
    return 0;
}
