//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int count=0,res=0,ans=0;
        for(int i=0;i<n;i++){
           if(a[i]==0){
               count++;
               res=max(res,count);
           }
           else{
               count--;
               if(count<0)
                count=0;
                ans++;
           }
        }
    return res+ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends