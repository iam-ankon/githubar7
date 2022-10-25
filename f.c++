#include <iostream>
#include <list>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;
int W = 0;
struct cmp
{
    bool operator()(prr a, prr b) { return a.second.second > b.second.second; }
};
list<pr> graph[100];
vector<int> tree[100];
priority_queue<prr, vector<prr>, cmp> pq;
map<int, bool> visited;
void add_w_edge(int u, int v, int w)
{
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}
void add_edge(int u, int v)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}

void showpq()
{
    auto tpq = pq;
    while (not tpq.empty())
    {
        cout << "[ " << tpq.top().first << ", " << tpq.top().second.first << " ]"
             << "=" << tpq.top().second.second << endl;
        tpq.pop();
    }
    cout << "=======================\n";
}

void prims(int source)
{

    visited[source] = true;
    for (auto l : graph[source])
        if (not visited[l.first])
            pq.push(make_pair(source, l));

    add_edge(pq.top().first, pq.top().second.first);
    cout << pq.top().first << ":" << pq.top().second.first << "=" << pq.top().second.second << endl;
    while (not pq.empty())
    {
        source = pq.top().second.first;
        pq.pop();
        if (not visited[source])
        {
            for (auto l : graph[source])
                if (not visited[l.first])
                    pq.push(make_pair(source, l));
            visited[source] = true;
        }
        if (not visited[pq.top().first] || not visited[pq.top().second.first])
        {
            cout << pq.top().first << ":" << pq.top().second.first << "=" << pq.top().second.second << endl;
            add_edge(pq.top().first, pq.top().second.first);
            W += pq.top().second.second;
        }
    }
}

void show_graph(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -->  ";
        for (auto leaf : tree[i])
            cout << leaf << " ";
        cout << endl;
    }
}

void show_w_graph(int n)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (auto l : graph[i])
            cout << i << " : " << l.first << "\t w: " << l.second << endl;
        cout << endl;
    }
}

int main()
{
    // change value from here
    add_w_edge(1, 5, 2);
    add_w_edge(1, 4, 10);
    add_w_edge(1, 2, 4);
    add_w_edge(2, 4, 8);
    add_w_edge(2, 3, 18);
    add_w_edge(5, 4, 5);
    add_w_edge(3, 4, 11);
    add_w_edge(4, 7, 11);
    add_w_edge(8, 6, 2);
    add_w_edge(4, 8, 9);
    add_w_edge(6, 7, 1);

    prims(1);
    cout << "Weight of MST: " << W << endl;
    // show_graph(9);
    return 0;
}
