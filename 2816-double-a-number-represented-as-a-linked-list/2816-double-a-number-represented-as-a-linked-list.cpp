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
    ListNode* doubleIt(ListNode* head) {

        if (head == nullptr) {
            return nullptr;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        ListNode* temp = prev;
        int carry = 0; 
        
        while (temp != nullptr) {
            int doubledValue = temp->val * 2 + carry;
            temp->val = doubledValue % 10;
            carry = doubledValue / 10;

            // Keep track of the next node
            ListNode* nextNode = temp->next;

            if (nextNode == nullptr && carry > 0) {
                temp->next = new ListNode(carry);
                break; 
            }

            temp = nextNode; 
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
