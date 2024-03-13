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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* last = head;
        int length = 1;
        // to get the size of LL
        while (last->next != nullptr) {
            length++;
            last = last->next;
        }

        k = k % length;
        // k if multiple of head or k at head directly return head
        if (k % length == 0)
            return head;

        // end ko start me point karna he
        last->next = head;

        // new toNewEnd
        ListNode* newEndNode = head;
        int toNewEnd = length - k - 1;
        while (toNewEnd > 0) {
            newEndNode = newEndNode->next;
            toNewEnd--;
        }
        // update head and make newEndNode null
        head = newEndNode->next;
        newEndNode->next = nullptr;

        return head;
    }
};