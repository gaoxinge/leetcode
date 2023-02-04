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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *root = new ListNode();
        ListNode *temp = root;
        while (list1 != nullptr || list2 != nullptr) {
            int val;
            if (list1 == nullptr) {
                val = list2->val;
                list2 = list2->next;
            } else if (list2 == nullptr) {
                val = list1->val;
                list1 = list1->next;
            } else {
                int val1 = list1->val;
                int val2 = list2->val;
                if (val1 <= val2) {
                    val = val1;
                    list1 = list1->next;
                } else {
                    val = val2;
                    list2 = list2->next;
                }
            }
            temp->next = new ListNode(val);
            temp = temp->next; 
        }
        return root->next;
    }
};
