class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                // 先弹出右操作数，再弹出左操作数
                int right = st.top();
                st.pop();

                int left = st.top();
                st.pop();

                if (token == "+") {
                    st.push(left + right);
                } else if (token == "-") {
                    st.push(left - right);
                } else if (token == "*") {
                    st.push(left * right);
                } else {
                    st.push(left / right);
                }

            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};