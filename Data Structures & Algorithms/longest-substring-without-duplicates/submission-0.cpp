class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;

        int left = 0;
        int best = 0;
        int n = static_cast<int>(s.size());

        for (int right = 0; right < n; ++right) {
            // 新字符与窗口中的某个字符重复
            while (window.count(s[right]) > 0) {
                window.erase(s[left]);
                ++left;
            }

            // 现在可以安全加入新字符
            window.insert(s[right]);

            // 当前窗口是 [left, right]
            best = max(best, right - left + 1);
        }

        return best;
    }
};