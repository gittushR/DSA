//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int ind,int k, vector<int> &arr,vector<int>&memo){
        if(ind==0)return 0;
        if(memo[ind]!=-1)return memo[ind];
        int min_steps = INT_MAX;
        for(int j=1;j<=k;j++){
            int currStep;
            if(ind-j>=0)currStep = f(ind - j,k,arr,memo) + abs(arr[ind]-arr[ind - j]);
            min_steps = min(min_steps,currStep);
        }
        return memo[ind]=min_steps;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> memo(n,-1);
        return f(n-1,k,arr,memo);
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends