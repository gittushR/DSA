//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int day, int last, vector<vector<int>> &arr,vector<vector<int>> &memo){
        if(day==0){
            int maxi=0;
            for(int i=0;i<3;i++){
                if(last!=i) {
                    maxi=max(maxi,arr[0][i]);
                }
            }
            return maxi;
        }
        if(memo[day][last]!=-1)return memo[day][last];
        int maxi=0;
        for(int i=0;i<3;i++){
            if(last!=i){
                int points = arr[day][i] + f(day-1,i,arr,memo);
                maxi=max(maxi,points);
            }
        }
        return memo[day][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        vector<vector<int>> memo(n,vector<int>(4,-1));
        return f(n-1,3,arr,memo);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends