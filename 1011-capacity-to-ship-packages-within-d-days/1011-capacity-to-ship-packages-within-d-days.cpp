class Solution {
public:
    int fn(int cap, vector<int> arr){
        int days=1;
        int load=0;
        for(int i=0;i<arr.size();i++){
            if(load+arr[i]>cap){
                days++;
                load=arr[i];
            }else{
                load+=arr[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=-1e8,sum=0;
        for(int i=0;i<weights.size();i++){
            maxi=max(maxi,weights[i]);
            sum+=weights[i];
        }
        int low=maxi,high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            int totalDays=fn(mid,weights);
            if(totalDays<=days){
                high=mid-1;
            }else
                low=mid+1;
        }
        return low;
    }
};