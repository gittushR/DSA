class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int s=potions.size();
        for(int i=0;i<spells.size();i++){
            long long ans=ceil((double) success/(double) spells[i]);
            auto a=lower_bound(potions.begin(),potions.end(),ans)-potions.begin();
            spells[i]=(s-a);
        }
        return spells;
    }
};