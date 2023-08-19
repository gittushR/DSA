//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string f(string &x, string &y) {
        int i = x.size() - 1; 
        int j = y.size() - 1; 
        
        int carry = 0; 
        while(i >= 0 && j >= 0) {
            int num1 = x[i] - '0';    
            int num2 = y[j] - '0'; 
            
            int res = num1 + num2 + carry; 
            x[i] = (res % 10 + '0'); 
            carry = res / 10; 
            
            i--, j--; 
        }
        
        while(i >= 0) {
            int num1 = x[i] - '0';    
            int res = num1 + carry; 
            x[i] = (res % 10 + '0'); 
            carry = res / 10; 
            i--; 
        }
        
        if(carry > 0) {
            x = to_string(carry) + x; 
        }
    
        i = 0; 
        while(i < x.size() && x[i] == '0') {
            i++; 
        }
        
        if(x[0] == '0' && i == x.size()) {
            return "0";
        }
        
        return x.substr(i); 
    }
    string findSum(string X, string Y) {
        if(X.size() >= Y.size()) {
            return f(X, Y);
        } else {
            return f(Y, X); 
        }
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends