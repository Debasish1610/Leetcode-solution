class Solution {
public:
    int score(int left, int right, int index, int fromBeg, int fromEnd, vector<int>& nums, vector<int>& multipliers, vector<vector<int>>&dp) {
        if (index >= multipliers.size()) {
            return 0;
        }
        
        if (dp[fromBeg][fromEnd] != INT_MIN) {
            return dp[fromBeg][fromEnd];
        }
        
        int q1 = score(left+1, right, index+1, fromBeg+1, fromEnd, nums, multipliers, dp) + nums[left]*multipliers[index];
        int q2 = score(left, right-1, index+1, fromBeg, fromEnd+1, nums, multipliers, dp) + nums[right]*multipliers[index];
        
        return dp[fromBeg][fromEnd] = (q1 > q2) ? q1 : q2;
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<int>>dp(multipliers.size()+1, vector<int>(multipliers.size()+1, INT_MIN));
        return score(0, nums.size()-1, 0, 0, 0, nums, multipliers, dp);
    }
};