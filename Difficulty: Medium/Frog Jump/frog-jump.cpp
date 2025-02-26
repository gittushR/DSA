//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int index, vector<int> &heights,vector<int> &memo){
        if(index==0)return 0;
        if(memo[index]!=-1)return memo[index];
        int left = f(index-1,heights,memo) + abs(heights[index]-heights[index-1]);
        int right=1e9;
        if(index>1)right = f(index-2,heights,memo)+abs(heights[index]-heights[index-2]);
        return memo[index] = min(left,right);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int> memo(n,-1);
        return f(n-1, height,memo);
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends