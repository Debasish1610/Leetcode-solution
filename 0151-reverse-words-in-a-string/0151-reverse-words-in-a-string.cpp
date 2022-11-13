class Solution {
public:
    string reverseWords(string s) {
        vector<string>str;
        string temp, output;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (temp.size() != 0) {
                    str.push_back(temp);
                    temp = "";
                }
            } else {
                temp.push_back(s[i]);
            }
        }
        if (temp.size() != 0) {
            str.push_back(temp);
            temp = "";
        }
        
        for (int i = str.size() - 1; i >= 0; i--) {
            output += str[i];
            if (i != 0) {
                output.push_back(' ');
            }
        }
        
        return output;
    }
};