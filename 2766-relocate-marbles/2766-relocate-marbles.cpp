class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int,int> currentMarbles;
        for(auto it:nums){
            currentMarbles[it]++;
        }
        for(int i=0;i<moveFrom.size();i++){
            int initPos=moveFrom[i];
            int finalPos=moveTo[i];
            if(initPos==finalPos)continue;
            int numberOfMarbles=currentMarbles[initPos];
            currentMarbles[finalPos]+=numberOfMarbles;
            currentMarbles[initPos]=0;
        }
        vector<int> ans;
        for(auto it:currentMarbles){
            if(it.second!=0){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};