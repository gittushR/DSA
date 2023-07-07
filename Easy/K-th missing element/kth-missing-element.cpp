//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
    set<int>s(a, a+n);
    
    for(int i= a[0];i<=a[n-1];i++) {
        if(s.find(i) == s.end()){
            k--;
            
            if(k <= 0){
                return i;
            }
        }
    }
    return -1;
}