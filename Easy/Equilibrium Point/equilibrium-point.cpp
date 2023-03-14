//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        // Your code here
        int i;
        int prevsum=0;
        int remsum=0;
        int Ts=0;
        for(i=0;i<n;i++)
        {
            Ts=Ts+a[i];
        }
        
        for(i=0;i<n;i++)
        {
            remsum=Ts-a[i]-prevsum;
            
            if (prevsum==remsum)
            {
                return (i+1);// return i+1 th iteration if there is one equilibrium point;
            }
            prevsum=prevsum+a[i];
            
        }
        return -1;// if there is no equillibrium point;
    }
};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends