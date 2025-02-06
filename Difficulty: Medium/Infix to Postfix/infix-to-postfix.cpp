//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string& s) {
        // Your code here
        stack <char> st;
        string ans="";
        
        for(int i=0;i<s.size();i++){
            //cout<<ans<<" "<<i<<"\t";
            char c = s[i];
            
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
                //cout<<"operand"<<endl;
                ans += c;
            }else if( c == '('){
                //cout<<"opener"<<endl;
                st.push('(');
            }else if( c == ')'){
                //cout<<"closer"<<endl;
                while(st.top()!='('){
                    ans+= st.top();
                    st.pop();
                }
                st.pop();
            }else{
                //cout<<"operator"<<endl;
                while(!st.empty() and prec(st.top())>=prec(s[i])){
                    ans+=st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
    int prec(char ch){
        if(ch=='^')return 3;
        if(ch=='*' or ch=='/')return 2;
        if(ch=='+' or ch=='-')return 1;
        else return -1;
    }
};


//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends