#include<bits/stdc++.h>
using namespace std;
#define mx 1000

vector<int> V[mx];
queue<int> Q;
bool visited[mx];
int cost[mx];
int node,edge;

void bfs(int start,int ends)
{
    memset(visited,false,sizeof(visited));
    memset(cost,0,sizeof(cost));
    visited[start]=true;
    Q.push(start);

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int i=0;i<V[u].size();i++)
        {
            int v = V[u][i];
            if(!visited[v])
            {
                visited[v]=true;
                cost[v]=cost[u]+1;
                Q.push(v);
            }
        }

    }
    cout<<cost[ends]<<endl;

    return;
}

int main()
{
    int start,ends;
    cin>>node>>edge;

    for(int i=0;i<edge;i++)
    {
        int x,y;
        cin>>x>>y;
        V[x].push_back(y);
        V[y].push_back(x);
    }
    cout<<"Start End"<<endl;
    cin>>start>>ends;
    bfs(start,ends);
    /*for(int i=1;i<=node;i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}
