class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        int prev=0;
        for(auto it: bank){
            int curr=0;
            for(int i=0;i<it.size();i++){
                if(it[i]=='1'){
                    curr++;
                }
            }
            if(curr>=1){
                ans+=(curr*prev);
                prev=curr;
            }
        }
        return ans;
    }
};