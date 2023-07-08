//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int nums[], int n, int X)
    {
        //Your Code Here
        sort(nums,nums+n);
        for(int i=0;i<n-2;i++){
            //   if(i>0 && (nums[i]==nums[i-1]) )continue;
               int l=i+1, r= n-1;
               while(l<r){
                   int sum =nums[i]+nums[l]+nums[r];
                   
                   if(sum<X) l++;
                   else if(sum>X)r--;
                   else {
                       return true;
                   }
               }
        }
       
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends