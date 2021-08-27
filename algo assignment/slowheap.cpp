/*input

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int> pii;
typedef pair<ll,ll>   pll;
#define pb push_back
#define mp make_pair
#define fs first
#define mems(m,b) memset(m,b,sizeof(m));
#define all(v) v.begin(),v.end()
#define ss second
#define rep(i,a,b) for(int i = a;i<b;i++)
#define repr(i,a,b) for(int i = a;i>=b;--i)
#define maxn 100050
#define allin(a,st,last) for(int i=st;i<last;i++)cin>>a[i];
#define allout(a,st,last) for(int i=st;i<last;i++)cout<<a[i]<<" ";
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int a[maxn];

struct heap
{
	int data;
	heap* left = NULL;
	heap* right = NULL;
} ;

heap* slowHeap(int i,int j)
{
	cout<<i<<" "<<j<<"\n";

	if (i==j)
	{
	   heap* temp = new heap;
       temp->data =	a[j];
       return temp;
	}
	int x=i;
	for (int k = i+1; k <= j; ++k)
	{
		if(a[k]<a[x])
			x=k;
	}

	swap(a[x],a[j]);
	int mid = (i+j-1)/2;

    heap* temp = new heap;
    temp->data =a[j];

    if (i<=mid)
    {
	temp->left = slowHeap(i,mid);
    }
    if(mid+1<=j-1)
    {
	temp->right = slowHeap(mid+1,j-1);
    }

    return temp;
}

void bfs(heap* h)
{
	queue<heap*> q;
    q.push(h);

	while(!q.empty()) {
	 
	heap* top = q.front();
	q.pop();

	cout<<" "<<top->data;

	if(top->left!=NULL)
		q.push(top->left);
	if(top->right!=NULL)
		q.push(top->right);

	}
}

int main()
{
  fast
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin>>n;
  allin(a,0,n)
  bfs(slowHeap(0,n-1));
  return 0;
}