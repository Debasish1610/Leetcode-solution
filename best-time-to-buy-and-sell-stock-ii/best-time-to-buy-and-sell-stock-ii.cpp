class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int stock = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[stock] < prices[i]) {
                profit += (prices[i] - prices[stock]);
                stock = i;
            } else {
                stock = i;
            }
        }
        
        return profit;
    }
};