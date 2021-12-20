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
    //-1 -> not required, 0-> no camera, 1-> has camera.
    int NR=-1,NC=0,HC=1;
    int ans=0;
    int helper(TreeNode* root){
        if(!root) return NR;
        int left=helper(root->left),right=helper(root->right);
        if(left==NC or right==NC) {
            ans++;
            return HC;
        }     
        if(left==HC or right==HC){
            //I need not place here any camera on the current node..
            return NR;
        }
        return NC; //no source of monitoring is there..
    }
    int minCameraCover(TreeNode* root) {
        if(helper(root)==NC) ans++;
        return ans;
    }
};