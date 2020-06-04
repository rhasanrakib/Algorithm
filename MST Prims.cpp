#include<bits/stdc++.h>
using namespace std;

int mst_prims(vector<pair<int,int>>edges[],int start)
{
    vector<int>path;
    int visited[1000000];
    memset(visited,0,sizeof(visited));
    int cost=0;
    priority_queue<pair<int,int>>PQ;
    //visited[start]=1;
    PQ.push(make_pair(0,start)); //<Cost,Node> because priority queue sort the pair with first element
    while(!PQ.empty())
    {
        pair<int,int>temp;
        temp = PQ.top();
        PQ.pop();
        int u=temp.second;

        if(!visited[u])
        {
            visited[u]=1;
            cost+= -temp.first;
            path.push_back(u);

            for(int i=0;i<edges[u].size();i++)
            {
                int v = edges[u][i].first;
                if(!visited[v])
                {
                    PQ.push(make_pair(-edges[u][i].second,edges[u][i].first));//making pair <-cost,node>
                }
            }
        }

    }
    for(int i=0;i<path.size();i++)
        cout<<path[i]<<" ";

    return cost;

}

int main()
{
    int node,edge,u,v,cost,start,ans;
    cin>>node>>edge;
    vector<pair<int,int>>V[node+1];
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v>>cost;
        V[u].push_back(make_pair(v,cost));
        V[v].push_back(make_pair(u,cost));
    }
    cin>>start;

    ans = mst_prims(V,start);
    cout<<ans<<endl;

    return 0;

}
