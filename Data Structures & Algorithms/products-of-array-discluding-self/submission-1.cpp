class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size_of_nums = static_cast<int>(nums.size());
        vector<int> output(size_of_nums, 1);
        for (int k = 1; k < size_of_nums; ++k) {
            output[k] = output[k - 1] * nums[k - 1];
        }
        int product_of_right = 1;
        for (int j = size_of_nums - 1; j >= 0; --j) {
            output[j] = output[j] * product_of_right;
            if (j > 0) {
                product_of_right = product_of_right * nums[j];
            }
        }
        return output;
    }
};
