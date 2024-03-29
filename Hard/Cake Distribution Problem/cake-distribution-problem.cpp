//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
      int maxSweetness(vector<int>& a, int n, int k) {
        int l = 1;
        int h = 0;
        for(int i = 0; i < n; i++){
            h += a[i];
        }
        while(l <= h){
            int mid = l + (h-l)/2;
            int piece = 0;
            int sweet = 0;
            for(int i = 0; i < n; i++){
                sweet += a[i];
                if(sweet >= mid){
                    piece++;
                    sweet = 0;
                }
            }
            if(piece < k+1){
                h = mid  - 1;
            }
            else{
                // ans = mid;
                l = mid+1;
            }
        }
        return h;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends