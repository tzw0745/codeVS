#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    int a,b;
    cin>>a;
    while(a++)
    {
        b=0;
        for(int i=1;i<=a/2;i++)
        {
            if(a%i==0) b+=i;
        }
        int c=0;
        for(int i=1;i<=b/2;i++)
        {
            if(b%i==0) c+=i;
        }
        if(a==c) break;
    }
    cout<<a<<' '<<b<<endl;
}
