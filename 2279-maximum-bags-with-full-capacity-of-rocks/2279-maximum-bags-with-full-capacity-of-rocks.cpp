class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ad) {
        int n=capacity.size();
        vector<int> diff(n);
        for(int i=0;i<n;i++){
            diff[i]=capacity[i]-rocks[i];
        }
        int ans=0;
        sort(diff.begin(),diff.end());
        for(int i=0;i<n;i++){
            if(diff[i]==0){
                ans++;
                continue;
            }
            ad-=diff[i];
            if(ad<0)break;
            ans++;
        }
        return ans;
    }
};