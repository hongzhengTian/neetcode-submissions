class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = static_cast<int>(s1.size());
        int n = static_cast<int>(s2.size());

        // s2 放不下一个完整窗口
        if (m > n) {
            return false;
        }

        // s1 只需要排序一次
        sort(s1.begin(), s1.end());

        // 枚举长度为 m 的窗口
        for (int left = 0; left <= n - m; ++left) {
            string window = s2.substr(left, m);

            sort(window.begin(), window.end());

            if (window == s1) {
                return true;
            }
        }

        return false;
    }
};