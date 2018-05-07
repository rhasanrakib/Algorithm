#include<bits/stdc++.h>
using namespace std;
int ara[1000009],st[100009][300];
int n;
void sparse_table()
{
    int i,j,k;
    memset(st,-1,sizeof(st));
    for(i=0;i<n;i++)
    {
        st[i][0]=i;
    }
    for(j=1;(1<<j)<=n;j++)
    {
        for(i=0;(i+(1<<j))<=n;i++)
        {
            int x=st[i][j-1];
            int y=st[i+(1<<(j-1))][j-1];
            if(ara[x]<=ara[y])
            {
                st[i][j]=x;
            }
            else
            {
                st[i][j]=y;
            }
        }
    }
}
void query(int lb,int ub)
{
    int dis=ub-lb;
    int k=log2(dis);
    int x=st[lb][k];
    int y=st[ub-(1<<k)+1][k];
    if(ara[x]<=ara[y])
    {
        cout<<ara[x]<<endl;
    }
    else
    {
        cout<<ara[y]<<endl;
    }
}
int main()
{
    int q,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ara[i];
    }
    sparse_table();
    cin>>q;
    while(q--)
    {
        cin>>i>>j;
        query(i,j);
    }
}
