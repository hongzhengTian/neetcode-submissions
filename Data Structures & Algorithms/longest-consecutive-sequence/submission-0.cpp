class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int longest = 1, current = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) continue;       // 去重
            if (nums[i] == nums[i-1] + 1) current++;  // 连上了
            else current = 1;                          // 断了,重新计数
            longest = max(longest, current);
        }
        return longest;
    }
};
