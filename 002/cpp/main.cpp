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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *root = new ListNode(), *temp = root;
        int left = 0;
        while  (l1 != nullptr || l2 != nullptr) {
            int val1 = l1 != nullptr ? l1->val : 0;
            int val2 = l2 != nullptr ? l2->val : 0;
            int val = val1 + val2 + left;
            temp->next = new ListNode(val % 10);
            left = val / 10;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next; 
            temp = temp->next;
        }
        if (left > 0) {
            temp->next = new ListNode(left);
        }
        temp = root->next;
        delete root;
        return temp;
    }
};
