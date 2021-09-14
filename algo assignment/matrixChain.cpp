/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define mems(m,b) memset(m,b,sizeof(m));
#define allin(a,st,last) for(int i=st;i<last;i++)cin>>a[i];
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int order[10000],n;
int dp[1000][1000];
int iterative[1000][1000];
char mat_name = 'A';
int brackets[1000][1000];

void printBracket(int i, int j){
    
    if(i == j){
        cout<<mat_name++;
    } else {
        cout<<"(";
        printBracket(i, brackets[i][j]);
        printBracket(brackets[i][j]+1, j);
        cout<<")";
    }
}

int multiplyRecursive(int i,int j)
{
	if(i==j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	dp[i][j]=INT_MAX;
	for(int k=i;k<j;k++)
	{	
		int ans=(multiplyRecursive(i,k)+multiplyRecursive(k+1,j)+order[i-1]*order[k]*order[j]);
		if(ans<dp[i][j])
		{
			dp[i][j]=ans;
			brackets[i][j] = k;
		}
    }
	return dp[i][j];
}

int multiplyIterative()
{
	for(int i=1;i<n;i++)
		iterative[i][i]=0;
	for(int l=2;l<n;l++)
	{
		for (int i = 1; i < n-l+1; ++i)
		{
			int j=i+l-1;
            iterative[i][j]=INT_MAX;
            for (int k=i;k<=j-1;k++)
            {
            	int ans = iterative[i][k]+iterative[k+1][j]+order[i-1]*order[k]*order[j];
            	if (ans<iterative[i][j])
            	{
            	   iterative[i][j]=ans;
                    brackets[i][j] = k;
            	}
            }
		}
	}
	return iterative[1][n-1];
}

int main(){
  fast
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin>>n;   // number of matrices 
  n++;
  allin(order,0,n)    //order of matrices
  mems(dp, -1)
  cout<<multiplyRecursive(1,n-1)<<" ";
  printBracket(0,n-2);
  cout<<"\n";
  mems(brackets, 0)
  mat_name='A';
  cout<<multiplyIterative()<<" ";
  printBracket(0,n-2);

  return 0;
}