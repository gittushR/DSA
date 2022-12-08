//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool isPossible(int arr[], int n, int m, int mid){
        int pageSum=0;
        int studentNum=1;
        
        for(int i=0;i<n;i++){
            if(pageSum+arr[i]<=mid){
                pageSum+=arr[i];
            }else{
                studentNum++;
                if(studentNum>m || arr[i]>mid)return false;
                pageSum=arr[i];
            }
        }
        return true;
    }
    
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
        }
        int s=0,e=sum;
        int mid=(s+e)/2;
        int ans =-1;
        if(N<M)return -1;
        while(s<=e){
            if (isPossible(A, N, M, mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends