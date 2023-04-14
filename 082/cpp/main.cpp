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
        ListNode *root = new ListNode();
        ListNode *temp1 = root;
        ListNode *temp2 = head;
        bool dup = false;
        for (; temp2 != nullptr && temp2->next != nullptr; temp2 = temp2->next) {
            if (temp2->val == temp2->next->val) {
                dup = true;
            } else {
                if (!dup) {
                    temp1->next = new ListNode(temp2->val);
                    temp1 = temp1->next;
                }
                dup = false;
            }
        }
        if (temp2 != nullptr && !dup) {
            temp1->next = new ListNode(temp2->val);
        }
        return root->next;
    }
};
