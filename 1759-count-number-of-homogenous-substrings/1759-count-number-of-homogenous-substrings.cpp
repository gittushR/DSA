#define mod 1000000007
class Solution {
public:
    int countHomogenous(string s) {
        int n=s.size();
        long long int ans=0,curr=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                curr++;
            }else{
                ans+=((curr*(curr+1))/2)%mod;
                curr=1;
            }
        }
        ans+=((curr*(curr+1))/2)%mod;
        return ans%mod;
    }
};