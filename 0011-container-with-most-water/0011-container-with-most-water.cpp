class Solution {
public:
    int maxArea(vector<int>& height) {
        int vol=0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            int h=min(height[i], height[j]);
            vol=max(vol, h*(j-i));
            while(h>=height[i]&&i<j){
                i++;
            }
            while(h>=height[j]&&i<j){
                j--;
            }
        }
        return vol;
    }
};