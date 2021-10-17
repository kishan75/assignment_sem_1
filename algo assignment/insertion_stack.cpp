/*input

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin>>n;
  stack<int> s;
  while(n--)
  {
  	int num;
  	cin>>num;
    s.push(num);
  }
  cout<<"\nsorted\n";
  stack<int> output=insertion(s);
  while(!output.empty())
  {
  	cout<<output.top()<<" ";
  	output.pop();
  }
  return 0;
}