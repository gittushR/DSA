//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    void printS(int index, int sum, vector<int> arr, vector<vector<int>>&ans, vector<int> &ds,int k,
                int n){
        
        if(ds.size()==k ){
            if(sum==n)ans.push_back(ds);
            return;
        }
        if(index==arr.size())return;
        
        ds.push_back(arr[index]);
        sum+=arr[index];
        printS(index+1,sum,arr,ans,ds,k,n);
        
        ds.pop_back();
        sum-=arr[index];
        printS(index+1,sum,arr,ans,ds,k,n);

    }
    vector<vector<int>> combinationSum(int k, int n) {
        vector<vector<int>> ans;
        
        vector<int> arr;
        for(int i=1;i<=9;i++)arr.push_back(i);
        
        vector<int> ds;
        
        printS(0,0,arr,ans,ds,k,n);
        return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends