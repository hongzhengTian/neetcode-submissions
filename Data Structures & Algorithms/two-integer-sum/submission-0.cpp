class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> diffs;
        vector<int> results = {0 ,0};
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; ++i) {
            diffs.push_back(target - nums[i]);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == diffs[j]) {
                    results[0] = i;
                    results[1] = j;
                }
            }
        }
        return results;
    }
};
