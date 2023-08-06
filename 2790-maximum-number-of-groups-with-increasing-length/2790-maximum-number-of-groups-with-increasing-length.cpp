#define ll long long
class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        ll tot=0, cnt=1;
        for(auto &it : usageLimits){
            tot+=it;
            if(tot>=(cnt*(cnt+1)/2)) cnt++;
        }
        return cnt-1;
    }
};