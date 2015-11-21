#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//left前面要留有一个0用来进位，也就是说left[-1]存在且为0,right前不需要
void add(char *left, const int lenLeft, const char *right, const int lenRight)
{
    int indexL=lenLeft-1,indexR=lenRight-1;
    while(indexL>=0)
    {
        if(indexR>=0)
        {
            left[indexL]+=right[indexR]-'0';
            indexR--;
        }
        if(left[indexL]>'9')
        {
            left[indexL-1]++;
            left[indexL]-=10;
        }
        indexL--;
    }
}

void sub(char *left, const int lenLeft, const char *right, const int lenRight)
{
    int indexL=lenLeft-1,indexR=lenRight-1;
    while(indexL>=0)
    {
        if(indexR>=0)
        {
            left[indexL]-=right[indexR]-'0';
            indexR--;
        }
        if(left[indexL]<'0')
        {
            left[indexL-1]--;
            left[indexL]+=10;
        }
        indexL--;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char number[500]={'0'};
        //从number+1开始输入，给加法预留一个进位
        scanf("%s",number+1);
        //如果输入-1,直接输出0
        if(!strcmp("-1",number+1))
        {
            putchar('0');
        }
        else
        {
            //判断输入数字的正负
            if(number[1]=='-')
            {
                //去掉前面的空位和负号
                strcpy(number,number+2);
                //调用减法函数
                sub(number,strlen(number),"1",1);
                //先输出一个负号
                putchar('-');
            }
            else
            {
                //直接调用加法函数
                add(number+1,strlen(number+1),"1",1);
            }
            //输出结果
            printf("%s",(number[0]=='0'?number+1:number));
        }
        putchar(' ');
    }
    return 0;
}
