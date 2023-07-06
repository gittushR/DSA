//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int nums[], int low, int high)
    {
        // Your code here
        int mid,ans=1e9;
        while(low<=high){
            mid=low+(high-low)/2;
            // if(nums[mid]<nums[mid-1] and nums[mid]<nums[mid+1])return mid;
            if(nums[low]<=nums[mid]){//left sorted
                ans=min(ans,nums[low]);
                low=mid+1;
            }else{//right sorted
                ans=min(ans,nums[mid]);
                high=mid-1;
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
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}
// } Driver Code Ends