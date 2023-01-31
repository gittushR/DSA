class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto comp = [](vector<int>& v1, vector<int>& v2) {
            if (v1[0] != v2[0]) {
                return v1[0] < v2[0];
            }
            return v1[1] < v2[1];
        };
        sort(intervals.begin(), intervals.end(), comp);
        int front = intervals[0][1];
        int ans = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < front) {
                ans++;
                if (intervals[i][1] < front) {
                    front = intervals[i][1];
                }
            } else {
                front = intervals[i][1];
            }
        }
        return ans;
    }
};