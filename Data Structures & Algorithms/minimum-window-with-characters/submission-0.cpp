class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (char c : t) {
            ++need[c];
        }

        int required = static_cast<int>(need.size());
        int formed = 0;

        int left = 0;
        int n = static_cast<int>(s.size());

        int bestStart = 0;
        int bestLength = n + 1;

        for (int right = 0; right < n; ++right) {
            char c = s[right];
            ++window[c];

            // 当前字符刚好达到所需次数
            if (need.count(c) > 0 && window[c] == need[c]) {
                ++formed;
            }

            // 已经覆盖 t，尽可能缩短窗口
            while (formed == required) {
                int length = right - left + 1;

                if (length < bestLength) {
                    bestLength = length;
                    bestStart = left;
                }

                char removed = s[left];
                --window[removed];

                // 移出后，这种字符不再满足需求
                if (need.count(removed) > 0 &&
                    window[removed] < need[removed]) {
                    --formed;
                }

                ++left;
            }
        }

        if (bestLength == n + 1) {
            return "";
        }

        return s.substr(bestStart, bestLength);
    }
};