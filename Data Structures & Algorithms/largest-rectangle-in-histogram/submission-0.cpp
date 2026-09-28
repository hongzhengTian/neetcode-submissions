class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = static_cast<int>(heights.size());
        int best = 0;

        // {最早起点, 高度}
        stack<pair<int, int>> st;

        for (int i = 0; i < n; ++i) {
            int start = i;

            // 当前柱子更矮，结算被挡住的高矩形
            while (!st.empty() && st.top().second > heights[i]) {
                int oldStart = st.top().first;
                int oldHeight = st.top().second;
                st.pop();

                int width = i - oldStart;
                best = max(best, oldHeight * width);

                // 当前较矮的高度可以延伸到旧矩形的起点
                start = oldStart;
            }

            st.push({start, heights[i]});
        }

        // 剩下的矩形一直没有被矮柱子挡住，可以延伸到末尾
        while (!st.empty()) {
            int start = st.top().first;
            int height = st.top().second;
            st.pop();

            int width = n - start;
            best = max(best, height * width);
        }

        return best;
    }
};