#include<bits/stdc++.h>
using namespace std;
vector<int> g[10];
bool vis[10];
void dfs(int source)
{
    vis[source] = 1;
    for(int i=0;i<g[source].size();i++)
    {
        int next = g[source][i];
        if(vis[next]==0)
        {
            dfs(next);
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
    dfs(0);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==1)
        {
            cout<<i<<" ";
        }
    }
}