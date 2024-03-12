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
    ListNode* findmiddle(ListNode* head){
        // slow and fast pointers in LL
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow= slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
   ListNode* mergeTwoLists(ListNode* left_head, ListNode* right_head) {
        ListNode* result = nullptr;
        // edge condition
        if (left_head == nullptr)
            return right_head;
        if (right_head == nullptr)
            return left_head;

        if (left_head->val <= right_head->val) {
            result = left_head;
            result->next = mergeTwoLists(left_head->next, right_head);
        } else {
            result = right_head;
            result->next = mergeTwoLists(left_head, right_head->next);
        }
        return result;
    }
    ListNode* sortList(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode*  middle = findmiddle(head);
        ListNode* left_head = head;
        ListNode* right_head = middle->next;
        middle->next = nullptr;
        left_head = sortList(left_head);
        right_head = sortList(right_head);
        
        return mergeTwoLists(left_head,right_head);
           
        
    }
};