//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    bool checkPoss(string s1, string s2){
        if(abs(s1.size()-s2.size())!=1)return false;
        int first=0,second=0;
        while(first<s1.size()){
            if(s1[first]==s2[second]){
                first++;second++;
            }else{
                first++;
            }
        }
        if(first==s1.size() and second==s2.size())return true;
        else return false;
    }
    bool comp(string &s1, string &s2){
        return s1.size()<s2.size();
    }
  public:
  static bool com(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    int longestChain(int n, vector<string>& words) {
        // Code here
        sort(words.begin(),words.end(),com);
        vector<int> dp(n,1);
        int maxi=1;
        for(int ind=0;ind<n;ind++){
            for(int prevInd=0;prevInd<ind;prevInd++){
                if(checkPoss(words[ind],words[prevInd]) and 1+dp[prevInd]>dp[ind]){
                    dp[ind]=1+dp[prevInd];
                }
            }
            maxi=max(maxi,dp[ind]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends