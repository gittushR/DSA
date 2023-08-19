//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    
    long long int countOfSubstringWithKOnes(string s, int k){
        //complete the function here
        unordered_map<long long, int> prevSum;
        long long sum=0;int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')sum++;
            if(sum==k)ans++;
            long long rem=sum-k;
            if(prevSum.find(rem)!=prevSum.end()){
                ans+=prevSum[rem];
            }
            prevSum[sum]++;
            // if(prevSum.find(sum)==prevSum.end()){
            //     prevSum[sum]=i;
            // }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
       string s;
       int k;
       cin >> s >> k;
       Solution ob;
       cout << ob.countOfSubstringWithKOnes(s, k) << endl;
    }
return 0;
}


// } Driver Code Ends