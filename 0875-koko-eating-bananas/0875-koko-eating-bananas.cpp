class Solution {
public:
    long long fn(vector<int> piles,int hourly){
        long long totalHours=0;
        for(int i=0;i<piles.size();i++){
            totalHours+=ceil((double)piles[i]/(double)hourly);
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        long long ans;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long totalH=fn(piles,mid);
            if(totalH<=h){
                ans=mid;
                high=mid-1;
            }else 
                low=mid+1;
        }
        return ans;
    }
};