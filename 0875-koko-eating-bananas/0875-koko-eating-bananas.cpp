class Solution {
public:
    bool canEatAllBananas(vector<int>& piles, int k, int h) {
        int time = 0;
        for (int p : piles) {
            time += (p - 1) / k + 1;
        }
        return time <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canEatAllBananas(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};