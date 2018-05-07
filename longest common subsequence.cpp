#include<bits/stdc++.h>
using namespace std;
string s,ss;
int dp[100][100];
func(int pos1,int pos2)
{
    if(s[pos1]=='\0' || ss[pos2]=='\0')
    {
        return 0;
    }
    if(dp[pos1][pos2]!=-1)
    {
        return dp[pos1][pos2];
    }
    int ans;
    if(s[pos1]==ss[pos2])
    {
        ans=1+func(pos1+1,pos2+1);
    }
    else
    {
        int x=func(pos1+1,pos2);
        int y=func(pos1,pos2+1);
        ans=max(x,y);
    }
    dp[pos1][pos2]=ans;
    return dp[pos1][pos2];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>s>>ss;
    int aa=func(0,0);
    cout<<"ans = "<<aa<<endl;
}
