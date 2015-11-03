#include<iostream>

using namespace std;

int main()
{
    int i;
    bool Cantor[5000]={false};
    for(i=1;i<=5000;i+=2)
    {
        Cantor[i]=true;
    }
    long N;
    cin>>N;
    for(i=0;N>0;)
    {
       N-=++i;
    }
    N+=i;
    if(Cantor[i-1]) cout<<N<<'/'<<i-N+1<<endl;
    else cout<<i-N+1<<'/'<<N<<endl;
    return 0;
}
