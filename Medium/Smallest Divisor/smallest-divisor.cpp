//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int fn(int divisor,vector<int> arr){
        int count=0;
        for(int i=0;i<arr.size();i++){
            count+=ceil((double)arr[i]/divisor);
        }
        return count;
    }
    int smallestDivisor(vector<int>& nums, int k) {
        // Write your code here.
        int maxi=-1e8;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int low=1,high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            int totalDivisions=fn(mid,nums);
            if(totalDivisions<=k){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends