class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;
        map<int,int> mp;
        sort(ans.begin(),ans.end());
        int rank=1;
        for(int i=0;i<arr.size();i++){
            if(mp.find(ans[i])!=mp.end())continue;
            mp[ans[i]]=rank++;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};
