//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
        void solve(int ind,vector<string> &v,string s,string &temp){
        int n = s.length();
        if(ind>=n){
            if(!temp.empty())
               v.push_back(temp);
            return;
            }
        temp.push_back(s[ind]);
        solve(ind+1,v,s,temp);
        temp.pop_back();
        solve(ind+1,v,s,temp);
        }
        vector<string> AllPossibleStrings(string s){
            // Code here
            vector<string> v;
            string temp;
            solve(0,v,s,temp);
          
           sort(v.begin(),v.end());
            return v;
        }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends