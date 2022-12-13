//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans;
        helper(0,0,ans,arr,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
    void helper(int index, int sum, vector<int> &ans, vector<int> arr, int n){
        if(index==n){
            ans.push_back(sum);
            return;
        }
        helper(index+1,sum+arr[index],ans,arr,n);
        
        helper(index+1,sum,ans,arr,n);
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends