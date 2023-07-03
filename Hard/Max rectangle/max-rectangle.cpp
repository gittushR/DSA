//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
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
    int maxArea(int matrix[MAX][MAX], int n, int m) {
        // Your code here
        int maxi=0;
        vector<int> height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1)height[j]++;
                else height[j]=0;
            }
            maxi=max(maxi,largestRectangleArea(height));
        }
        return maxi;
        
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends