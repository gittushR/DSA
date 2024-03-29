class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0;
        int right = 0;
        int ans = INT_MAX;
        int count = 0;
        while(right < blocks.size()){
            if(blocks[right] == 'W'){
                count++;
            }
            if(right - left + 1 == k){
                ans = min(count, ans);
                if(blocks[left] == 'W'){
                    count--;
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};