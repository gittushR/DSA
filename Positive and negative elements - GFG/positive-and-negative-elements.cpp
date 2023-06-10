//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
  public:
     vector<int> arranged(int arr[],int n){
         vector<int>pos,neg;
         for(int i=0;i<n;i++){
             if(arr[i]>0)
             pos.push_back(arr[i]);
             else
             neg.push_back(arr[i]);
         }
         int i=0,j=0;
         int k=0,l=1;
         vector<int>ans(n);
         while(i<pos.size() && j<neg.size()){
             ans[k]=pos[i++];
             k+=2;
             ans[l]=neg[j++];
             l+=2;
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
    int n,i,j;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    vector<int> ans;
    Solution obj;
    ans=obj.arranged(a,n);
    for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    }
}

// } Driver Code Ends