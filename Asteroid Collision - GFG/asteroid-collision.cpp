//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &A) {
        // code here
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends