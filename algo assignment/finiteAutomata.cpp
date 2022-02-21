#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string txt,pat;
    cin>>txt>>pat;
    int M = pat.size();
    int N = txt.size();
    int TF[M + 1][256];

    int lps = 0, x;
 
    // first row set 0
    for (x = 0; x < 256; x++)
        TF[0][x] = 0;
    TF[0][pat[0]] = 1;
 
    // Fill entries in other rows
    for (int i = 1; i <= M; i++) {
        // Copy values from row at index lps
        for (x = 0; x < 256; x++)
            TF[i][x] = TF[lps][x];
 
        // Update the entry corresponding to this character
        TF[i][pat[i]] = i + 1;
 
        // Update lps for next row to be filled
        if (i < M)
            lps = TF[lps][pat[i]];
    }

    for (int i = 0,j=0; i < N; i++) {
        j = TF[j][txt[i]];
        if (j == M) {
            cout << "pattern found at index " << i - M + 1 << "\n";
        }
    }

    return 0;
}