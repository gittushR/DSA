class Solution {
const int mod = 1e9 + 7;
public:
    int numWays(vector<string>& words, string target) {
        int m = target.size(), n = words[0].size();
        vector<vector<int>> count(n, vector<int>(26));
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < n; j++) {
                count[j][words[i][j] - 'a']++;
            }
        }
        vector<vector<int>> DP(m + 1, vector<int>(n + 1));
        DP[0][0] = 1;
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j < n; j++) {
                if(i < m) 
                    DP[i + 1][j + 1] = (DP[i + 1][j + 1] + (DP[i][j] * 1L * count[j][target[i] - 'a']) % mod) % mod;
                DP[i][j + 1] = (DP[i][j + 1] + DP[i][j]) % mod;
            }
        }
        return DP[m][n];
    }
};