/*input
id*(id+id)+id
*/
#include<bits/stdc++.h>
using namespace std;
string required;
int pos=0;
string current="";

void E();
void T();
void F();
void Tbar();
void Ebar();

void F()
{
	cout<<" exploring F -> (E)|id               "<<current<<"\n";
	if(required[pos]=='(')
	{
      pos++;
      current+="(";
      E();
      pos++;
      current+=")";
	}	
	else
	{
		if (required[pos]=='i')
		{
			pos+=2;
			current+="id";
		}
		else
		{
			cout<<"pattern didn't match after this string : "<<current;
			exit(0);
		}
	}
}

void T()
{
	cout<<" exploring T -> FT'                  "<<current<<"\n";
   F();
   Tbar();
}

void E()
{
    cout<<" exploring E -> TE'                  "<<current<<"\n";
   T();
   Ebar();
}

void Tbar()
{
	cout<<" exploring T' -> *FT'|epsilon        "<<current<<"\n";
   if (required[pos]=='*')
   {
   	pos++;
   	current+="*";
   	F();
    Tbar();
   }
}

void Ebar()
{
    cout<<" exploring E' -> +TE'|epsilon        "<<current<<"\n";
   if(required[pos]=='+')
   {
   	 pos++;
     current+="+";
     T();
     Ebar();
   }
}

int main()
{
   cin>>required;
   E();
   cout<<"parsing done";
   return 0;
}