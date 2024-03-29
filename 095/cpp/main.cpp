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

    TreeNode *generateTree(std::vector<int> inorder, std::vector<int> preorder, bool &check) {
        if (inorder.empty()) {
            check = true;
            return nullptr;
        }

        int t = preorder[0];
        auto it = std::find(inorder.begin(), inorder.end(), t);
        if (it == inorder.end()) {
            check = false;
            return nullptr;
        }
        int idx = std::distance(inorder.begin(), it);

        std::vector<int> leftInorder(inorder.begin(), it);
        std::vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + idx + 1);
        auto left = generateTree(leftInorder, leftPreorder, check);
        if (!check) {
            return nullptr;
        }

        std::vector<int> rightInorder(it + 1, inorder.end());
        std::vector<int> rightPreorder(preorder.begin() + idx + 1, preorder.end());
        auto right = generateTree(rightInorder, rightPreorder, check);
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
            auto r = generateTree(inorder, preorder, check);
            if (check) {
                result.push_back(r);
            }
        }

        return result;
    }
};
