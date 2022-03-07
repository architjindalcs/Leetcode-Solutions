/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    void printDirect(TreeNode* root,int level){
        if(!root) return;
        if(level==0) ans.push_back(root->val);
        printDirect(root->left,level-1);
        printDirect(root->right,level-1);
    }
    int helper(TreeNode* root,TreeNode* target,int k){
        if(!root) return -1;
        if(root==target){
            printDirect(root,k);
            return 0;
        }
        int dl=helper(root->left,target,k);
        if(dl!=-1){
            int actualDist=dl+1;
            if(actualDist==k){
                ans.push_back(root->val);
            }
            else
            printDirect(root->right,k-dl-2);
            return 1+dl;
        }
        int dr=helper(root->right,target,k);
        if(dr!=-1){
            int actualDist=dr+1;
            //actualDist+1+req=k
            // req = k-1-actualDist = k-1 -(dr+1) = k-dr-2
            if(actualDist==k){
                ans.push_back(root->val);
            }
            else
            printDirect(root->left,k-dr-2);
            return 1+dr;
        }
        return -1;
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        helper(root,target,k);
        return ans;
    }
};