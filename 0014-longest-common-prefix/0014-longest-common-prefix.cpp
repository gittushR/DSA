class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());int n=strs.size();
        string ans="";string curr=strs[0];string last=strs[n-1];
        for(int i=0;i<curr.size();i++){
            if(curr[i]==last[i]){
                ans+=curr[i];
            }else break;
        }
        return ans;
    }
};