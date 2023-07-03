class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        int n=a.size();
        int count = 0;
        int left = 0;
        long long product = 1;
        for (int right = 0; right < n; right++) {
            product *= a[right];
            while (left <= right && product >= k) {
                product /= a[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};