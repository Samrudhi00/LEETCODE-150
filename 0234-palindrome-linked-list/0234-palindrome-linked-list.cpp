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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true; 
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        // To get the middle element
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        
        //fast is not null means odd are their 1 2 3 2 1
        //take next
        if (fast != nullptr)
            slow = slow->next;
        
        
        // compare and cheak
        while (prev != nullptr && slow != nullptr) {
            if (prev->val != slow->val)
                return false; 
            prev = prev->next;
            slow = slow->next;
        }
        
        return true; 
    }
};
