class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            ++freq[x];
        }
        vector<pair<int, int>> items;
        for (auto x : freq) {
            items.push_back({x.first, x.second});
        }
        sort(items.begin(), items.end(),
            [](pair<int, int> a, pair<int, int> b){
                return a.second > b.second;
            }
        );
        vector<int> results;
        for (int i = 0; i < k; ++i) {
            results.push_back(items[i].first);
        }
        return results;
    }
};
