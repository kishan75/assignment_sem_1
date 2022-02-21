/*input
id*(id+id)+id
*/
#include<bits/stdc++.h>
using namespace std;
string required;
int pos=0;
string current="";

string E(string current);
string T(string current);
string F(string current);
string Tbar(string current);
string Ebar(string current);

string F(string current)
{
	cout<<" exploring F -> (E)|id               "<<current<<"\n";
    string temp = current+"(";
    temp+=E(current);
    temp+=")";
    if(temp==required)
     {
        cout<<"parsing done ";
        exit(0);
     }
      if(temp.size()>required.size())
     {
       return current+"id";
     }
     if(temp==required)
     {
        cout<<"parsing done ";
        exit(0);
     }
     if(required[current.size()]=='i')
     return current+"id"; 
     else
        return current+temp;
}

string T(string current)
{
	cout<<" exploring T -> FT'                  "<<current<<"\n";
    return current+F(current)+Tbar(current);
}

string E(string current)
{
    cout<<" exploring E -> TE'                  "<<current<<"\n";
   return current +T(current)+Ebar(current);
}

string Tbar(string current)
{
	cout<<" exploring T' -> *FT'|epsilon        "<<current<<"\n";
   	string temp = current+"*";
     if (temp.size()>required.size())
     {
         return current;
     }
    temp+=F(current);
     if (temp.size()>required.size())
     {
         return current;
     }
    temp+=Tbar(current);
     if (temp.size()>required.size())
     {
         return current;
     }
     if(temp==required)
     {
        cout<<"parsing done ";
        exit(0);
     }
     return temp;
}

string Ebar(string current)
{
    cout<<" exploring E' -> +TE'|epsilon        "<<current<<"\n";
     string temp = current+"+";
     if (temp.size()>required.size())
     {
         return current;
     }
     temp+=T(current);
     if (temp.size()>required.size())
     {
         return current;
     }
     temp+=Ebar(current);
     if (temp.size()>required.size())
     {
         return current;
     }
     if(temp==required)
     {
        cout<<"parsing done ";
        exit(0);
     }
     return temp;
}

int main()
{
   cin>>required;
   cout<<E(current)<<"";
   return 0;
}