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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0; 
        ListNode* temp = head; 

        while (temp != nullptr){
            temp = temp -> next; 
            n++;
        }
        
        int count = n / k, newCount = 0; 
        int extra = n % k; 
        vector<ListNode*> ans;

        while (k--){
            newCount = count;
            if (extra > 0){
                newCount++; 
                extra--; 
            }
            if (newCount == 0){
                ans.push_back(nullptr);
                continue;
            }
            newCount--; 
            temp = head; 
            while (newCount--){
                temp = temp -> next;
            }
            ans.push_back(head);
            head = temp -> next; 
            temp -> next = nullptr;
        }

        return ans;
    }
};