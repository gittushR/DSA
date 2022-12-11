//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long int sum=0;
        if(n<=1) return arr[0];
        for(int i=0;i<n;i++)sum+=arr[i];
        
        long long int s=0,e=sum;
        long long int mid=s+(e-s)/2;
        
        long long int ans=-1;
        while(s<=e){
            if (isPossible(arr,n,k,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
    bool isPossible(int arr[],int n,int k, long long int mid){
        long long int painter=1;
        long long int lengthSum=0;
        for(int i=0;i<n;i++){
            if(lengthSum+arr[i]<=mid){
                lengthSum+=arr[i];
            }else{
                painter++;
                if(painter>k || arr[i]>mid)return false;
                lengthSum=arr[i];
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends