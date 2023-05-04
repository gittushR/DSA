class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        stack<int> st;
        if(g.size()==0 or s.size()==0)return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int i=0;i<g.size();i++){
            st.push(g[i]);
        }
        int n=s.size();
        int ans=0;
        while(!st.empty() and n) {
            if(s[n-1]>=st.top()){
                ans++;
                st.pop();
                n--;
            }else{
                st.pop();
            }
        }
        return ans;
    }
};