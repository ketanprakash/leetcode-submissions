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

    int pairSum(ListNode* head) {
        ListNode *fast = head, *slow = head; 

        while (fast != nullptr && fast -> next != nullptr){
            fast = fast -> next -> next; 
            slow = slow -> next;
        }

        fast = head; 
        slow = reverse(slow);

        int ans = 0; 

        while (slow != nullptr){
            ans = max(ans, slow -> val + fast -> val);
            slow = slow -> next; 
            fast = fast -> next;
        }

        return ans;
    }
};