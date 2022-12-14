//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len){
        long long  vol=0;
        int i=0;
        int j=len-1;
        while(i<j){
            long long h=min(A[i], A[j]);
            vol=max(vol, h*(j-i));
            while(h>=A[i]&&i<j){
                i++;
            }
            while(h>=A[j]&&i<j){
                j--;
            }
        }
        return vol;
    
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends