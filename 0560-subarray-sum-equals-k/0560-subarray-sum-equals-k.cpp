class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        unordered_map<long long, int> prevSum;
        long long sum=0;int ans=0;
        for(int i=0;i<a.size();i++){
            sum+=a[i];
            if(sum==k)ans++;
            long long rem=sum-k;
            if(prevSum.find(rem)!=prevSum.end()){
                ans+=prevSum[rem];
            }
            prevSum[sum]++;
            // if(prevSum.find(sum)==prevSum.end()){
            //     prevSum[sum]=i;
            // }
        }
        return ans;
    }
};