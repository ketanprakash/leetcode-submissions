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
    ListNode* rev(ListNode* head){
        ListNode *curr = head, *prev = NULL, *next = NULL;

        while (curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head -> next == NULL) return head;
        int n = 0; 
        ListNode *temp = head;
        while (temp != NULL){
            temp = temp -> next;
            n++;
        }
        k = k % n;

        if (k == 0) return head;

        head = rev(head);
        temp = head;
        k--;
        while (k--){
            temp = temp -> next;
        }

        ListNode* head2 = temp -> next;
        temp -> next = NULL;
        ListNode *newHead = rev(head);
        ListNode *newHead2 = rev(head2);

        head -> next = newHead2;

        return newHead;
    }
};