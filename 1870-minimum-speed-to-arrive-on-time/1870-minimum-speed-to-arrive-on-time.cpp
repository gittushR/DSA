class Solution {
public:
    bool isPossible(vector<int>& dist,int speed,double hour){
        double ans=0;
        for(int i=0;i<dist.size();i++){
            double d=dist[i]*1.0/speed;
            if(i!=dist.size()-1)
            ans=ans+ceil(d);
            else
            ans+=d;
            if(ans>hour)
            return false;
        }
       if(ans<=hour)
       return true;
       return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour <= dist.size()-1) return -1;
        int ans=-1;
        int low=1;
        int high=1e9;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(dist,mid,hour)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};