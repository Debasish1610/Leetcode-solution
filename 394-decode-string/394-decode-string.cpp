class Solution {
public:
    string decodeString(string s) {
        string decode, temp, numstr;
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                st.push(s[i]);
            } else {
                
                while(!st.empty() && st.top() != '[') {
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                
                reverse(temp.begin(), temp.end());
                while(!st.empty() && isdigit(st.top())) {
                    numstr.push_back(st.top());
                    st.pop();
                }
                reverse(numstr.begin(), numstr.end());
                int repeat = stoi(numstr);
                for(int j = 0; j < repeat; j++) {
                    for (char ch:temp) {
                        st.push(ch);
                    }
                }
                
                
                numstr = "";
                temp = "";
            }
        }
        
        while(!st.empty()) {
            decode.push_back(st.top());
            st.pop();
        }
                
        reverse(decode.begin(), decode.end());
        return decode;
    }
};