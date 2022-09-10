class Solution {
public:
    int profit(vector<int>& prices, int index, int k, int buy, vector<vector<vector<int>>> &dp) {
        if (k == 0 || index == prices.size()) {
            return 0;
        }
        
        if (dp[index][k][buy] != -1) {
            return dp[index][k][buy];
        }
        
        if (buy) {
            dp[index][k][buy] = max(profit(prices,index+1, k-1, 0, dp)+prices[index], profit(prices,index+1, k, 1, dp));//for sell & not sell
        } else {
            dp[index][k][buy] = max(profit(prices,index+1, k, 1, dp)-prices[index], profit(prices,index+1, k, 0, dp));//for buy & not buy
        }
                                
        return dp[index][k][buy];
    }
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1 || k == 0) return 0;
        vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(k+1, vector<int>(2, -1)));
        return profit(prices, 0, k, 0, dp);
    }
};