class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size(), maxHeightIndex = 0, output = 0;
        for(int i = 1; i < len; i++) {
            if (height[i] > height[maxHeightIndex]) {
                maxHeightIndex = i;
            }
        }
        
        int maxFromLeft = height[0];
        for (int i = 1; i <= maxHeightIndex; i++) {
            if (maxFromLeft < height[i]) {
                maxFromLeft = height[i];
            }
            else {
                output += (maxFromLeft - height[i]);
            }
        }
        
        int maxFromRight = height[len-1];
        for (int i = len-2; i >= maxHeightIndex; i--) {
            if (maxFromRight < height[i]) {
                maxFromRight = height[i];
            }
            else {
                output += (maxFromRight - height[i]);
            }
        }
        
        return output;
    }
};