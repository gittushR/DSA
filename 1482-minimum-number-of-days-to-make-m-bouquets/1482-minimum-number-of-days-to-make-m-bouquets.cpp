class Solution {
public:
    void getMiniandMaxi(int &low, int &high, vector<int> arr){
        for(int i=0;i<arr.size();i++){
            low=min(low,arr[i]);
            high=max(high,arr[i]);
        }
    }
    bool isPossible(int day, vector<int> arr, int m, int k){
        int cnt=0,numBouq=0;
        for(int i=0;i<arr.size();i++){
            if(day>=arr[i]){
                cnt++;
            }else{
                numBouq+=cnt/k;
                cnt=0;
            }
        }
        numBouq+=cnt/k;
        if(numBouq>=m)return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = (long long)m* (long long)k;
        if((long long)bloomDay.size()<total)return -1;
        int low=1e8,high=-1e8;
        getMiniandMaxi(low,high,bloomDay);
        int ans;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(isPossible(mid,bloomDay,m,k)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};