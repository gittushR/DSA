class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ind1=0,ind2=0;
        int n=s.size(),m=t.size();
        while(ind1<n and ind2<m){
            if(s[ind1]==t[ind2]){
                ind1++;ind2++;
            }else{
                ind2++;
            }
        }
        if(ind1==n)return true;
        else return false;
    }
};