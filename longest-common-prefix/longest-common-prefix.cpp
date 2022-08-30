class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output;
        if (strs.size() == 1) {
            return strs[0];
        }
        for (int len = 0; ; len++) {
            bool isAllCharSame = false;
            for (int i = 1; i < strs.size(); i++) {
                if (len < strs[i].size() && len < strs[i-1].size() && strs[i][len] == strs[i-1][len]) {
                    isAllCharSame = true;
                } else {
                    isAllCharSame = false;
                    break;
                }
            }
            
            if (isAllCharSame) {
                output.push_back(strs[0][len]);
            } else {
                break;
            }
        }
        
        return output;
    }
};