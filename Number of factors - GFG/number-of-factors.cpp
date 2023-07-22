//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int countFactors(int n){
        //code here
        int ans=0;
        for (int i=1; i<=sqrt(n); i++)
        {
            if (n%i == 0)
            {
            // If divisors are equal, print only one
                if (n/i == i)
                    ans++;
      
                else // Otherwise print both
                    ans+=2;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.countFactors(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends