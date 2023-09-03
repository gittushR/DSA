class Solution {
public:
    int maxDepth(string s) {
        int maxDepth=INT_MIN;
        int currDepth=0;
        int count=0;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
                count++;
            }else if(s[i]==')'){
                currDepth=st.size();
                maxDepth=max(maxDepth,currDepth);
                st.pop();
            }else continue;
        }
        if(count==0)return 0;
        return maxDepth;
    }
};