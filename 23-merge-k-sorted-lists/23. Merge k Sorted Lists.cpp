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
    ListNode* merge2Lists(ListNode* list1, ListNode* list2){
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode *dummy = new ListNode(0);

        ListNode *temp = dummy;

        while (list1 != nullptr && list2 != nullptr){
            if (list1 -> val <= list2 -> val){
                temp -> next = list1; 
                temp = temp -> next;
                list1 = list1 -> next; 
                temp -> next = nullptr;
            }
            else {
                temp -> next = list2;
                temp = temp -> next;
                list2 = list2 -> next;
                temp -> next = nullptr;
            }
        }

        if (list1 != nullptr){
            temp -> next = list1;
        }

        if (list2 != nullptr){
            temp -> next = list2;
        }

        return dummy -> next;
    }

    ListNode* mergeKLists(vector<ListNode*> &lists, int s, int e){
        if (s > e) return nullptr;
        if (s == e) return lists[s];
        int m = s + (e - s) / 2;

        ListNode *list1 = mergeKLists(lists, s, m);
        ListNode *list2 = mergeKLists(lists, m + 1, e);
        return merge2Lists(list1, list2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }
};