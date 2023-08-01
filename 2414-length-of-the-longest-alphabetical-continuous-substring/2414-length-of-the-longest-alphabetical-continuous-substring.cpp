class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1;
		int sum=1;
        for(int i = 0; i < s.length()-1; i++){
            if(s[i+1]-s[i]==1){
                sum++;
            }else{
                sum = 1;
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};