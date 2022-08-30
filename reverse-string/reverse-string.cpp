class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        
        for (int i = 0; i < (len-i); i++) {
            swap(s[i], s[len-i-1]);
        }
    }
};