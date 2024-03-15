/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        int lengthA = 0, lengthB = 0;
        ListNode *tempA = headA, *tempB = headB;

        while (tempA != nullptr) {
            lengthA++;
            tempA = tempA->next;
        }
        while (tempB != nullptr) {
            lengthB++;
            tempB = tempB->next;
        }

        tempA = headA;
        tempB = headB;

        if (lengthA > lengthB) {
            int diff = lengthA - lengthB;
            while (diff > 0) {
                tempA = tempA->next;
                diff--;
            }
        } else {
            int diff = lengthB - lengthA;
            while (diff > 0) {
                tempB = tempB->next;
                diff--;
            }
        }

        while (tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return tempA;
    }
};
