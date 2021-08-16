#include<bits/stdc++.h>
using namespace std;

int a[5000];
int n;

// complexity n
void display_array()
{
    cout<<"\narray elements are\n";
    for(int i=0;i<n;i++)
    	cout<<a[i]<<" ";
    cout<<"\n";
}

//complexity n
void input_element()
{
	cout<<"\n enter array elements\n";
    for(int i=0;i<n;i++)
    	cin>>a[i];
}

//complexity n
void insert_at_begin(int num)
{
   for(int i=n-1;i>-1;i--)
   	a[i+1]=a[i];
   a[0]=num;
   n++;
}

//complexity O(1)
void insert_at_end(int num)
{
   a[n]=num;
   n++;
}

//complexity n
void insert_after_given_pos(int num,int pos)
{
   for(int i=n-1;i>pos;i--)
   	a[i+1]=a[i];
   a[pos+1]=num;
   n++;
}

//complexity n
void insert_after_given_element(int num)
{
    for(int i=0;i<n;i++)
    {
    	if(a[i]==num)
    	{
    		for(int j=n-1;j>i;i--)
    			a[j+1]=a[j];
    		a[i]=num;
    		n++;
    		return ;
    	}
    }
    cout<<"didn't find the given element\n";
}

//complexity n
void delete_given_element(int num)
{
    int temp;
    for(int i=0;i<n;i++)
    {
    	if(a[i]==num)
    	{
    		for(;i<n-1;i++)
    			a[i]=a[i+1];
    		n--;
    		return ;
    	}
    }
    cout<<"didn't find the given element\n";
}

int main()
{
	cout<<"enter size of array\n";
	cin>>n;
	input_element();
	display_array();
	int num;
	cout<<"insert element at begin\n";
	cin>>num;
	insert_at_begin(num);
	display_array();
	cout<<"insert element at end\n";
	cin>>num;
	insert_at_end(num);
	display_array();
	int pos;
	cout<<"insert at given position\n";
	cin>>pos>>num;
    insert_after_given_pos(num,pos);
    display_array();
    cout<<"insert after given element\n";
    cin>>num;
    insert_after_given_element(num);
    display_array();
    cout<<"delete given element\n";
    cin>>num;
    delete_given_element(num);
    display_array();
	return 0;
}