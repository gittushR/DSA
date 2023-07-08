class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> pairs;
        for(int i=1;i<weights.size();i++){
            pairs.push_back(weights[i]+weights[i-1]);
        }
        sort(pairs.begin(),pairs.end());
        long long mini=0,maxi=0;
        for(int i=0;i<k-1;i++){
            mini+=pairs[i];
            maxi+=pairs[pairs.size()-1-i];
        }
        return maxi-mini;
    }
};