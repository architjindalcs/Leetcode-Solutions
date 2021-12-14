/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string helper(TreeNode* root){
        if(!root){
            return "X,"; //null node..
        }
        return to_string(root->val)+","+helper(root->left)+helper(root->right);
    }
    string serialize(TreeNode* root) {
        return helper(root);
    }

    TreeNode* mtree(queue<int>& q){
        if(q.empty()) return NULL;
        int fr=q.front();
         q.pop();
        if(fr==INT_MAX) return NULL;
       
        TreeNode* nn=new TreeNode(fr);
        nn->left=mtree(q);
        nn->right=mtree(q);
        return nn;
    }
    TreeNode* deserialize(string s) {
        queue<int> q;
        int i=0;
        string cs="";
        while(i<s.size()){
            if(s[i]==','){
                if(cs=="X") q.push(INT_MAX);
                else q.push(stoi(cs));
                cs="";
                //i++;
            }
            else cs+=s[i];
            i++;
        }
        return mtree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));