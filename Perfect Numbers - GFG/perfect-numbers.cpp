//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  int isPerfectNumber(long long N) {
        //base case
        if(N==1)return 0;
        long long sum=1;
        for(long long i=2;i<=sqrt(N);i++){
        if(N%i==0){
         sum+=i;
         if(N/i!=i) //handing for perfect squares---avoiding double addition
         sum+=N/i;//if i is a factor of N then quotient of N/i is also a factor of N.
            }
        }
        if(N==sum)return 1;
        else return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends