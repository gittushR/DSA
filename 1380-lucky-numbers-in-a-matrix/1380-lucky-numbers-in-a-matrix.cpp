class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> max_in_column;
        vector<int> min_in_row;
        vector<int> ans;
        //max_column
        for(int j = 0 ; j < matrix[0].size();j++)
        {
            int max = INT_MIN;
            for(int i = 0 ; i < matrix.size();i++)
            {
                if(matrix[i][j] > max)
                    max = matrix[i][j];
            }
            max_in_column.push_back(max);
        }
        //min_row
        for(int i = 0 ; i < matrix.size();i++)
        {
            int min = INT_MAX;
            for(int j = 0 ; j < matrix[i].size();j++)
            {
                if(min > matrix[i][j])
                    min = matrix[i][j];
            }
            min_in_row.push_back(min);
        }
        for(int i = 0 ;i < matrix.size();i++)
        {
            for(int j = 0 ; j < matrix[i].size();j++)
            {
                if(matrix[i][j] == min_in_row[i] && matrix[i][j] == max_in_column[j])
                    ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};