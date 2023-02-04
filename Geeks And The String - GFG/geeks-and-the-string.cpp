//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        int i=0;
        while(i<s.size()){
            if(s[i]==s[i+1]){
                s.erase(i,2);
                i=0;
            }
            else  i++;
        }
        if(!s.size())s="-1";
        return s;
    }
};

/*
string removePair(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(!st.empty()){
                if(st.top()==s[i]){
                    st.pop();
                }
                else st.push(s[i]);
            }
            else st.push(s[i]);
        }
        s="";
        if(st.empty()){
            return "-1";
        }
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
*/


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends