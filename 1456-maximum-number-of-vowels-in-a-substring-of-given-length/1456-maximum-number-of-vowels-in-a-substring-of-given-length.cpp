class Solution {
private:
    bool isVowel(char c){
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')return true;
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int ans=0;
        int count=0;
        int n=s.size();
        while(j<n){
            if(isVowel(s[j])){
                count++;
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                ans=max(count,ans);
                if(isVowel(s[i])){
                    count--;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};