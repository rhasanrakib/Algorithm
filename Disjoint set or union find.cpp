#include<bits/stdc++.h>
using namespace std;
int parent[100];
int finds(int n)
{
    if(parent[n]==n)
    {
        return n;
    }
    parent[n]=finds(parent[n]);
    return parent[n];
}
void unions(int a ,int b)
{
    int u=finds(a);
    int v=finds(b);
    if(u==v)
    {
        return;
    }
    else
    {
        parent[u]=v;
    }
}
void makeset(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
    }
}
int main()
{
    int n=5,u,v;
    makeset(n);
    for(int i=1;i<=n;i++)
    {
        cin>>u>>v;
        unions(u,v);
    }
}
