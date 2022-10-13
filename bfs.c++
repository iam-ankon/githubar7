#include<bits/stdc++.h>
using namespace std;
vector<int> g[10];
bool vis[10];
int dis[10];
void bfs(int source)
{
    queue<int> q;
    vis[source]=1;
    dis[source]=0;
    q.push(source);
    while (!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int i=0;i<g[node].size();i++)
        {
            int next = g[node][i];
            if(vis[next]==0)
            {
                vis[next]=1;
                dis[next]=dis[node]+1;
                q.push(next); 
            }
        }
    }
    
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(0);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==1)
        cout<<i<<" ";
    }
}