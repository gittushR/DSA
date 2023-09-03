//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int kLevelSum(int k, string s) {
        // code here
        int level = -1;
        int sum = 0;
        string num = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                if(num != ""){
                    if(level == k){
                        sum+=stoi(num);
                    }
                    num = "";
                }
                level++;
                continue;
            }
            if(s[i] == ')'){
                level--;
                continue;
            }
           num+=s[i];
        
        }
        return sum;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>K;
        cin>>S;

        Solution ob;
        cout << ob.kLevelSum(K,S) << endl;
    }
    return 0;
}
// } Driver Code Ends