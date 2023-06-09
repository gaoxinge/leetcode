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
    ListNode* partition(ListNode* head, int x) {
        ListNode *r1 = new ListNode();
        ListNode *t1 = r1;
        ListNode *r2 = new ListNode();
        ListNode *t2 = r2;
        while (head != nullptr) {
            int val = head->val;
            if (val < x) {
                t1->next = new ListNode(val);
                t1 = t1->next;
            } else {
                t2->next = new ListNode(val);
                t2 = t2->next;
            }
            head = head->next;
        }
        t1->next = r2->next;
        return r1->next;
    }
};
