class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        int n = static_cast<int>(nums.size());

        for (int right = 0; right < n; ++right) {
            // 1. 删除已经离开窗口的候选者
            while (!dq.empty() && dq.front() <= right - k) {
                dq.pop_front();
            }

            // 2. 新元素淘汰队尾中不比它大的候选者
            while (!dq.empty() && nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }

            // 3. 当前元素作为新候选者加入
            dq.push_back(right);

            // 4. 已形成完整窗口，记录最大值
            if (right >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};