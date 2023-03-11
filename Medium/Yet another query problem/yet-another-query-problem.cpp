//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:

    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {

        // code here

        vector<int> ans;

        vector<int> rev_pref(N);

        map<int,int> mp;

        for(int i=N-1; i>-1; --i) {

            mp[A[i]]++;

            rev_pref[i]=mp[A[i]];

        }

        for(int i=0; i<num; ++i) {

            int ans1=0;

            for(int j=Q[i][0]; j<=Q[i][1]; ++j) {

                if(rev_pref[j]==Q[i][2]) {

                    ans1++;

                }

            }

            ans.push_back(ans1);

        }

        return ans;

    }

};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends