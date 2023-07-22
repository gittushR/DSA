//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

//User function template in C++

class Solution 
{
    public:
    int fn(int pages,int arr[],int n){
        int numbStudents=1;
        long long pagesperStudent=0;
        for(int i=0;i<n;i++){
            if(pagesperStudent+arr[i]<=pages){
                pagesperStudent+=arr[i];
            }else{
                numbStudents++;
                pagesperStudent=arr[i];
            }
        }
        return numbStudents;
    }
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if(m>n)return -1;
        int maxi=-1e8,sum=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            sum+=arr[i];
        }
        int low=maxi,high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            int students=fn(mid,arr,n);
            if(students>m){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
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