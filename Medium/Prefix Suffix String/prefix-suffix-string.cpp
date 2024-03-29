//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        unordered_map<string,bool> mpp;
        for(auto it:s1){
            string temp="";
            for(int i=0;i<it.length();i++){
                temp+=it[i];
                mpp[temp]=true;
            }
            temp="";
            for(int i=it.length()-1;i>=0;i--){
                temp=it[i]+temp;
                mpp[temp]=true;
            }
        }
        int ans=0;
        for(auto it:s2){
            if(mpp[it])ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends