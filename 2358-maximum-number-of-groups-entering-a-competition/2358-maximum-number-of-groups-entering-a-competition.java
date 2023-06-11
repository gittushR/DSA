class Solution {
    public int maximumGroups(int[] A) {
        int left = 0, right = 1000, n = A.length;
        while (left < right) {
            int k = (left + right + 1) / 2;
            if (k * (k + 1) / 2 > n) {
                right = k - 1;
            } else {
                left = k;
            }
        }
        return left;
    }
}
