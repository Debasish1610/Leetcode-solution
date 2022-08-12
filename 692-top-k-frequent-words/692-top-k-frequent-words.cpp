class Solution {
public:
    
    static bool compare(pair<string, int>firstPair, pair<string, int>secondPair) {
        if (firstPair.second == secondPair.second) {
            return firstPair.first < secondPair.first;
        }
        
        return firstPair.second > secondPair.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<string, int>> wordWithFrequency;
        vector<string>output;
        map<string, int>wordFrequencyCount;
        
        for (int i = 0; i < words.size(); i++) {
            wordFrequencyCount[words[i]]++;
        }
        
        for (auto it : wordFrequencyCount) {
            wordWithFrequency.push_back({it.first, it.second});
        }
        
        sort(wordWithFrequency.begin(), wordWithFrequency.end(), compare);
        
        for (int i = 0; i < k; i++) {
            output.push_back(wordWithFrequency[i].first);
        }
        
        return output;
    }
};