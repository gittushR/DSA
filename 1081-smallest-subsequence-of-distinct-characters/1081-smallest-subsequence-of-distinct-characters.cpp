class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        unordered_map<char,int> freq;
        unordered_map<char,bool> vis;
        for(auto it:s){
            freq[it]++;
            vis[it]=false;
        }
        for(int i=0;i<s.size();i++){
            if(vis[s[i]]){
                freq[s[i]]--;
                continue;
            }
            while(!st.empty() and freq[st.top()]>0 and st.top()>s[i]){
                vis[st.top()]=false;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]]=true;
            freq[s[i]]--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};