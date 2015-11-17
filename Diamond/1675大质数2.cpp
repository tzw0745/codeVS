#include <iostream>
#include <cmath>

#define MAX 1000

using namespace std;

int main()
{
    //预先筛选出1000以内的素数
    const bool IS=false,NOT=true;
    static bool prime[MAX/2];
    int np[100000]={2},n=1;

    for(int i=0;i*2+3<=MAX;i++)
	{
		if(IS==prime[i])
		{
		    np[n++]=i*2+3;
			for(int j=3;j*(i*2+3)<=MAX;j+=2)
			{
				prime[((j*(i*2+3))-3)/2]=NOT;
			}
		}
	}

    int in;
    cin>>in;
    if(in>1000)
    {
        for(int i=MAX+1;i<in;i+=2)
        {
            int flag=1,j;
            for(j=0;j<n;j++)
            {
                if(j>sqrt(i)) break;
                if(i%np[j]==0)
                {
                    flag=0;
                    break;
                }
            }
            if(flag) np[n++]=i;
        }
        for(int i=0;i<n;i++)
        {
            cout<<np[i]<<endl;
        }
    }
    else
    {
       for(int i=0;np[i]<in;i++)
        {
            cout<<np[i]<<endl;
        }
    }
}
