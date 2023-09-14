//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<int> DistinctSum(vector<int>nums){
        // Code here
            // do using tabulation and , it's a subset sum problem
            // knapsack tabulation
            //make a 2d table
            int tsum=0;
            int n=nums.size();
            for(auto it: nums) tsum+=it;
            vector<vector<bool>> t(n+1, vector<bool>(tsum+1));
            
            //do initialization
            for(int i=0; i<=n; i++) t[i][0]=true;
            for(int i=1; i<=tsum; i++) t[0][i]=false;
            
            //dual loop and do
            for(int i=1; i<=n; i++){
                for(int j=1; j<=tsum; j++){
                    //pick and not pick
                    if(nums[i-1]<=j){
                        t[i][j]= t[i-1][j] || t[i-1][j-nums[i-1]];
                    }
                    
                    else
                        t[i][j]= t[i-1][j];
                    
                }
            }
            
            //push all indices of t[][] that it true to ans vector and return
            vector<int> ans;
            for(int i=0; i<=tsum; i++){
                if(t[n][i]) ans.push_back(i);
            }
            return ans;
            
    }
        
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends