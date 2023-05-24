//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
     int isPossible(int n, int m, string s){

        int maxX = 0, maxY = 0,x = 0, y = 0, minX = 0, minY = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'L'){
                x = x-1;
            }else if(s[i] == 'R'){
                x = x+1;
            }else if(s[i] == 'D'){
                y = y+1;
            }else{
                y = y -1;
            }
            maxX = x > maxX ? x : maxX;
            maxY = y > maxY ? y : maxY;
            minX = x < minX ? x : minX;
            minY = y < minY ? y : minY;
        }

        if(maxX + abs(minX) < m && maxY + abs(minY) < n){
            return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends