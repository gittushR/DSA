class Solution {
public:
    void printS(int index, int sum, vector<int> arr, vector<vector<int>>&ans, vector<int> &ds,int k,
                int n){
        
        if(ds.size()==k ){
            if(sum==n)ans.push_back(ds);
            return;
        }
        if(index==arr.size())return;
        
        ds.push_back(arr[index]);
        sum+=arr[index];
        printS(index+1,sum,arr,ans,ds,k,n);
        
        ds.pop_back();
        sum-=arr[index];
        printS(index+1,sum,arr,ans,ds,k,n);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        
        vector<int> arr;
        for(int i=1;i<=9;i++)arr.push_back(i);
        
        vector<int> ds;
        
        printS(0,0,arr,ans,ds,k,n);
        return ans;
    }
    
};