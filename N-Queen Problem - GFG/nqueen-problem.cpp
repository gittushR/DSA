//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> board;
        vector<int> leftrow(n,0), diagD(2*n-1,0), diagU(2*n-1,0);
        solve(0,ans,board,leftrow,diagD,diagU,n);
        return ans;
    }
    void solve(int col, vector<vector<int>>&ans, vector<int> &board, vector<int> left, vector<int> &diagD,
    vector<int> &diagU, int n){
        
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(left[row]==0 && diagD[row+col]==0 && diagU[n-1+col-row]==0){
                board.push_back(row+1);
                left[row]=1;
                diagD[row+col]=1;
                diagU[n-1+col-row]=1;
                solve(col+1,ans,board,left,diagD,diagU,n);
                board.pop_back();
                left[row]=0;
                diagD[row+col]=0;
                diagU[n-1+col-row]=0;
            }
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends