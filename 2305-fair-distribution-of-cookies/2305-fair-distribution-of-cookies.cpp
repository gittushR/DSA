class Solution {
public:
    bool isPossible(int maxChoc, vector<int> &cookies, int k){
        sort(cookies.begin(),cookies.end());
        do{
            int kid=1, cntChoc=0;
            for(int i=0;i<cookies.size();i++){
                if(cntChoc+cookies[i]<=maxChoc){
                    cntChoc+=cookies[i];
                }else{
                    kid++;
                    cntChoc=cookies[i];
                }
            }
            if(kid<=k)return true;    
        } while(next_permutation(cookies.begin(),cookies.end()));
        
        return false;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int low=-1e8,high=0;
        for(int i=0;i<cookies.size();i++){
            low=max(low,cookies[i]);
            high+=cookies[i];
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(mid,cookies,k)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};