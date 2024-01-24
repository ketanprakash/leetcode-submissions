/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL) return nullptr;

        ListNode *slow = head, *fast = head;

        do {
            slow = slow -> next;
            fast = fast -> next -> next;
        } while (fast != NULL && fast -> next != NULL && slow != fast);

        if (slow != fast) return nullptr;

        slow = head;

        while (slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }

        return slow;
    }
};