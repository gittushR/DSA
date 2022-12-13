//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void helper(int ind, vector<vector<int>> &ans, vector<int> &ds,int sum, vector<int> arr){
        if(sum<0)return;
        if(ind==arr.size()){
            if(sum==0){
                ans.push_back(ds);
            }
            return;
        }
        
            ds.push_back(arr[ind]);
            helper(ind,ans,ds,sum-arr[ind],arr);
            ds.pop_back();
        helper(ind+1,ans,ds,sum,arr);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>> ans;
        vector<int> ds;
        set<int> st;
        for(auto it:A){
            st.insert(it);
        }
        vector<int> Arr;
        for(auto it: st){
            Arr.push_back(it);
        }
        helper(0,ans,ds,B,Arr);
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    //  void helper(vector<vector<int>> &ans, vector<int> &arr,int target,int index,vector<int> &temp){
    //     if(target<0){
    //         return ;
    //     }
    //     if(index==arr.size()){
    //         if(target==0){
    //             ans.push_back(temp);
    //         }
    //         return;
    //     }
    //     temp.push_back(arr[index]);
    //     helper(ans,arr,target-arr[index],index,temp);
    //     temp.pop_back();
    //     helper(ans,arr,target,index+1,temp);              
    // }
    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     vector<vector<int>> ans;
    //     vector<int> temp;
    //     helper(ans,candidates,target,0,temp);
    //     return ans;
    // }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends