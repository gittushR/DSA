//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int count_trip_withsum_less_than_equalToo_X( int arr[], int n, int X){
       sort(arr, arr+n);
       int count = 0;
       for(int i = 0; i<n-2; i++){
           int j = i+1, k = n-1;
           while(j<k){
               if(arr[i]+arr[j]+arr[k] <= X){
                   count += k-j;
                   j++;
               }
               else k--;
           }
       }
       return count;
   }
   int countTriplets(int Arr[], int N, int L, int R) {
       return (count_trip_withsum_less_than_equalToo_X( Arr, N, R)
       - count_trip_withsum_less_than_equalToo_X( Arr, N, L-1) );
   }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}
// } Driver Code Ends