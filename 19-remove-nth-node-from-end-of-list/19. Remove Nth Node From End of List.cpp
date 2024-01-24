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
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *temp = head, *temp1 = dummy;

        int count = 0; 
        while (temp != nullptr){
            temp = temp -> next;
            count++;
            if (count > n) temp1 = temp1 -> next;
        }

        temp1 -> next = temp1 -> next -> next;
        return dummy -> next;
    }
};