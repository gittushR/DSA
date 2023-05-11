//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        int n=s.length();
        int lastpos=-1;
        char c;
        int ans=0;
       for(int i=0;i<(n+1)/2;i++)
       {
           if(s[i]!=s[n-1-i])
           {
               if(s[i]=='?'||s[n-1-i]=='?')
               {
                   if(s[i]=='?')
                   {
                       s[i]=s[n-1-i];
                       if(lastpos==-1)
                       {
                           c=s[i];
                       }
                       else if(i-lastpos==1)
                       {
                           ans=ans+2*abs(s[i]-c);
                           c=s[i];
                       }
                       else
                       {
                           ans+=2*abs(s[i]-c);
                           c=s[i];
                       }
                   }
                   else
                   {
                       s[n-1-i]=s[i];
                       if(lastpos==-1)
                       {
                           c=s[i];
                       }
                       else if(i-lastpos==1)
                       {
                           ans=ans+2*abs(s[i]-c);
                           c=s[i];
                       }
                       else
                       {
                           ans+=2*abs(s[i]-c);
                           c=s[i];
                       }
                   }
                   lastpos=i;
               }
               else return -1;
           }
           else
           {
               if(lastpos==-1&&s[i]!='?')
               {
                   c=s[i];
                   lastpos=i;
               }
               else if(lastpos!=-1&&s[i]!='?')
               {
                   if(i-lastpos==1)
                   {
                       ans=ans+2*abs(s[i]-c);
                   }
                   else
                   {
                       if(lastpos!=(n+1)/2-1)
                       {
                       ans=ans+2*abs(s[i]-c);
                       }
                       else
                       {
                           ans=ans+2*abs(s[i]-c);
                       }
                   }
                   c=s[i];
                   lastpos=i;
               }
           }
       }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends