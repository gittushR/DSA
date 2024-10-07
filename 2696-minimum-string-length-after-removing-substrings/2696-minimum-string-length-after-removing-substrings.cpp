class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char curr_char=s[i];
            if(st.empty()){
                st.push(curr_char);
                continue;
            }
            if(curr_char=='B' and st.top()=='A'){
                st.pop();
            }
            else if(curr_char=='D' and st.top()=='C'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};