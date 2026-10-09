class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 站在下标 i，下一步走到下标 nums[i]，如果有重复，会形成环
        int slow = nums[0];
        int fast = nums[nums[0]];
        // slow 每次沿着 nums[i] 走一步；fast 走两步，找到环内相遇点。
        // 从下标 0 再出发一个指针；它与相遇点指针都每次走一步，再次相遇的位置就是环的入口
        // 第一阶段，在环内相遇
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // 第二阶段，寻找环的入口
        int finder = 0;
        while (finder != slow) {
            finder = nums[finder];
            slow = nums[slow];
        }
        return finder;
    }
};
