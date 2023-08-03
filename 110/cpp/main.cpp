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
    int isBalanced(TreeNode *root, bool &check) {
        if (root == nullptr) {
            check = true;
            return 0;
        }
        int left = isBalanced(root->left, check);
        if (!check) {
            return -1;
        }
        int right = isBalanced(root->right, check);
        if (!check) {
            return -1;
        }
        if (abs(left - right) > 1) {
            check = false;
            return -1;
        }
        return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        bool check;
        isBalanced(root, check);
        return check;
    }
};
