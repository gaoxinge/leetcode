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
public:
    void flatten(TreeNode* root) {
        vector<TreeNode *> r;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            if (node != nullptr) {
                r.push_back(node);
                s.push(node->right);
                s.push(node->left);
            }
        }
        TreeNode *dummy = new TreeNode();
        TreeNode *temp = dummy;
        for (auto &node: r) {
            temp->left = nullptr;
            temp->right = node;
            temp = temp->right;
        }
        delete dummy;
    }
};
