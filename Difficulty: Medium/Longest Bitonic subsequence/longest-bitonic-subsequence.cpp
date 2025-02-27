//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution{
	public:
	int LongestBitonicSequence(int n, vector<int>&arr){
	    // code here
	    //int n=arr.size();
	    vector<int> dp1(n,1);
        vector<int> dp2(n,1);
    
        for(int i=0; i<=n-1; i++){
            for(int prev_index = 0; prev_index <=i-1; prev_index ++){
                if(arr[prev_index]<arr[i]){
                    dp1[i] = max(dp1[i], 1 + dp1[prev_index]);
                }
            }
        }
    
    // reverse the direction of nested loops
        for(int i=n-1; i>=0; i--){
            for(int prev_index = n-1; prev_index >i; prev_index --){
            
                if(arr[prev_index]<arr[i]){
                    dp2[i] = max(dp2[i], 1 + dp2[prev_index]);
                }
            }
        }
    
        int maxi = 0;
    
        for(int i=0; i<n; i++){
            if(dp1[i]>1&&dp2[i]>1){
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
            }
        }
        return maxi;
	}
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends