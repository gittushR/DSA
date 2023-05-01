class Solution {
public:
    double average(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        double sum=0;
        double ans;
        for(int i=1;i<n-1;i++){
            sum+=arr[i];
        }
        ans=sum/(n-2);
        return ans;
    }
};