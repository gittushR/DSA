//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSumLis(int arr[], int n) {
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }
        int dp[2][n];//dp[0]for storing the length of longest Increasing subsequence at that ind and
        //dp[1] for storing the min sum of subsequence upto that particular ind
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
            dp[1][i] = arr[i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    if (dp[0][i] < dp[0][j] + 1) {
                        dp[0][i] = dp[0][j] + 1;
                        dp[1][i] = dp[1][j]
                                   + arr[i];
                    }
                    else if (dp[0][i]
                             == dp[0][j] + 1) {
                        dp[1][i]
                            = min(dp[1][i],
                                  dp[1][j]
                                      + arr[i]);
                    }
                }
            }
        }
        int maxm = 0;
        int subtractSum = 0;
        // Find the sum that need to be subtracted from total sum
        //among all the LIS and their sums, we find that particular LIS with the minimum sum
        for (int i = 0; i < n; i++) {
            if (dp[0][i] > maxm) {
                maxm = dp[0][i];
                subtractSum = dp[1][i];
            }
            else if (dp[0][i] == maxm) {
                subtractSum = min(subtractSum,
                                  dp[1][i]);
            }
        }
     
        // Return the sum
        return totalSum - subtractSum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int Arr[n];
        for (int i = 0; i < n; i++) cin >> Arr[i];
        Solution obj;
        cout << obj.maxSumLis(Arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends