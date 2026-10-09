/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> copies;

        // 第一遍：为每个旧节点创建一个新节点
        for (Node* old = head; old != nullptr; old = old->next) {
            copies[old] = new Node(old->val);
        }

        // 第二遍：连接新节点的 next 和 random
        for (Node* old = head; old != nullptr; old = old->next) {
            Node* fresh = copies[old];
            fresh->next = old->next ? copies[old->next] : nullptr;
            fresh->random = old->random ? copies[old->random] : nullptr;
        }

        return copies[head];
    }
};
