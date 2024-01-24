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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(ListNode *&head, int s, int e){
        if (s > e) return nullptr;
        
        TreeNode *root = new TreeNode;
        int m = s + (e - s) / 2;

        root -> left = helper(head, s, m - 1);
        root -> val = head -> val;
        head = head -> next;
        root -> right = helper(head, m + 1, e);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int l = 0;
        ListNode *temp = head;
        while (temp != nullptr){
            l++;
            temp = temp -> next;
        }

        return helper(head, 0, l - 1);
    }
};