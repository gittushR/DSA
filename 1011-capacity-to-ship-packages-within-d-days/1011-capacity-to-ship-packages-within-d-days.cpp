class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(int i=0;i<weights.size();i++)sum+=weights[i];
        
        int s=0;
        int e=sum;
        int mid=(s+e)/2;
        
        int ans=-1;
        
        while(s<=e){
            if (isPossible(weights,weights.size(),days,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
    bool isPossible(vector<int> arr, int n, int m,int mid){
        int day=1;
        int weightSum=0;
        
        for(int i=0;i<n;i++){
            if(weightSum+arr[i]<=mid)weightSum+=arr[i];
            else{
                day++;
                if(day>m || arr[i]>mid)return false;
                weightSum=arr[i];
            }
        }
        return true;
    }
};