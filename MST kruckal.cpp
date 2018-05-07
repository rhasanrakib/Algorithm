#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
};
bool acom(edge a,edge b)
{
	return a.w<b.w;
}
int par[1000];
vector<edge>e;
int find(int r)
{
	if(par[r]==r)
		return r;
	//par[r]=find(par[r]);
	return find(par[r]);
}
int mst(int n)
{
	sort(e.begin(),e.end(),acom);
	for(int i =0;i<=n;i++)
		par[i]=i;
	int cnt=0,s=0;
	for(int i=0;i<(int)e.size();i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(u!=v)
		{
			par[u]=v;
			cnt++;
			s+=e[i].w;
			if(cnt==n-1)
				break;
		}
	}
	return s;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edge get;
		get.u=u;
		get.v=v;
		get.w=w;
		e.push_back(get);
	}
	cout<<mst(n)<<endl;
	e.clear();
	return 0;
}
