//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
     long long sumSubstrings(string s){
        vector<int>v;
        for(int i=0;i<s.size();i++){
           v.push_back(int(s[i])-48);
        }
        long long ans = 0;
        for(int i=0;i<v.size();i++){
            long long res = 0;
            for(int j=i;j<v.size();j++){
              res=((res*10)%1000000007+v[j])%1000000007;
              ans = (ans+res)%1000000007;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends