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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2; 
        if (l2 == nullptr) return l1; 

        int carry = 0;
        ListNode *temp1 = l1, *temp2 = l2; 
        temp1 -> val = temp1 -> val + temp2 -> val; 
        carry = temp1 -> val / 10; 
        temp1 -> val = temp1 -> val % 10;

        while (temp1 -> next != nullptr && temp2 -> next != nullptr){
            temp1 -> next -> val = temp1 -> next -> val + temp2 -> next -> val + carry;
            carry = temp1 -> next -> val / 10; 
            temp1 -> next -> val = temp1 -> next -> val % 10;
            temp1 = temp1 -> next; 
            temp2 = temp2 -> next;
        }

        if (temp2 -> next != nullptr){
            temp1 -> next = temp2 -> next; 
        }

        while (temp1 -> next != nullptr && carry != 0){
            temp1 -> next -> val += carry; 
            carry = temp1 -> next -> val / 10;
            temp1 -> next -> val = temp1 -> next -> val % 10; 
            temp1 = temp1 -> next;
        }

        if (carry != 0){
            temp1 -> next = new ListNode(carry);
        }

        return l1;
    }
};