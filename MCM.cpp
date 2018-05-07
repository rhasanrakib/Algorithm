#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int row[100],col[100];
int func (int be,int ed)
{
    if(be>=ed)
    {
        return 0;
    }
    if(dp[be][ed]!=-1)
    {
        return dp[be][ed];
    }
    int mn=999999999;
    for(int mid=be;mid<ed;mid++)
    {
        int left=func(be,mid);
        int right=func(mid+1,ed);
        int current=row[be]*col[mid]*col[ed];
        int sum=left+right+current;
        mn=min(mn,sum);
       // cout<<mn<<endl;
        //dp[be][ed]=mn;
    }
    return dp[be][ed]=mn;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>row[i]>>col[i];
    }

    int re=func(0,n+1);
    cout<<re<<endl;
}
