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
        ListNode *prev = nullptr, *curr = head, *next; 

        while (curr != nullptr){
            next = curr -> next; 
            curr -> next = prev; 
            prev = curr; 
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return true;

        ListNode *slow = head, *fast = head; 

        while (fast != nullptr && fast -> next != nullptr){
            fast = fast -> next -> next; 
            slow = slow -> next;
        }

        fast = head;
        slow = reverse(slow);

        while (slow != nullptr && fast != nullptr){
            if (fast -> val != slow -> val) return false;
            fast = fast -> next; 
            slow = slow -> next;
        }

        return true;
    }
};