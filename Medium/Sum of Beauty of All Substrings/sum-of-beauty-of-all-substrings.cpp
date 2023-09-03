//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beauty(int hashMap[]){
        int mf=-1e9,lf=1e9;
        for(int i=0;i<26;i++){
            mf=max(mf,hashMap[i]);
            if(hashMap[i]>0)lf=min(lf,hashMap[i]);
        }
        return mf-lf;
    }
    int beautySum(string s) {
        // Your code goes here
        int res=0;
        for(int i=0;i<s.size();i++){
            int hashMap[26]={0};
            for(int j=i;j<s.size();j++){
                hashMap[s[j]-'a']++;
                res+=beauty(hashMap);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends