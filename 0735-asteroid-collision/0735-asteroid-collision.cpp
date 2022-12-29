class Solution {
public:
    vector<int> asteroidCollision(vector<int>& A) {
        stack<int> st;
        int i=0;
       while(i<A.size()){
            if(st.empty()|| A[i]>0){
                st.push(A[i]);
                i++;
            }
            else{
                if(!st.empty() and st.top()>0 and st.top()<abs(A[i])){
                    st.pop();
                }
                else if(!st.empty() and st.top()>0 and st.top()==abs(A[i])){
                    st.pop();
                    i++;
                }
                else if(!st.empty() and st.top()>0 and st.top()>abs(A[i])){
                    i++;
                }
                else if(st.empty() || st.top()<0){
                    st.push(A[i]);
                    i++;
                }
            }
        }
        vector<int> ans;
        if(st.empty()){return ans;}
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
