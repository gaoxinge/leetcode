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
private:
    ListNode *head_;

public:
    Solution(ListNode* head) : head_(head) {
        std::srand(std::time(nullptr));
    }
    
    int getRandom() {
        int result = head_->val;
        int cnt = 2;
        for (ListNode *temp = head_->next; temp != nullptr; temp = temp->next, cnt++) {
            double ratio = (double) std::rand() / RAND_MAX;
            if (ratio <= 1.0 / cnt) {
                result = temp->val;
            }
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
