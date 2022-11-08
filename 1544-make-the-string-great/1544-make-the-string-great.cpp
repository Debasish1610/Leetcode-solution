class Solution {
public:
    
    string makeGood(string s) {
        stack<char>st;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty()) {
                char ch1 = st.top();
                char ch2 = s[i];
                if ((isupper(ch1) && islower(ch2)) || (isupper(ch2) && islower(ch1))) {
                    if (tolower(ch1) == tolower(ch2)) {
                        st.pop();
                    } else {
                        st.push(s[i]);
                    }
                } else {
                    st.push(s[i]);
                }
                
            } else {
                st.push(s[i]);
            }
        }
        string str;
        while(!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }
        
        reverse(str.begin(), str.end());
        return str;
    }
};