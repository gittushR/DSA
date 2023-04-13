class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        stack<int>st;
        for(int i=0,j=0; i<po.size(); i++) {
            if(!st.empty()) {
                if(st.top()==po[i]) {
                    st.pop();
                    continue;
                }
            }

            while(j<pu.size() && pu[j]!=po[i]) {
                st.push(pu[j]);
                j++;
            }
            j++;
        }
        if(st.empty()) return true;
        else return false; 
    }
};