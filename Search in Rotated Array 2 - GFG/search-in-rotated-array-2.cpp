//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int n, vector<int>& arr, int k) {
        // Code here
        int low=0,high=n-1;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(arr[mid]==k)return true;
            if(arr[mid]==arr[low] and arr[mid]==arr[high]){
                high--;
                low++;
                continue;
            }
            if(arr[mid]==k)return true;
            else if(arr[low]<=arr[mid]){//left sorted
                if(k<=arr[mid] and k>=arr[low])high=mid-1;
                else low=mid+1;
            }else{
                if(k<=arr[high] and k>=arr[mid])low=mid+1;
                else high=mid-1;
            }
        }
        return false;
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
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends