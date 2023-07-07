//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int f(int capacity, int arr[],int n){
      int days=1,load=0;
      for(int i=0;i<n;i++){
          if(load+arr[i]>capacity){
              days++;
              load=arr[i];
          }else{
              load+=arr[i];
          }
      }
      return days;
  }
    int leastWeightCapacity(int arr[], int n, int D) {
        // code here
        int sum=0;
        int maxi=-1e8;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxi=max(maxi,arr[i]);
        }
        int low=maxi,high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            int daysReqd=f(mid,arr,n);
            if(daysReqd<=D){
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
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends