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
    bool isValidBST(TreeNode *root, int &minValue, int &maxValue) {
        minValue = root->val;
        maxValue = root->val;
        if (root->left != nullptr) {
            int leftMinValue, leftMaxValue;
            if (!isValidBST(root->left, leftMinValue, leftMaxValue)) {
                return false;
            }
            if (leftMaxValue >= root->val) {
                return false;
            }
            minValue = leftMinValue;
        }
        if (root->right != nullptr) {
            int rightMinValue, rightMaxValue;
            if (!isValidBST(root->right, rightMinValue, rightMaxValue)) {
                return false;
            }
            if (rightMinValue <= root->val) {
                return false;
            }
            maxValue = rightMaxValue;
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        int minValue, maxValue;
        return isValidBST(root, minValue, maxValue);
    }
};
