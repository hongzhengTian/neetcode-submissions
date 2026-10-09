/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int answer = 0;

    // 返回以node为根的子树深度，按节点数计算
    int depth(TreeNode* node) {
        if (node == nullptr) return 0;

        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);

        // 经过当前节点的路径长度，按边数计算
        answer = max(answer, leftDepth + rightDepth);

        return 1 + max(leftDepth, rightDepth);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        answer = 0;
        depth(root);
        return answer;
    }
};
