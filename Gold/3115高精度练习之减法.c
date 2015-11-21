#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    char a[500],b[500];
    scanf("%s%s",a,b);

    int la=strlen(a),lb=strlen(b);

    if(la==lb)
    {
        if(strcmp(a,b)>=0)
        {
            sub(a,la,b,lb);
            printf("%s",(a[0]=='0'?a+1:a));
        }
        else
        {
            sub(b,lb,a,la);
            putchar('-');
            printf("%s",(b[0]=='0'?b+1:b));
        }
    }
    else
    {
        if(la>lb)
        {
            sub(a,la,b,lb);
            printf("%s",(a[0]=='0'?a+1:a));
        }
        else
        {
            sub(b,lb,a,la);
            putchar('-');
            printf("%s",(b[0]=='0'?b+1:b));
        }
    }

    return 0;
}
