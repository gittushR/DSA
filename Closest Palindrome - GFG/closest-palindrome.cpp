//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution {
public:
	long long int closestPalindrome(long long int num){
        ll digits=0,n=num;
        while(n){
            digits++;
            n/=10;
        }
        if(digits==1)
            return num;
        vector<ll>candidates={(ll)pow(10,digits)+1,(ll)pow(10,digits)-1,
        (ll)pow(10,digits-1)+1,(ll)pow(10,digits-1)-1};
        ll mid=(digits+1)/2;
        ll prefix=num/(ll)(pow(10,digits-mid));
        vector<ll>v={prefix,prefix-1,prefix+1};
        for(auto i:v){
            string s=to_string(i);
            if(digits%2!=0)
                s.pop_back();
            reverse(s.begin(),s.end());
            string c=to_string(i)+s;
            candidates.push_back(stoll(c));
        }
        long long int res = 0;
        long long int minDiff = INT_MAX;
        for(auto i : candidates){
            if(abs(num - i) == minDiff ){
                res = min (i, res);
            }
            if(abs(num - i) < minDiff){
                minDiff = abs(num- i);
                res = i;
            }
        }
        return res;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int num;
		cin >> num;
		Solution obj;
		long long int ans = obj.closestPalindrome(num);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends