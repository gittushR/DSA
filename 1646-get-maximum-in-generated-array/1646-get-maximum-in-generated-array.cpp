class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<2)
            return n;
        int arr[n+1];
        int maxi = INT_MIN;
        arr[0] = 0;
        arr[1] = 1;
        for(int i = 2;i<=n;i++){
            if(i%2==1)
                arr[i] = arr[i/2] + arr[i/2 + 1];
            else
                arr[i] = arr[i/2];
            maxi = max(maxi,arr[i]);        
        }
        return maxi;

        return maxi;
    }
};