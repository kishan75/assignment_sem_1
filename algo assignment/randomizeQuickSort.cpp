/*input
5
1 2 0 4 6
*/
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int arr[10000];

int part (int low, int high) 
{ 
	int randPos = (rand()%(high-low+1))+low;
	swap(arr[randPos],arr[high]);
    int pivot = arr[high];  
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++; 
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
void quick(int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = part(low, high); 
        quick(low, pi - 1); 
        quick(pi + 1, high); 
    } 
} 

int main()
{
  fast
   int n;
   cin>>n;
   for (int i = 0; i < n; ++i)
   {
   	cin>>arr[i];
   }
   quick(0,n-1);
   cout<<"sorted array \n";
   for (int i = 0; i < n; ++i)
   {
   	  cout<<arr[i]<<" ";
   }
   cout<<"\n";
  return 0;
}