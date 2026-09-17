class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> output(n, 1);
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        // 从左往右
        for (int i = 1; i < n; ++i) {
            left[i] = left[i - 1] * nums[i - 1];
        }

        // 从右往左
        for (int i = n - 2; i >= 0; --i) {
            right[i] = right[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; ++i) {
            output[i] = left[i] * right[i];
        }
        return output;
    }
};
