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
    ListNode* merge(ListNode *head1, ListNode* head2){
        if (head1 == nullptr) return head2; 
        if (head2 == nullptr) return head1; 

        ListNode *head = nullptr;

        if (head1 -> val <= head2 -> val){
            head = head1; 
            head1 = head1 -> next;
        }
        else {
            head = head2; 
            head2 = head2 -> next; 
        }
        head -> next = nullptr;

        ListNode *temp = head, *temp1 = head1, *temp2 = head2; 

        while (temp1 != nullptr && temp2 != nullptr){
            if (temp1 -> val < temp2 -> val){
                temp -> next = temp1; 
                temp = temp -> next; 
                temp1 = temp1 -> next;
            }
            else {
                temp -> next = temp2; 
                temp = temp -> next; 
                temp2 = temp2 -> next;
            }
            temp -> next = nullptr;
        }

        if (temp1 != nullptr){
            temp -> next = temp1; 
        }

        if (temp2 != nullptr){
            temp -> next = temp2;
        }

        return head;
    }

    ListNode* mergeSort(ListNode *head){
        if (head == nullptr || head -> next == nullptr) return head;
        if (head -> next -> next == nullptr){
            if (head -> val > head -> next -> val) swap(head -> val, head -> next -> val);
            return head;
        }
        ListNode *fast = head, *slow = head; 

        while (fast != nullptr && fast -> next != nullptr){
            fast = fast -> next -> next; 
            slow = slow -> next;
        }

        fast = slow -> next; 
        slow -> next = nullptr;

        head = mergeSort(head);
        fast = mergeSort(fast);

        return merge(head, fast);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};