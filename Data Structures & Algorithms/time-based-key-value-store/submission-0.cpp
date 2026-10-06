class TimeMap {
    unordered_map<string, vector<pair<int, string>>> history;

public:
    TimeMap() = default;

    void set(string key, string value, int timestamp) {
        history[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = history.find(key);
        if (it == history.end()) return "";

        const auto& records = it->second;
        int left = 0;
        int right = static_cast<int>(records.size()); // 右边界不包含

        // 找第一个时间戳 > timestamp 的位置
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (records[mid].first <= timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // left 前一条就是最后一个 <= timestamp 的记录
        return left == 0 ? "" : records[left - 1].second;
    }
};