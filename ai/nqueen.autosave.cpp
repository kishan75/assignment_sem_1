#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int, int> pii;
#define mp make_pair
#define fs first
#define ss second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define N 30

int current_state[N][N];
int temp_state[N][N];
int initial_pos[N];

template <size_t size_x, size_t size_y>
void set_random(int (&arr)[size_x][size_y])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			current_state[i][j]=0;
			temp_state[i][j]=0;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		int ranNumber=rand()%N;
		arr[ranNumber][i]=1;
		initial_pos[i]=ranNumber;
	}
}

template <size_t size_x, size_t size_y>
void printBoard(int (&arr)[size_x][size_y])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n---------\n";
}

template <size_t size_x, size_t size_y>
int getAttackValue(int (&arr)[size_x][size_y],pii queen_pos)
{
	int attacks=0;
	for(int i=0;i<N;i++)
	{
		if(queen_pos.ss==i)
			continue;
		attacks+=arr[queen_pos.fs][i];
	}
	for(int i=0;i<N;i++)
	{
		if(queen_pos.fs==i)
			continue;
		attacks+=arr[i][queen_pos.ss];
	}
	for(int i=1;queen_pos.fs-i>=0&&queen_pos.ss-i>=0;i++)
	{
		attacks+=arr[queen_pos.fs-i][queen_pos.ss-i];
	}
	for(int i=1;queen_pos.fs+i<N&&queen_pos.ss+i<N;i++)
	{
		attacks+=arr[queen_pos.fs+i][queen_pos.ss+i];
	}
	for(int i=1;queen_pos.fs-i>=0&&queen_pos.ss+i<N;i++)
	{
		attacks+=arr[queen_pos.fs-i][queen_pos.ss+i];
	}
	for(int i=1;queen_pos.ss-i>=0&&queen_pos.fs+i<N;i++)
	{
		attacks+=arr[queen_pos.fs+i][queen_pos.ss-i];
	}
	return attacks;
} 

void init_code()
{
	fast
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void copyToTempArray()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			temp_state[i][j]=current_state[i][j];
		}
	}
}

void copyToCurrentStateArray()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			current_state[i][j]=temp_state[i][j];
		}
	}
}

void hillClimb()
{
	for(int i=0;i<N;i++)
	{
		int pos=initial_pos[i];
		int current_attack=getAttackValue(current_state,{pos,i});
		copyToTempArray();
		temp_state[pos][i]=0;
		int temp_attackValue;
		for (int j = 0; j < N; ++j)
		{
			if(j==pos)
				continue;
			temp_state[j][i]=1;
			temp_attackValue=getAttackValue(temp_state,{j,i});
			if (temp_attackValue<current_attack)
			{
				current_attack=temp_attackValue;
				copyToCurrentStateArray();
				initial_pos[i]=j;
			}
			temp_state[j][i]=0;
		}
		// printBoard(current_state);
	}
}

void solve()
{
	set_random(current_state);
	printBoard(current_state);
	int finalAttack=0;
	int attack=0;
	do 
	{
		finalAttack=0;
		attack=0;
		for(int i=0;i<N;i++)
			attack+=getAttackValue(current_state,{initial_pos[i],i});
		hillClimb();
		for(int i=0;i<N;i++)
			finalAttack+=getAttackValue(current_state,{initial_pos[i],i});
		cout<<"\n attacking pair count ==> "<<finalAttack<<"\n";
		if(finalAttack==0)
		{
			printBoard(current_state);
			break;
		}
		if(finalAttack>=attack)
		{
		  cout<<"\n--restarting algorithm--\n";
			set_random(current_state);
			finalAttack=0;
			attack=1;
		}
	}while(finalAttack<attack);
}

int main()
{
 	init_code();
	srand(time(0));
	solve();
	return 0;
}