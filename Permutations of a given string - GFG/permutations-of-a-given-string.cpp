//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector<string> ans;
		    int freq[s.size()];
		    for(int i=0;i<s.size();i++){freq[i]=0;}
            string temp;
            sets(ans,temp,s,freq);
            set<string> st;
            for(auto it: ans)st.insert(it);
            ans.clear();
            for(auto it: st)ans.push_back(it);
            return ans;
		}
		void sets(vector<string> &ans, string &temp, string s, int freq[]){
		    if(temp.size()==s.size()){
		        ans.push_back(temp);
		        return;
		    }
		    for(int i=0;i<s.size();i++){
            if(!freq[i] ){
                temp=temp+s[i];
                freq[i]=1;
                sets(ans,temp,s,freq);
                freq[i]=0;
                temp.pop_back();
            }
        }
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends