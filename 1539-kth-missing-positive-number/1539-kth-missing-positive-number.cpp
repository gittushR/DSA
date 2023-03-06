class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int s=0,e=n-1;
        int missing= compute(arr[n-1],n);
        while(s<=e){
            int mid=s+(e-s)/2;
            missing=compute(arr[mid],mid+1);
            
            if(missing>=k)e=mid-1;
            else s=mid+1;
        }
        if(e==-1)return k;
        else return arr[e]+(k-compute(arr[e],e+1));
    }
private:
    int compute(int actual, int expected){
        return actual-expected;
    }
};