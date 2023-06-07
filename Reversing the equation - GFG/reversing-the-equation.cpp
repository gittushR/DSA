//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            stack<string>st;
            int n = s.length();
            string ans = "";
            
            int i = 0;
            while (i<n){
                string aux = "";
                if (s[i] >= '0' && s[i] <= '9'){
                    while(i<n && (s[i] >= '0' && s[i] <= '9')){
                        aux += s[i];
                        i++;
                    }
                    st.push(aux);
                }
                else{
                    aux += s[i];
                    st.push(aux);
                    i++;
                }
            }
            while(!st.empty()){
                ans += st.top();
                st.pop();
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends