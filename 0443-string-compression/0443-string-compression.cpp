class Solution {
public:
    int compress(vector<char>& chars) {
        int group=1;
        string ans;
        ans+=chars[0];
        for(int i=1;i<chars.size();i++){
            if(chars[i]==chars[i-1]){
                group++;
            }else{
                
                if(group!=1)ans+=to_string(group);
                ans+=chars[i];
                group=1;
            }
        }
        if(group!=1)ans+=to_string(group);
        for(int i=0;i<ans.size();i++){
            chars[i]=ans[i];
        }
        return ans.size();
    }
};