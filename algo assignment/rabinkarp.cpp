#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    const int p = 31; 
    const int m = 1e9 + 9;


    //power calculation
    vector<long long> p_pow(max(s.size(), t.size())); 
    p_pow[0] = 1; 
    for (int i = 1; i < p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;
    
    //hash calculation
    vector<long long> h(t.size() + 1, 0); 
    for (int i = 0; i < t.size(); i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 

    //hash calculation
    for (int i = 0; i < s.size(); i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    //comparison 
    vector<int> occurences;
    for (int i = 0; i + s.size() - 1 < t.size(); i++) { 
        long long cur_h = (h[i+s.size()] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }

    cout<<"\n";
    for (int i = 0; i < occurences.size(); ++i)
    {
    	cout<<occurences[i]<<" ";
    }
    cout<<"\n";
	return 0;
}