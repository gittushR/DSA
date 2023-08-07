class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<pair<int,pair<int,int>>> diff;
        for(int i=0;i<costs.size();i++){
            diff.push_back({costs[i][0]-costs[i][1],{costs[i][0],costs[i][1]}});
        }
        sort(diff.begin(),diff.end());
        int ans=0;
        for(int i=0;i<costs.size();i++){
            if(i<n/2){
                ans+=diff[i].second.first;
            }else{
                ans+=diff[i].second.second;
            }
        }
        return ans;
    }
};