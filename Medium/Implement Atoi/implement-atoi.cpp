//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int n = str.length();
        int sign = (str[0] == '-')? -1 : 1;
        int ans = 0;
        
        //
        for(int i=0; i<n; i++){
            
            if(i == 0 && str[i] == '-') continue; // beauase it is already scanned
            if(str[i] < '0' || str[i] > '9') return -1; // acc. to constraints
            
            ans = (ans * 10) + (str[i] - 48);
        }
        return sign*ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends