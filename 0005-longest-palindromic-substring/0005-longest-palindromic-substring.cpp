class Solution {
public:
    string longestPalindrome(string s) {
        int start = -1;
        int len = 0;
        for(int i = 0; i < s.size(); i++){
            //odd length
            int l = i-1; int r = i+1;
            while(l >= 0 and r < s.size() and s[l] == s[r]){
                l--;
                r++;
            }
            if(r - l - 1 > len){
                len = r - l - 1;
                start = l+1;
            }
            //even length
            l = i;
            r = i+1;
            while(l >= 0 and r < s.size() and s[l] == s[r]){
                l--;
                r++;
            }
            if(r - l - 1 > len){
                len = r - l - 1;
                start = l+1;
            }
        }
        if(start != -1){
            string ans = s.substr(start, len);
            return ans;
        }
        return "";
    }
};