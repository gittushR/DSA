class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int s=0,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int missing=calculateMissingNums(arr[mid],mid+1);
            
            if(missing>=k)e=mid-1;
            else s=mid+1;
        }
        if(e==-1)return k;
        else return arr[e]+(k-calculateMissingNums(arr[e],e+1));
    }
private:
//this functiuon returns total number of missing elements till that index
    int calculateMissingNums(int actual, int expected){
        return actual-expected;
    }
};