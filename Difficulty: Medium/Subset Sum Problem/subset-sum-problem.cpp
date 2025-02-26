//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    bool fn(int ind, int target, vector<int> &arr,vector<vector<int>> memo){
        if(ind==0)return (arr[0]==target);
        if(target==0)return true;
        if(memo[ind][target]!=-1)return memo[ind][target];
        bool notTake = fn(ind-1, target, arr,memo);
        bool take = false;
        if(target>=arr[ind])take = fn(ind-1,target-arr[ind],arr,memo);
        return memo[ind][target]= take or notTake;
    }
    bool isSubsetSum(vector<int>& arr, int t) {
        // code here
        int n=arr.size();
        vector<vector<bool>> memo(n,vector<bool>(t+1,0));
        for(int i=0;i<n;i++)memo[i][0]=true;
        memo[0][arr[0]]=true;
        
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=t;target++){
                bool notTake = memo[ind-1][target];
                bool take = false;
                if(target>=arr[ind])take = memo[ind-1][target-arr[ind]];
                memo[ind][target]= (take or notTake);
            }
        }
        return memo[n-1][t];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends