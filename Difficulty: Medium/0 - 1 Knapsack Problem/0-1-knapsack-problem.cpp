//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fn(int ind, int cap, vector<int>&val, vector<int>&wt,vector<vector<int>> &memo){
        if(ind==0){
            if(cap>=wt[0])return val[0];
            return 0;
        }
        if(memo[ind][cap]!=-1)return memo[ind][cap];
        int notTake = fn(ind-1,cap,val,wt,memo);
        int take=INT_MIN;
        if(cap>=wt[ind])take = val[ind] + fn(ind-1,cap-wt[ind],val,wt,memo);
        return memo[ind][cap]= max(take,notTake);
    }
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> memo(n,vector<int>(capacity+1,-1));
        return fn(n-1,capacity,val,wt,memo);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends