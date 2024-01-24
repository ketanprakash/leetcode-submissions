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
        if (head == NULL || head -> next == NULL || head -> next -> next == NULL) return head; 
 
        ListNode* temp = head; 
        ListNode* head2 = head -> next;
        ListNode* temp2;

        while (temp != NULL && temp -> next != NULL){
            temp2 = temp -> next;
            temp -> next = temp -> next -> next;
            temp2 -> next = temp2 -> next == NULL ? NULL : temp2 -> next -> next;
            temp = temp -> next;
        }

        temp = head; 
        while (temp -> next != NULL) temp = temp -> next;
        temp -> next = head2;
        return head;
    }
};