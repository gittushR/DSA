class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n, 0);
        set<pair<int, int>> roadset;
        
        for (auto& road : roads) {
            indegree[road[0]]++;
            indegree[road[1]]++;
            roadset.insert({road[0], road[1]});
            roadset.insert({road[1], road[0]});
        }

        int max_rank = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int rank = indegree[i] + indegree[j];
                if (roadset.find({i, j}) != roadset.end()) {
                    rank--;
                }
                max_rank = max(max_rank, rank);
            }
        }

        return max_rank;
    }
};