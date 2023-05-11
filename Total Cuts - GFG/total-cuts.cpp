//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n,int k,vector<int> &v){
        int c=0;
        int mi=INT_MAX,ma=INT_MIN;
        vector<int>m1,m2; //m1 max, m2 min
        for(int i=n-1;i>=1;i--){
            mi=min(mi,v[i]);
            m1.push_back(mi);
        }
        reverse(m1.begin(),m1.end());
        for(int i=0;i<n-1;i++){
            ma=max(ma,v[i]);
            m2.push_back(ma);
        }
        for(int i=0;i<n-1;i++){
            if(m1[i]+m2[i]>=k)c++;
        }
        return c;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends