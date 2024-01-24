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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* h0 = new ListNode();
        ListNode *temp = h0, *temp1 = head, *temp2;

        while (temp1 != nullptr){
            temp2 = temp1; 

            while (temp2 -> next != nullptr && temp2 -> next -> val == temp1 -> val){
                temp2 = temp2 -> next;
            }

            if (temp1 == temp2) {
                temp -> next = temp1;
                temp = temp -> next;
            }

            temp1 = temp2 -> next;
            temp -> next = nullptr;
        }

        return h0 -> next;
    }
};