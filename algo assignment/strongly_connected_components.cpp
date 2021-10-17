/*input
7 10
1 2
2 1
1 4
5 4
2 5
3 2
6 5
6 3
3 7
7 6
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100000], adj_rev[100000];
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

int main() {
    int n,edges;
    cin>>n>>edges;
    for (int i=0;i<edges;i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    for (int i = 1; i <=n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    for (auto v : order)
        if (!used[v]) {
            dfs2 (v);

            for (int i = 0; i < component.size(); ++i)
            {
                cout<<component[i]<<" ";
            }
            cout<<"\n";

            component.clear();
        }
}