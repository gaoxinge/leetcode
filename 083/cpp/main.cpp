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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *root = new ListNode(0);
        ListNode *temp = root;
        int val = -200;
        for (; head != nullptr; head = head->next) {
            if (head->val != val) {
                if (val != -200) {
                    temp->next = new ListNode(val);
                    temp = temp->next;
                }
                val = head->val;
            }
        }
        if (val != -200) {
            temp->next = new ListNode(val);
        }
        return root->next;
    }
};
