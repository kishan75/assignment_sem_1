#include<bits/stdc++.h>
#define MAX 20
using namespace std;

const int n=4;

void multiply(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int n){
    if(n == 1){
        C[0][0] = A[0][0] * B[0][0];
        return;
    } else {
        n /= 2;
        vector<vector<int>> X(n, vector<int>(n));
        vector<vector<int>> Y(n, vector<int>(n));

        vector<vector<int>> P(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                X[i][j] = A[i][j] + A[i+n][j+n];
                Y[i][j] = B[i][j] + B[i+n][j+n];
            }
        }
        multiply(X, Y, P, n);

        vector<vector<int>> Q(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                X[i][j] = A[i+n][j] + A[i+n][j+n];
                Y[i][j] = B[i][j];
            }
        }
        multiply(X, Y, Q, n);

        vector<vector<int>> R(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                X[i][j] = A[i][j];
                Y[i][j] = B[i][j+n] - B[i+n][j+n];
            }
        }
        multiply(X, Y, R, n);

        vector<vector<int>> S(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                X[i][j] = A[i+n][j+n];
                Y[i][j] = B[i+n][j] - B[i][j];
            }
        }
        multiply(X, Y, S, n);

        vector<vector<int>> T(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                X[i][j] = A[i][j] + A[i][j+n];
                Y[i][j] = B[i+n][j+n];
            }
        }
        multiply(X, Y, T, n);

        vector<vector<int>> U(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                X[i][j] = A[i+n][j] - A[i][j];
                Y[i][j] = B[i][j] + B[i][j+n];
            }
        }
        multiply(X, Y, U, n);

        vector<vector<int>> V(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                X[i][j] = A[i][j+n] - A[i+n][j+n];
                Y[i][j] = B[i+n][j] + B[i+n][j+n];
            }
        }
        multiply(X, Y, V, n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                C[i][j] = P[i][j] + S[i][j] - T[i][j] + V[i][j];
                C[i][j+n] = R[i][j] + T[i][j];
                C[i+n][j] = Q[i][j] + S[i][j];
                C[i+n][j+n] = P[i][j] + R[i][j] - Q[i][j] + U[i][j];
            }
        }
    }
}


int main(){
    int n;

    cout<<"dimension of matrics \n";
    cin>>n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    vector<vector<int>> C(n, vector<int>(n));

    cout<<"matrix A's content \n";
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>A[i][j]; 

    cout<<"matrix B's content \n";
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>B[i][j];

    multiply(A, B, C, n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<C[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
