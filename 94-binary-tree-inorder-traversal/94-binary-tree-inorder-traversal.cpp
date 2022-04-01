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
    TreeNode* findPred(TreeNode* curr){
        TreeNode* temp=curr->left;
        while(temp->right and temp->right!=curr)
            temp=temp->right;
        return temp;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        vector<int> ans;
        while(curr){
            if(!(curr->left)){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* pred=findPred(curr);
                if(!(pred->right)){
                    pred->right=curr;
                    curr=curr->left;
                }
                else{
                    pred->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};