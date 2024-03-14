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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)return head;
        //we will take two pointers 
        //start and end
        int cnt = 1;
        ListNode* start = head;
        ListNode* end = head;
        while (end->next != nullptr) {
            end = end->next;
            cnt++;
        }
        //new cnt
         cnt = cnt / 2;
        // if(cnt % 2 == 0){
        //     cnt = cnt/2;
        // }else{
        //     cnt = (cnt/2) + 1;
        // }

        while(cnt>0){
            end->next = start->next;
            start->next = start->next->next;
            end->next->next = nullptr;
            start = start->next;
            end = end->next;
            cnt--;
        }
        return head;

        //last end to point karna he even index pe
        //even index ka prev node me even index ka next copy karna he
        //that even index ko null karna he
        //start++
        //end++
        //end ->next == temp->next
        //temp->next=temp->next->next;
        //cnt we will take which will decide number of times we need do opeartion cnt/2 
    }
};