class Solution {
public:
    
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
    string decodeString(string s) {
        string decode, temp;
        stack<string> st;
        stack<int> repeat;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                temp.push_back(s[i]);
                st.push(temp);
                temp = "";
            } else {
                while(st.top() != "[") {
                    temp.append(reverseString(st.top()));
                    st.pop();
                }
                st.pop();
                
                string revString = reverseString(temp);
                temp = "";
                while(!st.empty() && st.top().size() == 1 && isdigit(st.top()[0])) {
                    temp.append(reverseString(st.top()));
                    st.pop();
                }
                reverse(temp.begin(), temp.end());
                int repeat = stoi(temp);
                temp = "";
                for(int j = 0; j < repeat; j++) {
                    st.push(revString);
                }
            }
        }
        
        while(!st.empty()) {
            decode.append(reverseString(st.top()));
            st.pop();
        }
                             
        return reverseString(decode);
    }
};