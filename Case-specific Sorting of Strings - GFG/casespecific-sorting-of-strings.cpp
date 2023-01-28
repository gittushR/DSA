//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string small="";
        string caps="";
        for(int i=0;i<str.size();i++){
            if(str[i]<='Z'){
                caps+=str[i];
            }else{
                small+=str[i];
            }
        }
        sort(caps.begin(),caps.end());
        sort(small.begin(),small.end());
        string ans="";
        int a=0,b=0;
        for(int i=0;i<str.size();i++){
            if(str[i]<='Z'){
                ans+=caps[a++];
            }else{
                ans+=small[b++];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends