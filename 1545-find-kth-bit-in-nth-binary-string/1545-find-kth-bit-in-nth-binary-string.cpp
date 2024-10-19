class Solution {
public:
    string ans="";
    string invert(string ss){
        for(int i=0;i<ss.size();i++){
            if(ss[i]=='0'){
                ss[i]='1';
            }else{
                ss[i]='0';
            }
        }
        return ss;
    }
    void helper(int it, int n, string s){
        if(it==n){
            ans=s;
            return;
        }
        string inv = invert(s);
        //cout<<inv<<":"<<endl;
        reverse(inv.begin(),inv.end());
        helper(it+1,n,s+'1'+inv);
        return;
    }
    char findKthBit(int n, int k) {
        helper(1,n,"0");
        //cout<<ans<<endl;
        return ans[k-1];
    }
};