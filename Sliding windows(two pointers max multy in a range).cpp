#include<bits/stdc++.h>
using namespace std;

int main()
{
        int ara[]={1,1,4,5,6,7,2,1,4,3};
        int r=0,l=0,mx=0,i,j,k,sum=1,range=3;
        for(i=0;i<3;i++)
        {
            sum*=ara[i];
            r=i;
        }
        r+=1;
        l=1;
        mx=sum;
        for(i=3;i<10;i++)
        {
            sum=(sum*ara[r])/ara[l-1];
            mx=max(sum,mx);
            r++;
            l++;
        }
        cout<<mx<<endl;
}
