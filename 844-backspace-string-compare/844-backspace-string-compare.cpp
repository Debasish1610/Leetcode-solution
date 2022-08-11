class Solution {
public:
    
    string returnFinalString(string s) {
        stack<char> st;
        string newString;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#' && !st.empty()) {
                st.pop();
            } else if (s[i] != '#') {
                st.push(s[i]);
            }
        }
        
        while(!st.empty()) {
            newString.push_back(st.top());
            st.pop();
        }
        
        return newString;
    }
    bool backspaceCompare(string s, string t) {
        return returnFinalString(s) == returnFinalString(t);
    }
};