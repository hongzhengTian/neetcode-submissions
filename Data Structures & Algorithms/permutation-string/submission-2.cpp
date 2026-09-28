class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = static_cast<int>(s1.size());
        int n = static_cast<int>(s2.size());

        if (m > n) {
            return false;
        }

        vector<int> target(26, 0);
        vector<int> window(26, 0);

        // 统计 s1 和 s2 的第一个完整窗口
        for (int i = 0; i < m; ++i) {
            ++target[s1[i] - 'a'];
            ++window[s2[i] - 'a'];
        }

        if (window == target) {
            return true;
        }

        // right 是即将进入窗口的新字符下标
        for (int right = m; right < n; ++right) {
            --window[s2[right - m] - 'a']; // 移出最左字符
            ++window[s2[right] - 'a'];     // 加入最右新字符

            if (window == target) {
                return true;
            }
        }

        return false;
    }
};