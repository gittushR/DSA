//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
    //     // Code here
    //     vector<int> ds;
    //     printS(0,ds,arr,0,k);
    //     return true;
    // }
    // void printS(int ind, vector<int> &ds, vector<int> arr, int s, int k){
    //     if(ind==arr.size() && s==k){
    //         for(auto it: ds){
    //             cout<<it<<endl;
    //         }
    //         return;
    //     }
    //     ds.push_back(arr[ind]);
    //     s+=arr[ind];
    //     printS(ind+1,ds,arr,s,k);
        
    //     s-=arr[ind];
    //     ds.pop_back();
    //     printS(ind+1,ds,arr,s,k);
    // }
    bool checkSubsequenceSum(int n, vector<int>& a, int k) {

        sort(a.begin(),a.end());

        bool v[k+1];

        memset(v,false,sizeof(v));

        v[0]=true;queue<int>q;int c;

        for(int i=0;i<n;i++)

        {

            if(a[i]==0)continue;

            if(a[i]>k)return false;

            if(a[i]==k) return true;

            for(int j=0;j<=k-a[i];j++)

            {

                if(v[j]==true)q.push(j);

            }

            while(!q.empty())

            {

                c=q.front();

                q.pop();

                v[c+a[i]]=true;

            }

            if(v[k]==true) return true;

        }

        return false;

    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends