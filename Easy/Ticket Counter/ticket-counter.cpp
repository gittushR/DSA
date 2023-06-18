//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int k) {
        // code here
        int s=1,e=N;
        // cout<<"now s = "<<s<<endl;
        // cout<<"now e = "<<e<<endl;
        while(s != e)
        {
            if(s + k < e)
            {
                s = s+k;
                // cout<<"now s = "<<s<<endl;
            }
            else
            {
                return e;
            }
            
            if( e - k > s)
            {
                e = e-k;
                // cout<<"now e = "<<e<<endl;
            }
            else
            {
                return s;
            }
        }
        return s;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends