class Solution {
public:
    int addMinimum(string word) {
        string s="abc";
        int i=0,j=0;
        int ans=0;
        while(j<word.size()){
            if(s[i]==word[j]){
                i=(i+1)%3;
                j++;
            }else{
                i=(i+1)%3;
                ans++;
            }
        }
        if(i==0)return ans;
        else return ans+(3-i);
    }
};