class Solution {
public:
    long long minimumSteps(string s) {
        long long numOnes=0;
        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                numOnes++;
            }else{
                ans+=numOnes;
            }
        }
        return ans;
    }
};