/*input
1 2 3 4 5 6 7 8 0 
1 2 3 4 0 5 6 7 8 
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define pb push_back
#define fs first
#define ss second
#define x_dimension 3
#define y_dimension 3
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

enum Move
{
  Up,Down,Left,Right,Start
};


unordered_set<string> vis;

short int req_pos[x_dimension][y_dimension];          // required position
struct node
{
  short int a[x_dimension][y_dimension]={0};
  short int level=0;
  Move last_move = Start;
  short int cost=0;
  pii blank_pos;
  node *parent_node=NULL;
} *ans;

void set_cost_count(node& l)
{
  short int sum=0;
  for (short int i = 0; i < x_dimension; ++i)
    for (short int j = 0; j < y_dimension; ++j)
      if (l.a[i][j]&&l.a[i][j]!=req_pos[i][j])
        sum++;
  l.cost=sum;
}


struct cmp  
{  
  bool operator()(const node& l, const node& r)  
  {  
      return (l.level+l.cost) > (r.level+r.cost);  
  }  
}; 

priority_queue<node,vector<node>,cmp> q;

string getSum(node& l)
{
  string s;
  for (int i = 0; i < x_dimension; ++i)
  {
    for (int j = 0; j < y_dimension; ++j)
    {
      s+=to_string(l.a[i][j]);
      s+=',';
    }
  }
  return s;
}

node getNewNode(node cur_node,Move move)
{
  node temp = cur_node;
  temp.level=cur_node.level+1;
  temp.last_move=move;
  short int x=cur_node.blank_pos.fs;
  short int y=cur_node.blank_pos.ss;
  switch(move)
  {
    case Up: 
        swap(temp.a[x-1][y],temp.a[x][y]);
        temp.blank_pos.fs--;
        break;
    case Down:
        swap(temp.a[x+1][y],temp.a[x][y]);
        temp.blank_pos.fs++; 
        break;
    case Left: 
        swap(temp.a[x][y-1],temp.a[x][y]);
        temp.blank_pos.ss--;
        break;
    case Right:
        swap(temp.a[x][y+1],temp.a[x][y]);
        temp.blank_pos.ss++;
        break;
  }
  set_cost_count(temp);
  return temp;
}

node tempNode;

void solve(node cur_node)
{
   q.push(cur_node);
   vis.insert(getSum(cur_node));
   while(1)
   {
    cur_node=q.top();
    cout<<"\n---- levels = "<<cur_node.level<<" cost = "<<cur_node.cost<<"  "<<"------\n";
    q.pop();
    if((cur_node.last_move==Start&&cur_node.blank_pos.fs!=0)||(cur_node.last_move!=Down&&cur_node.blank_pos.fs!=0))  // going Up
    {
      tempNode=getNewNode(cur_node,Up);
      string visString=getSum(tempNode);
      if(vis.find(visString)==vis.end())
      {
      vis.insert(visString);
      tempNode.parent_node=&cur_node;
      q.push(tempNode);
      if (tempNode.cost==0)
        break;
      }
    }
    if((cur_node.last_move==Start&&cur_node.blank_pos.fs!=x_dimension-1)||(cur_node.last_move!=Up&&cur_node.blank_pos.fs!=y_dimension-1))  // going down
    {
      tempNode=getNewNode(cur_node,Down);
      string visString=getSum(tempNode);
      if(vis.find(visString)==vis.end())
      {
      vis.insert(visString);
      tempNode.parent_node=&cur_node;
      q.push(tempNode);
      if (tempNode.cost==0)
        break;
      }
    }
    if((cur_node.last_move==Start&&cur_node.blank_pos.ss!=0)||(cur_node.last_move!=Right&&cur_node.blank_pos.ss!=0))  // going Up
    {
      tempNode=getNewNode(cur_node,Left);     
      string visString=getSum(tempNode);
      if(vis.find(visString)==vis.end())
      {
      vis.insert(visString);
      tempNode.parent_node=&cur_node;
      q.push(tempNode);
      if (tempNode.cost==0)
        break;
      }
    }
    if((cur_node.last_move==Start&&cur_node.blank_pos.ss!=x_dimension-1)||(cur_node.last_move!=Left&&cur_node.blank_pos.ss!=y_dimension-1))  // going Up
    {
      tempNode=getNewNode(cur_node,Right);
      string visString=getSum(tempNode);
      if(vis.find(visString)==vis.end())
      {
      vis.insert(visString);
      tempNode.parent_node=&cur_node;
      q.push(tempNode);
      if (tempNode.cost==0)
        break;
      }
    }
   }
   ans = &tempNode; 
}

void printNodeState(node* cur_node)
{
   if (cur_node==NULL)
      return ;
   printNodeState(cur_node->parent_node);
   cout<<"levels: "<<cur_node->level<<", cost: "<<cur_node->cost;
   cout<<", blank position (x: "<<cur_node->blank_pos.fs<<", y: "<<cur_node->blank_pos.ss<<")\n";
   for (int i = 0; i < x_dimension; ++i)
   {
     for (int j = 0; j < y_dimension; ++j)
     {
       cout<<cur_node->a[i][j]<<" ";
     }
     cout<<"\n";
   }
}

int main()
{
  fast
  node in;
  cout<<"taking input of required position\n";
  for (short int i = 0; i < x_dimension; ++i)
  {
    for (short int j = 0; j < y_dimension; ++j)
    {
       cin>>req_pos[i][j];
    }
  }
  cout<<"taking input of input position\n";
  pii blank_pos;
  for (short int i = 0; i < x_dimension; ++i)
  {
    for (short int j = 0; j < y_dimension; ++j)
    {
       cin>>in.a[i][j];
       if(!in.a[i][j])
        blank_pos={i,j};
    }
  }
  set_cost_count(in);
  in.blank_pos=blank_pos;
  solve(in);
  cout<<"\n"<<ans->level<<" ";
  if(&ans->parent_node==&(ans->parent_node->parent_node))
    cout<<"equal";
  //printNodeState(ans);
  return 0;
}

