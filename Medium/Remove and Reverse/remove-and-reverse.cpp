//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        int n=S.size();
        unordered_map<char,int> freq;
        for(int i=0;i<S.size();i++){
            freq[S[i]]++;
        }
        int dir=0;
        int st=0;
        int end=n-1;
        while(st<=end){
            if(dir==0){
                if(freq[S[st]]==1){
                    st++;
                }else{
                    freq[S[st]]--;
                    S[st]='@';
                    st++;
                    dir=1;
                }
            }else{
                if(freq[S[end]]==1){
                    end--;
                }
                else{
                    freq[S[end]]--;
                    S[end]='@';
                    end--;
                    dir=0;
                }
            }
        }
        string ans;
        for(int i=0;i<n; i++){
            if(S[i]!='@'){
                ans.push_back(S[i]);
            }
        }
        
        if(dir==1){
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends