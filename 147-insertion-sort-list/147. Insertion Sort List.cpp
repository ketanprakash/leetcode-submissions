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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head;
        ListNode* dummy = new ListNode(-5001);

        ListNode *temp, *temp1;
        while (head != nullptr){
            temp = dummy; 
            while (temp -> next != nullptr && temp -> next -> val < head -> val){
                temp = temp -> next;
            }
            temp1 = head; 
            head = head -> next;
            temp1 -> next = temp -> next; 
            temp -> next = temp1;
        }

        return dummy -> next;
    }
};