class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size(), maxValue = 0, output = 0;
        vector<int>heightFromLeft(len), heightFromRight(len);
        for(int i = 0; i < len; i++) {
            if (height[i] > maxValue) {
                maxValue = height[i];
            }
            heightFromLeft[i] = maxValue;
        }
        
        maxValue = 0;
        for(int i = len-1; i >= 0; i--) {
            if (height[i] > maxValue) {
                maxValue = height[i];
            }
            heightFromRight[i] = maxValue;
        }
        
        for(int i = 0; i < len; i++) {
            output += (min(heightFromRight[i], heightFromLeft[i]) - height[i]);
        }
        
        return output;
    }
};