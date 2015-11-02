#include<iostream>
#include<memory.h>

using namespace std;

long x[20],sum,co=0,end;
bool *prime=new bool[15000];

void zuhe(int m,int k)
{
    int i,j;
    for(i=m;i>=k;i--)
    {
        x[k]=i;
        if(k>1) zuhe(i-1,k-1);
        else
        {
            sum=0;
            for(j=1;j<end;j++)
                sum+=x[j];
            if((sum-3)/2==true) co++;
        }
    }
}

int main()
{
	memset(prime,true,15000);
	for(int i=0;i*2+3<=30000;i++)
	{
		if(prime[i])
		{
			for(int j=3;j*(i*2+3)<=30000;j+=2)
			{
				prime[((j*(i*2+3))-3)/2]=false;
			}
		}
	}

	long n,k;
	long x[20];
	cin>>n>>k;
	end=n;
	for(int i=0;i<n;i++) cin>>x[i];
	zuhe(n,k);
    cout<<co;
    return 0;
}
