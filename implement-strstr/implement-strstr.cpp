class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) {
            return -1;
        }
        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            bool isExist = true;
            for (int j = 0; j < needle.size(); j++) {
                if (needle[j] != haystack[i+j]) {
                    isExist = false;
                    break;
                }
            }
            
            if (isExist) {
                return i;
            }
        }
        
        return -1;
    }
};