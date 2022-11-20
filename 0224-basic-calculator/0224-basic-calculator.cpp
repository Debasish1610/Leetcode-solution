class Solution {
public:
    int calculate(string s) {
        string removeSpace;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                removeSpace.push_back(s[i]);
            }
        }
        s = removeSpace;
        stack<string>st;
        string str = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '-') {
                if (s[i+1] >= '0' && s[i+1] <= '9') {
                    string num;
                    while(i+1 < s.size() && s[i+1] >= '0' && s[i+1] <= '9') {
                        num.push_back(s[i+1]);
                        i = i+1;
                    }
                    str = "";
                    str.push_back('-');
                    str += num;
                    st.push(str);
                } else {
                    st.push("-");
                }
            } else if (s[i] == '+') {
                continue;
            } else if (s[i] == '(') {
                st.push("(");
            } else if (s[i] >= '0' && s[i] <= '9') {
                string num;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    num.push_back(s[i]);
                    i = i+1;
                }
                st.push(num);
                i = i-1;
            } else if (s[i] == ')') {
                int val = 0;
                while(!st.empty()) {
                    string tp = st.top();
                    st.pop();
                    if (tp == "(") break;
                    
                    val += stoi(tp);
                }
                
                if (!st.empty() && st.top() == "-") {
                    st.pop();
                    val = -val;
                }
                st.push(to_string(val));
            }
        }
        
        int ans = 0;
        while(!st.empty()) {
            string tp = st.top();
            st.pop();
            cout<<tp<<endl;
            int temp = stoi(tp);
            ans += temp;
        }
        
        return ans;
    }
};