class Solution {
private:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        // 其中一条走完了，另一条剩余部分本来就是有序的
        tail->next = (a != nullptr) ? a : b;
        return dummy.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        int count = static_cast<int>(lists.size());

        while (count > 1) {
            int newCount = 0;

            for (int i = 0; i < count; i += 2) {
                ListNode* a = lists[i];
                ListNode* b = (i + 1 < count) ? lists[i + 1] : nullptr;

                lists[newCount] = mergeTwoLists(a, b);
                ++newCount;
            }

            count = newCount;
        }

        return lists[0];
    }
};