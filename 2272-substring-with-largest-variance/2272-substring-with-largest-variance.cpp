class Solution {
public:
    int largestVariance(string s) {
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        int ans=0;
        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2='a';ch2<='z';ch2++){
                if(ch1==ch2 or !freq[ch1-'a'] or !freq[ch2-'a'])continue;
                for(int i=1;i<=2;i++){
                    int cnt1=0,cnt2=0;
                    for(auto it:s){
                        cnt1+=it==ch1;
                        cnt2+=it==ch2;
                        if(cnt1<cnt2){
                            cnt1=cnt2=0;
                        }else if(cnt1>0 and cnt2>0){
                            ans=max(ans,cnt1-cnt2);
                        }
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};