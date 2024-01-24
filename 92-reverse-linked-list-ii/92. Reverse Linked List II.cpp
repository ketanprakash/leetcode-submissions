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
    ListNode* reverse(ListNode* head){
        ListNode *prev = nullptr, *curr = head, *next = nullptr; 

        while (curr != nullptr){
            next = curr -> next; 
            curr -> next = prev; 
            prev = curr; 
            curr = next;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *headLeft = head, *headRight = head; 
        left--; right--;
        while (left-- && headLeft != nullptr){
            headLeft = headLeft -> next;
        }

        while (right-- && headRight != nullptr){
            headRight = headRight -> next;
        }

        ListNode* temp = headRight -> next; 
        headRight -> next = nullptr;

        reverse(headLeft);

        headLeft -> next = temp; 

        if (head == headLeft) return headRight;

        temp = head; 

        while (temp -> next != headLeft){
            temp = temp -> next; 
        }

        temp -> next = headRight;

        return head;
    }
};