#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int, pii>   ppiii;
#define pb push_back
#define mp make_pair
#define fs first
#define all(v) v.begin(),v.end()
#define ss second
#define maxn 100050
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int parent[maxn],vertices,edges;
ppiii graph_data[maxn];
vector<int> mst_edges;

int get_root(int x)
{
    if (x==parent[x])
    {
    	return x;
    }
    else {
    	return get_root(parent[x]);
    }
}

void merge(int x,int y)
{
	parent[get_root(x)]=parent[get_root(y)];
} 

bool is_cycle(int x, int y)
{
   if (get_root(x)==get_root(y))
   {
     return true;
   }
   return false;
}

int get_cost(int ignore = -1)
{ 

    int x,y,min_cost=0,cost;
    for (int i = 0; i < edges; ++i)
    {
        if(ignore==i)
            continue;
         x=graph_data[i].ss.fs;
         y=graph_data[i].ss.ss;
         cost=graph_data[i].fs;
         if(!is_cycle(x,y))
         {
            min_cost+=cost;
            merge(x,y);
            if (ignore==-1)
            {
                mst_edges.pb(i);
            }
         }
    }
    return min_cost;
}

int main()
{
  fast
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
 
  for (int i = 0; i < maxn; ++i)
  {
      parent[i]=i;
  }

  cin>>vertices>>edges;

  int weight,a,b,min_cost;
  for (int i = 0; i < edges; ++i)
  {
  	 cin>>weight>>a>>b;
  	 graph_data[i]=mp(weight,mp(a,b));
  }
   sort(graph_data,graph_data+edges);
   min_cost=get_cost();
   cout<<"min cost = "<<min_cost<<"\n";
   
   int min_cost_2=INT_MAX,cost;
   for (int i = 0; i < mst_edges.size(); ++i)
   {
       for (int i = 0; i < maxn; ++i)
        {
            parent[i]=i;
        }
       cost=get_cost(i);
       if (cost>min_cost)
       {
       min_cost_2=min(min_cost_2,cost);
       }
   }
   cout<<"2nd min cost = "<<min_cost_2;

  return 0;
}