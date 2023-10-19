class Solution {
public:
    string makeWord(string &s){
        stack<char> st;
        for(auto it: s){
            if(st.empty() and it=='#')continue;
            if(it=='#'){
                st.pop();
            }else{
                st.push(it);
            }
        }
        string word="";
        while(!st.empty()){
            word+=st.top();
            st.pop();
        }
        reverse(word.begin(),word.end());
        // cout<<word<<endl;
        return word;
    }
    bool backspaceCompare(string s, string t) {
        return makeWord(s)==makeWord(t);
    }
};