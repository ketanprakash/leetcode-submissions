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

    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0; 
        ListNode *t = head; 

        while (t != nullptr){
            n++;
            t = t -> next;
        }
        k = min(k, n - k + 1);
        k--;
        ListNode *slow = head, *fast = head, *temp;

        while (fast != nullptr && fast -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        fast = head; 
        slow = reverse(slow);
        temp = slow;

        while (k--){
            fast = fast -> next;
            temp = temp -> next;
        }

        swap(fast -> val, temp -> val);
        slow = reverse(slow);

        return head;
    }
};