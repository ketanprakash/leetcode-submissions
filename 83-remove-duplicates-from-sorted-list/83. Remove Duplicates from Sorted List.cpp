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
        if (head == nullptr || head -> next == nullptr) return head;
        ListNode *ans = head; 
        head = head -> next; 
        ans -> next = nullptr;

        ListNode *temp = head;
        ListNode *temp1 = ans; 

        while (temp != nullptr){
            if (temp -> val != temp1 -> val) {
                temp1 -> next = temp; 
                temp = temp -> next; 
                temp1 = temp1 -> next;
                temp1 -> next = nullptr;
            }
            else {
                temp = temp -> next;
            }
        }

        return ans;
    }
};