#include<stdio.h>
#include<math.h>
#define N 5000//modify it to hold larger number
//to avoid stack overflow, define it as global varible
int f[N];//do not need to be assigned as 0 because it has already been assigned 0 by the system
int main()
{
    int n,i,j,s,up;
    scanf("%d",&n);
    for(i=2,f[0]=1; i<=n; i++)
    {
        for(j=up=0; j<N; j++)
        {
            s=f[j]*i+up;
            f[j]=s%10;
            up=s/10;
        }
    }
    int sum=0;
    for(i=N-1; f[i]==0; i--);
    for(; i>=0; i--)
        sum+=f[i];
    printf("%d",sum);
    int flag=1;
    for(i=2; i<sqrt(sum); i+=2)
    {
        if(sum%i==0)
        {
            flag=0;
            break;
        }
        if(i==2) i--;
    }
    flag?putchar('T'):putchar('F');
    return 0;
}
