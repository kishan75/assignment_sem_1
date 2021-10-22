/*input
4 6
0 1
0 2
1 2
2 0
2 3
3 3
*/
#include<bits/stdc++.h>
using namespace std;
int n; 
bool tc[100][100]; 
vector<int> adj[100];

void dfs(int u, int v)
{
	tc[u][v] = true;
	for (auto i:adj[v])
		if (!tc[u][i])
			dfs(u, i);
}

void calculate_tc()
{
	for (int i = 0; i < n; i++)
		dfs(i, i); 
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			cout<<tc[i][j]<<" ";
		cout<<"\n";
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
	calculate_tc();
	return 0;
}
