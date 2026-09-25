class Solution {
public:
    int trap(vector<int>& height) {
        int n = static_cast<int>(height.size());
        if (n < 3) {
            return 0;
        }

        // 1. 找到一个全局最高柱
        int peak = 0;
        for (int i = 1; i < n; ++i) {
            if (height[i] > height[peak]) {
                peak = i;
            }
        }

        int total = 0;
        int pending = 0;

        // 2. 左侧：从左往最高柱扫描
        int left = 0;

        for (int right = 1; right <= peak; ++right) {
            if (height[right] < height[left]) {
                pending += height[left] - height[right];
            } else {
                // 找到不低于左边界的右边界，结算
                total += pending;
                pending = 0;
                left = right;
            }
        }

        // 3. 右侧：从右往最高柱扫描
        pending = 0;
        int right = n - 1;

        for (int left = n - 2; left >= peak; --left) {
            if (height[left] < height[right]) {
                pending += height[right] - height[left];
            } else {
                // 找到不低于右边界的左边界，结算
                total += pending;
                pending = 0;
                right = left;
            }
        }

        return total;
    }
};