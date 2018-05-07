#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,l,range,cnt,dis,r;
    int ara[1000],digit[1000];
    while(cin>>n>>range)
    {
        memset(digit,0,sizeof(digit));
        l=0,r=0,cnt=0;
        int mn=99999;
        for(i=0;i<n;i++)
            cin>>ara[i];
        for(i=0;l<n;i++)
        {
            if(cnt==range)
            {
                dis=r-l;
                mn=min(dis,mn);
                if(digit[ara[l]]==1)
                {
                    cnt--;
                }
                if(digit[ara[l]]>0)
                {
                    digit[ara[l]]--;
                }
                l++;
            }
            else if(ara[r]<=range)
            {
                if(digit[r]==0)
                {
                    cnt++;
                }
                digit[r]++;
            }
            r++;
        }
        cout<<mn<<endl;
    }
}
