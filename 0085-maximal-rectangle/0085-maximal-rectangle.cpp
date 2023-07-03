class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> leftSmall(n),rightSmall(n);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() and heights[st.top()]>=heights[i])st.pop();
            if(st.empty())leftSmall[i]=0;
            else leftSmall[i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())rightSmall[i]=n-1;
            else rightSmall[i]=st.top()-1;
            st.push(i);
        }
        
        int maxArea=-1e9;
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,heights[i]*(rightSmall[i]-leftSmall[i]+1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')height[j]++;
                else height[j]=0;
            }
            maxi=max(maxi,largestRectangleArea(height));
        }
        return maxi;
    }
};