#include<iostream>

using namespace std;

int main()
{
    int x,y,n=0;
    int P,Q;
    cin>>x>>y;
    for(P=x;P<=y;P+=x)
    {
        for(Q=x;Q<=y;Q+=x)
        {
            int temp,a=P,b=Q;
            while(b!=0)
            {
                temp=a%b;
                a=b;
                b=temp;
            }
            if(((P*Q)/a==y)&&(a==x)) n++;
        }
    }
    cout<<n;
    return 0;
}
