class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                // 题目保证只有六种括号，因此这里是右括号
                if (st.empty()) {
                    return false;
                }

                char top = st.top();

                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};