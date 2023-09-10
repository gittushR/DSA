//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
int delrow[8]={-2,-2,-1,-1,1,1,2,2};
int delcol[8]={-1,1,-2,2,-2,2,-1,1};
int mod=1e9+7;
long long bfs(int N,int M,int row,int col){
    long long ans=N*M;
    ans--;
    for(int i=0;i<8;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && nrow<N && ncol>=0 && ncol<M){
            ans--; 
        }
    }
    return ans;
}
long long numOfWays(int N, int M){
    long long ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int k=bfs(N,M,i,j);
            ans+=k;
            ans=ans%mod;
        }
    }
    return ans;
}