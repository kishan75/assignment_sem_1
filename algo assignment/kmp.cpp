#include<bits/stdc++.h>
using namespace std;

vector<int> createlps(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    string s,pat;
    cin>>s>>pat;
    vector<int> lps = createlps(pat); 
    int i = 0;  
    int j = 0; 
    while (i < s.size()) { 
        if (pat[j] == s[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == pat.size()) { 
            cout<<"\n Found pattern at "<< i - j<<"\n"; 
            j = lps[j - 1]; 
        } 
        else if (i < s.size() && pat[j] != s[i]) {
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
	return 0;
}