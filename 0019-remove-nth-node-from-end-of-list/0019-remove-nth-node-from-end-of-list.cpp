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

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nextptr = head;
        while(n!=0){
            nextptr = nextptr->next;
            n--;
        }
        while(nextptr != nullptr){
            //maintain three pointers
            prev = current;
            current = current->next; 
            nextptr = nextptr->next;
        }
        if (prev == nullptr) { 
            head = head->next;
        } else {
            prev->next = current->next;
        }
       // prev->next = current->next;
        // current->next = nullptr;
        delete current;

     return head;
    }
};