//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest(int arr[], int n, int target) 
    { 
       int index= lower_bound(arr,arr+n,target)-arr;
       if(index==-1)
       return arr[n-1];
       else if(index-1>=0)
           return (abs(target-arr[index-1])<abs(target-arr[index]))?arr[index-1]:arr[index];
       else
       return arr[index];
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,target;
        cin>>n>>target;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(arr,n,target)<<endl;
    }
}

// } Driver Code Ends