class Solution {
public:
    int beauty(vector<int> hashMap){
        int mf=-1e9,lf=1e9;
        for(int i=0;i<26;i++){
            mf=max(mf,hashMap[i]);
            if(hashMap[i]>0)lf=min(lf,hashMap[i]);
        }
        return mf-lf;
    }
    int beautySum(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            vector<int> hashMap(26,0);
            for(int j=i;j<s.size();j++){
                hashMap[s[j]-'a']++;
                res+=beauty(hashMap);
            }
        }
        return res;
    }
};