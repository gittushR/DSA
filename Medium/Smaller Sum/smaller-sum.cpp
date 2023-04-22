//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    #define ll long long
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<int>A(n);
        A = arr;
        sort(A.begin(),A.end());
        vector<ll>pref(n,0);
        for(int i = 0; i < n; i++){
            if(i == 0){
                pref[i] = A[i];
            }
            else{
                pref[i] = pref[i-1] + A[i];
            }
        }
        vector<ll>ans(n,0);
        for(int i = 0; i < n; i++){
            int start = 0,end = n-1,mid,idx = -1;
            while(start <= end){
                mid = start + (end - start) / 2;
                if(A[mid] < arr[i]){
                    idx = mid;
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
            if(idx != -1){
                ans[i] = pref[idx];
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends