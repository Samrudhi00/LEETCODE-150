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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* next = head;

        while(next != nullptr){
            if(n > 0){
                next = next->next;
                n--;
                continue;
            }
            
            prev = current;
            current = current->next;
            next = next->next;
        }

        if(prev == nullptr)
            head = head->next;
        else{
            prev->next = current->next;
            current->next = nullptr;
        }

        return head;
    }
};