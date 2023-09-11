class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        map<int,vector<int>> adj;
        for(int i=0;i<arr.size();i++){
            adj[arr[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto it:adj){
            int sizeofGroup=it.first;
            vector<int> elements=it.second;
            int n=elements.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                temp.push_back(elements[i]);
                if(temp.size()==sizeofGroup){
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
};