class Solution {
    unordered_map<string, int> wordMap;
    vector<int>dp;
public:
    int checkWordCanBreak(string s, int index) {
        if (s.size() <= index) {
            return 1;
        }
        
        if (dp[index] != -1) return dp[index];
        string subString = "";
        for (int i = index; i < s.size(); i++) {
            subString.push_back(s[i]);
            if (wordMap[subString] != 0 && checkWordCanBreak(s, i+1)) {
                return dp[index] = 1;
            }
        }
        return dp[index] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i = 0; i < wordDict.size(); i++) {
            wordMap[wordDict[i]] = 1;
        }
        dp.assign(s.size()+2, -1);
        return checkWordCanBreak(s, 0);
    }
};