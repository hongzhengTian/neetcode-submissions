class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        int n = static_cast<int>(nums.size());

        for (int i = 0; i < n; ++i) {
            int need = target - nums[i];

            auto it = seen.find(need);

            if (it != seen.end()) {
                return {it->second, i};
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};
