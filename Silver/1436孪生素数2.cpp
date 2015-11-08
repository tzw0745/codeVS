#include <iostream>
#include <memory.h>

#define MAX 5000

using namespace std;

int main()
{
    //打表
    bool prime[MAX/2];
	memset(prime,true,MAX/2);
	for(int i=0;i*2+3<=MAX;i++)
	{
		if(prime[i])
		{
			for(int j=3;j*(i*2+3)<=MAX;j+=2)
			{
				prime[((j*(i*2+3))-3)/2]=false;
			}
		}
	}
	int m,k;
	int count=0;
	cin>>m>>k;
	//从2迭代到m
	for(int i=2;i+k<m;i++)
	{
	    //判断i和i+k是否为素数
	    if( (i==2||(i%2&&prime[(i-3)/2])) && ((i+k)%2&&prime[(i+k-3)/2]) )
	    {
	        cout<<i<<' '<<i+k<<endl;
	        count++;
	    }
	}
	cout<<"Total Is:"<<count;
	return 0;
}
