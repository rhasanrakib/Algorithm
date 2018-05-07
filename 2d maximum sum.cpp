#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ara[200][200];
    int csum[200][200];
    int linear[200];
    memset(ara,0,sizeof(ara));
    memset(csum,0,sizeof(csum));
    memset(linear,0,sizeof(linear));
    int row,col,i,j,x,k=0;
    cin>>row>>col;
    for(i=1; i<=row; i++)
    {
        for(j=1; j<=col; j++)
        {
            cin>>ara[i][j];
        }
    }

    ///cumulative sum
    for(i=1; i<=col; i++)
    {
        for(j=1; j<=row; j++)
        {
            csum[j][i]=csum[j-1][i]+ara[j][i];///making cumulative sum of the col.
        }
    }

    ///2D array starting point i and ending point j;

    int nd,mx=0;
    for(i=1; i<=row; i++)
    {
        for(j=i; j<=row; j++)
        {
            for(k=1; k<=col; k++)   ///K is for changing the col
            {
                linear[k]=csum[j][k]-csum[i-1][k];
            }
            int sum=0;
            for(x=1; x<=col; x++)
            {
                sum+=linear[x];

                if(sum<0)
                    sum=0;

                mx=max(mx,sum);
            }
        }
    }
    cout<<mx<<endl;
}
