class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i = 0; i < s.size(); i++) {
            if (!st.empty() && st.top() == s[i]) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        
        string output;
        
        while(!st.empty()) {
            output.push_back(st.top());
            st.pop();
        }
        
        reverse(output.begin(), output.end());
        return output;
    }
};