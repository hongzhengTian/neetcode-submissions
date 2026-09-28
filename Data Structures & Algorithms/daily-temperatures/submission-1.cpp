class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = static_cast<int>(temperatures.size());
        vector<int> result(n, 0);
        stack<int> st; // 保存尚未找到更高温的下标

        for (int i = 0; i < n; ++i) {
            while (!st.empty() &&
                   temperatures[i] > temperatures[st.top()]) {

                int previous = st.top();
                st.pop();

                result[previous] = i - previous;
            }

            st.push(i);
        }

        return result;
    }
};