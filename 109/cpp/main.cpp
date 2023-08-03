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
    TreeNode *sortedListToBST(vector<int> &nums, int i, int j) {
        if (j - i == 0) {
            return nullptr;
        }
        int k = i + (j - i) / 2;
        auto left = sortedListToBST(nums, i, k);
        auto right = sortedListToBST(nums, k + 1, j);
        return new TreeNode(nums[k], left, right);
    }

    TreeNode* sortedListToBST(vector<int>& nums) {
        return sortedListToBST(nums, 0, nums.size());
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        for (; head != nullptr; head = head->next) {
            nums.push_back(head->val);
        }
        return sortedListToBST(nums);
    }
};
