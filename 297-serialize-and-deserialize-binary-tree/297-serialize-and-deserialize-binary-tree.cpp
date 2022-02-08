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
    
    string serialize(TreeNode* root) {
        if(!root) return "X";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }
    TreeNode* helper(queue<int>& q){
        if(q.empty()) return NULL;
        int fr=q.front();
        q.pop();
        if(fr==INT_MAX) return NULL;
        TreeNode* root=new TreeNode(fr);
        root->left=helper(q);
        root->right=helper(q);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<int> q;
        data+=",";
        int i=0;
        string cs="";
        while(i<data.size()){
            if(data[i]==','){
                if(cs!="X")
                    q.push(stoi(cs));
                else q.push(INT_MAX);
                cs="";
                i++;
            }
            else cs+=data[i++];
        }
        return helper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));