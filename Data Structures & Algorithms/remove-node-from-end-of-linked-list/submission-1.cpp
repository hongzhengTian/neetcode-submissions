/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 做法是让两个指针保持 n 个节点的距离。先让 fast 走 n 步，再让 fast 和 slow 一起走；等 fast 到达末尾，slow 就停在待删除节点的前一个节点。为了让“删除头节点”也按同一套代码处理，先放一个虚拟头节点 dummy
        ListNode dummy(0, head);
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // 先拉开n步距离
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        // fast到尾节点时，slow正好到待删除节点的前一个节点
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next; // 跳过待删除节点
        return dummy.next;
    }
};
