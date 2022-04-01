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
    ListNode* getMid(ListNode* head,ListNode*& prev){
        /*
        [1,2],3,4
        s  s  s
        f        f
        1,2,[3],4,5
        */
        ListNode* s=head;
        ListNode* f=s;;
        while(f and f->next){
            if(!prev) prev=s;
            else prev=prev->next;
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!(head->next)) return new TreeNode(head->val);
        
        ListNode* prev=NULL;
        ListNode* mid=getMid(head,prev);
        
        ListNode* l1=head;
        ListNode* l2=mid->next;
        mid->next=NULL;
        TreeNode* nn=new TreeNode(mid->val);
        prev->next=NULL;
        
        nn->left=sortedListToBST(l1);
        nn->right=sortedListToBST(l2);
        return nn;
    }
};