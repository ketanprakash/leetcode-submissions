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
    ListNode* reverse(ListNode *head){
        ListNode *prev = nullptr, *curr = head, *next; 

        while (curr != nullptr){
            next = curr -> next; 
            curr -> next = prev; 
            prev = curr; 
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head -> next == nullptr) return head;\
        int k1 = k;
        k--; 
        ListNode *temp = head;
        while (k--){
            temp = temp -> next; 
            if (temp == nullptr) return head;
        }

        ListNode* restHead = temp -> next;
        temp -> next = nullptr; 
        restHead = reverseKGroup(restHead, k1);
        ListNode* newHead = reverse(head);
        head -> next = restHead;
        
        return newHead;
    }
};