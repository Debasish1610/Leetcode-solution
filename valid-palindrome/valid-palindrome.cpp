class Solution {
public:
    bool isPalindrome(string s) {
        string strAfterRemoveNonAlphaChar;
        
        for (int i = 0; i < s.size(); i++) {
            char ch = tolower(s[i]);
            
            if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
                strAfterRemoveNonAlphaChar.push_back(ch);
            }
        }
        
        
        int strLen = strAfterRemoveNonAlphaChar.size();
        
        for (int i = 0; i < (strLen-i); i++) {
            if (strAfterRemoveNonAlphaChar[i] != strAfterRemoveNonAlphaChar[strLen-i-1]) {
                return false;
            }
        }
        
        return true;
    }
};