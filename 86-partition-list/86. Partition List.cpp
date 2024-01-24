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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy1 = new ListNode(0);
        ListNode *dummy2 = new ListNode(0);
        dummy2 -> next = head; 

        ListNode* temp1 = dummy1, *temp2 = dummy2; 

        while (temp2 -> next != nullptr){
            if (temp2 -> next -> val < x){
                temp1 -> next = temp2 -> next;
                temp2 -> next = temp2 -> next -> next; 
                temp1 = temp1 -> next; 
                temp1 -> next = nullptr;
            }
            else temp2 = temp2 -> next;
        }
        temp1 -> next = dummy2 -> next; 

        return dummy1 -> next;
    }
};