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
    std::vector<std::vector<int>> generate(int n) {
        if (n == 1) {
            return {{1}};
        }

        auto result = generate(n - 1);
        std::vector<std::vector<int>> result0;
        for (auto &r: result) {
            for (int i = 0; i < n; i++) {
                std::vector<int> r0(r);
                r0.insert(r0.begin() + i, n);
                result0.push_back(r0);
            }
        }

        return result0;
    }

    TreeNode *generateTree(std::vector<int> inorder, int in_i, int in_j, std::vector<int> preorder, int pre_i, int pre_j, bool &check) {
        if (in_j - in_i == 0) {
            check = true;
            return nullptr;
        }

        int t = preorder[pre_i];
        auto it = std::find(inorder.begin() + in_i, inorder.begin() + in_j, t);
        if (it == inorder.begin() + in_j) {
            check = false;
            return nullptr;
        }
        int index = std::distance(inorder.begin(), it);

        auto left = generateTree(inorder, in_i, index, preorder, pre_i + 1, pre_i + 1 + index - in_i, check);
        if (!check) {
            return nullptr;
        }

        auto right = generateTree(inorder, index + 1, in_j, preorder, pre_i + 1 + index - in_i, pre_j, check);
        if (!check) {
            return nullptr;
        }

        return new TreeNode(t, left, right);
    }

    vector<TreeNode*> generateTrees(int n) {
        std::vector<int> inorder;
        for (int i = 0; i < n; i++) {
            inorder.push_back(i + 1);
        }

        auto preorders = generate(n);
        std::vector<TreeNode *> result;
        for (auto &preorder: preorders) {
            bool check;
            auto r = generateTree(inorder, 0, n, preorder, 0, n, check);
            if (check) {
                result.push_back(r);
            }
        }

        return result;
    }
};
