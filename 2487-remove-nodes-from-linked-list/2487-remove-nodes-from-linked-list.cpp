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
    ListNode* removeNodes(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        ListNode* temp = prev;
        ListNode* prev_prev = nullptr; 
        int max_val = INT_MIN;
        
        while (temp != nullptr) {
            if (temp->val < max_val) {
                ListNode* toDelete = temp;
                temp = temp->next;
                delete toDelete;
                if (prev_prev) {
                    prev_prev->next = temp;
                } else {
                    head = temp;
                }
            } else {
                max_val = temp->val;
                prev_prev = temp;
                temp = temp->next;
            }
        }
        
        ListNode* ans = nullptr;
        while (prev != nullptr) {
            ListNode* next = prev->next;
            prev->next = ans;
            ans = prev;
            prev = next;
        } 
        
        return ans;
    }
};