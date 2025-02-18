//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void generateBinaryStringHelper(vector<string> &ans, int size, string str, int ind){
        if(str.size()==size){
            ans.push_back(str);
            return;
        }
        
        if(str[ind-1]=='1'){
            str+='0';
            generateBinaryStringHelper(ans,size,str,ind+1);
        }else{
            str+='0';
            generateBinaryStringHelper(ans,size,str,ind+1);
            str.pop_back();
            str+='1';
            generateBinaryStringHelper(ans,size,str,ind+1);
        }
    }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        if(num<=0)return {};
        vector<string> ans;
        generateBinaryStringHelper(ans,num,"0",1);
        generateBinaryStringHelper(ans,num,"1",1);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends