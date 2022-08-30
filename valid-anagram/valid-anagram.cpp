class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int flag[26] = {0};
        
        for (int i = 0; i < s.size(); i++) {
            flag[s[i]-'a']++;
        }
        
        for (int i = 0; i < t.size(); i++) {
            if (flag[t[i]-'a'] != 0) {
                flag[t[i]-'a']--;
            } else {
                return false;
            }
        }
        
        return true;
    }
};