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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while (true) {
            // 1. 找到本组的第 k 个节点；不足 k 个就结束
            ListNode* kth = groupPrev;
            for (int i = 0; i < k; ++i) {
                kth = kth->next;
                if (kth == nullptr) {
                    return dummy.next;
                }
            }

            ListNode* groupNext = kth->next;
            ListNode* groupStart = groupPrev->next;

            // 2. 只翻转本组，走到 groupNext 就停
            ListNode* prev = groupNext;
            ListNode* curr = groupStart;

            while (curr != groupNext) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // 3. 接好本组的前端，并准备处理下一组
            groupPrev->next = kth;
            groupPrev = groupStart;
        }
    }
};
