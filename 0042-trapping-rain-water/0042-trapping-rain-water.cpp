#define ll long long
class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0]=arr[0];
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],arr[i]);
        }
        rightMax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],arr[i]);
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            ans+=min(leftMax[i],rightMax[i])-arr[i];
        }
        return ans;
    }
};