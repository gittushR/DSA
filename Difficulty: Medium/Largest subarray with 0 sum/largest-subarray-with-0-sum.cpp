//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        unordered_map<long long, int> prevSum;
        long long sum=0;int maxLen=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0){
                maxLen=max(maxLen,i+1);
            }
            //long long rem=sum-k;
            if(prevSum.find(sum)!=prevSum.end()){
                int len=i-prevSum[sum];
                maxLen=max(maxLen, len);
            }
            if(prevSum.find(sum)==prevSum.end()){
                prevSum[sum]=i;
            }
        }
        return maxLen;
    }
};
/*


class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        int k=0;
        unordered_map<long long, int> prevSum;
        long long sum=0;int maxLen=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum==k){
                maxLen=max(maxLen,i+1);
            }
            long long rem=sum-k;
            if(prevSum.find(rem)!=prevSum.end()){
                int len=i-prevSum[rem];
                maxLen=max(maxLen, len);
            }
            if(prevSum.find(sum)==prevSum.end()){
                prevSum[sum]=i;
            }
        }
        return maxLen;
    }
};
*/

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends