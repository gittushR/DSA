#define mod 1000000007
class Solution {
public:
    int numSub(string s) {
        long long int ans=0;
        long long int len=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                len++;
            }else{
                ans+=((len*(len+1))/2)%mod;
                len=0;
            }
        }
        ans+=((len*(len+1))/2)%mod;
        return ans%mod;
    }
};