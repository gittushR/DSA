class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, 
            int iniColor, int color, int drow[], int dcol[]) {
                int n = image.size();
                int m = image[0].size();
                ans[row][col] = color;
                for (int i = 0; i < 4; i++) {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        ans[nrow][ncol] != color && image[nrow][ncol] == iniColor) 
                            dfs(nrow, ncol, image, ans, iniColor, color, drow, dcol);       
                }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        dfs(sr, sc, image, ans, iniColor, color, drow, dcol);  
        return ans;
    }
};