//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    
    vector<int> ans;
    int ind1= lower_bound(arr,arr+n,x)-arr;
    if(arr[ind1]!=x or n==0)return{-1,-1};
    ans.push_back(ind1);
    ind1=upper_bound(arr,arr+n,x)-arr-1;
    ans.push_back(ind1);
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends