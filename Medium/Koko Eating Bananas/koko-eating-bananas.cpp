//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fn(vector<int> arr, int x){
        int totalHours=0;
        for(int i=0;i<arr.size();i++){
            totalHours+=ceil((double)arr[i]/(double)x);
        }
        return totalHours;
    }
    int Solve(int n, vector<int>& piles, int h) {
        // Code here
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            int totalHours=fn(piles,mid);
            if(totalHours<=h){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends