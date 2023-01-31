class Solution {
public:
   vector<vector<int>> rotate(vector<vector<int>>& mat) {
        int row = mat.size();
        int column = mat[0].size();
        vector<vector<int>> result;

        for(int i = 0; i<column; i++){
            vector<int> temp;
            for(int j = 0; j<row; j++){
                temp.push_back(mat[j][i]);
            }
            reverse(temp.begin(),temp.end());
            result.push_back(temp);
        }
        return result;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target) // For 0 or 360 degree
            return true;
        vector<vector<int>> rotated = rotate(mat);
        vector<vector<int>> rotated1 = rotate(rotated);
        if(rotated == target) // Check for 90 degree rotation
            return true;
        else if(rotated1 == target) // For 180 degree
            return true;
        else if(rotate(rotated1) == target) // For 270 degree
            return true;
        return false;
    }
};