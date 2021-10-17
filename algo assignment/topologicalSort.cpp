/*input
7
1 2
2 3
3 6
5 3
5 2
4 5
4 1
4
*/
#include<bits/stdc++.h>
using namespace std;

bool vis[5000];
vector<int> a[5000];
vector<int> topo_sort;

void dfs(int x)
{
	vis[x]=true;
   
	for(auto& i : a[x])
	{
		if(vis[i]==false)
		{
			dfs(i);
		}
	}
	topo_sort.push_back(x);
}

int main()
{

	int n;       // number of edges
	cin>>n;
	int num1,num2;
	while(n--)
	{
		cin>>num1>>num2;
		a[num1].push_back(num2);
	}
	int root;
	cin>>root;
	dfs(root);
	for (int i = topo_sort.size()-1; i >-1; --i)
	{
		cout<<topo_sort[i]<<"\n";
	}

}