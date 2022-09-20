class Solution {
public:
    int findMaxSubarray(vector<int>& nums1, vector<int>& nums2, int indexOne, int indexTwo, vector<vector<int>>&dp) {
        if (indexOne >= nums1.size() || indexTwo >= nums2.size()) {
            return dp[indexOne][indexTwo] = 0;
        }
        
        if (dp[indexOne][indexTwo] != -1) {
            return dp[indexOne][indexTwo];
        }
        int value1 = 0, value2 = 0, value3 = 0;
        dp[indexOne][indexTwo] = 0;
        if (nums1[indexOne] == nums2[indexTwo]) {
            value1 = findMaxSubarray(nums1, nums2, indexOne+1, indexTwo+1, dp);
            dp[indexOne][indexTwo] = dp[indexOne+1][indexTwo+1] + 1;
        }
        value2 = findMaxSubarray(nums1, nums2, indexOne+1, indexTwo, dp);
        value3 = findMaxSubarray(nums1, nums2, indexOne, indexTwo+1, dp);
        // cout<<dp[indexOne][indexTwo]<<" ";
        return max(max(value1, value2), max(value3, dp[indexOne][indexTwo]));
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int maxSize = 1001;
        vector<vector<int>>dp(maxSize, vector<int>(maxSize, -1));
        return findMaxSubarray(nums1, nums2, 0, 0, dp);
        // for (int i = 0; i < nums1.size(); i++) {
        //     for (int j = 0; j < nums2.size(); j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // return 0;
    }
};