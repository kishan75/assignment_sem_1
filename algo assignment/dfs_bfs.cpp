/*input

*/
#include<bits/stdc++.h>
using namespace std;
void dfs(int node, bool visit,int adjacency)
{
    for (int i = 0; i < count; ++i)
    {
    	/* code */
    }
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin>>n;
  stack<int> s;
  int num;
  while(n--)
  {
  	cin>>num;
    s.push(num);
  }
  stack<int> temp,result;
  while(!s.empty()) {
      while(!result.empty()&&s.top()>result.top()) {
          temp.push(result.top());
          result.pop();
      }
      result.push(s.top());
      s.pop();
      while(!temp.empty()) {
          result.push(temp.top());
          temp.pop();
      }
  }
  while(!result.empty()) {
      cout<<result.top()<<" ";
      result.pop();
  }
  return 0;
}