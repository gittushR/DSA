class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans=0;
        for(auto it: s){
            if(it==')'){
                if(st.empty())st.push(it);
                else if(st.top()=='(')st.pop();
                else st.push(it);
            }else{
                st.push(it);
            }
        }
        return st.size();
    }
};