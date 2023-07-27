class Solution {
private:
    bool fun(vector<int>& a, long long x, long long k){
        long long val = x*k;
        for(int i=0; i<a.size(); i++){
            val -= min((long long)a[i],k);
        }
        return val <= 0;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sumPower=0;
        for(int i=0;i<batteries.size();i++)sumPower+=batteries[i];
        
        long long left=1, right=(sumPower/n);
        long long ans = 0;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(fun(batteries,n,mid)){
                ans = mid;
                left=mid+1;
            }else right=mid-1;
        }
        return ans;
    }
};