class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int n=word1.size(), m=word2.size();
        int i=0;
        for(i;i<min(n,m);i++){
            ans+=word1[i];
            ans+=word2[i];
        }
        if(i==n){
            for(i;i<m;i++){
                ans+=word2[i];
            }
        }else{
            for(i;i<n;i++){
                ans+=word1[i];
            }
        }
        return ans;
    }
};