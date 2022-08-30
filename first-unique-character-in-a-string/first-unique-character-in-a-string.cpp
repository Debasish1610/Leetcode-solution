class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> charFrequencyCountInString(26, 0);
        
        for (int i = 0; i < s.size(); i++) {
            charFrequencyCountInString[s[i]-'a']++;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (charFrequencyCountInString[s[i]-'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};