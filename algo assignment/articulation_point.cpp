/*input
5 5
1 0
0 2
2 1
0 3
3 4
*/
#include<bits/stdc++.h>
using namespace std;

int n; 
vector<int> adj[10000]; 

vector<bool> visited;
vector<int> tin, low;
int timer;
set<int> cut_point;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                cut_point.insert(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        cut_point.insert(v);
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 1; i<=n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}

int main()
{
    cin>>n;
    int edge;
    cin>>edge;
    while(edge--)
    {
        int num1,num2;
        cin>>num1>>num2;
        adj[num1].push_back(num2);
    }
    find_cutpoints();
    for (auto i:cut_point)
    {
        cout<<i<<" ";
    }

}