class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        int temp;
        while (n){
            n--;
            temp = n % 26;
            ans += ('A' + temp);
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};