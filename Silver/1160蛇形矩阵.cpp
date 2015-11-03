#include<iostream>

using namespace std;

int main()
{
    int snake[100][100]={0},i,j;
    int n,k,sum=0;
    cin>>n;
    k=n*n;
    i=j=n-1;
    while(k>0)
    {
        while(k>0)
        {
            if(j<0||snake[i][j]!=0)
            {
                j++;
                break;
            }
            //cout<<i<<"and"<<j<<':'<<k<<"  a"<<endl;
            snake[i][j--]=k--;
        }
        if(snake[i][j]!=0) i--;

        while(k>0)
        {
            if(i<0||snake[i][j]!=0)
            {
                i++;
                break;
            }
            //cout<<i<<"and"<<j<<':'<<k<<"  b"<<endl;
            snake[i--][j]=k--;
        }
        if(snake[i][j]!=0) j++;

        while(k>0)
        {
            if(j>=n||snake[i][j]!=0)
            {
                j--;
                break;
            }
            //cout<<i<<"and"<<j<<':'<<k<<"  c"<<endl;
            snake[i][j++]=k--;
        }
        if(snake[i][j]!=0) i++;

        while(k>0)
        {
            if(i>=n||snake[i][j]!=0)
            {
                i--;
                break;
            }
            //cout<<i<<"and"<<j<<':'<<k<<"  d"<<endl;
            snake[i++][j]=k--;
        }
        if(snake[i][j]!=0) j--;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<snake[i][j];
            if(j<n-1) cout<<' ';
            if(i==j||i+j==n-1) sum+=snake[i][j];
        }
        cout<<endl;
    }
    cout<<sum;
    cout<<endl;
}
