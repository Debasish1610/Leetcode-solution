class Solution {
public:
    static bool compare(pair<int,int>&a, pair<int,int>&b) {
        return a.second < b.second;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>speedEfficiencyPair;
        priority_queue<int, vector<int>, greater<int>>pq;
        long long int len = speed.size(), maxValue = 0, pqSum = 0, modValue = 1000000007;
        
        for(int i = 0; i < len; i++) {
            speedEfficiencyPair.push_back({speed[i], efficiency[i]});
        }
        sort(speedEfficiencyPair.begin(), speedEfficiencyPair.end(), this->compare);
        
        for (int i = len-1; i >= 0; i--) {
            pq.push(speedEfficiencyPair[i].first);
            pqSum += speedEfficiencyPair[i].first;
            maxValue = max(maxValue, pqSum*speedEfficiencyPair[i].second);
            if (pq.size() == k) {
                pqSum -= pq.top();
                pq.pop();
            }
        }
        return (int)(maxValue%modValue);
    }
};