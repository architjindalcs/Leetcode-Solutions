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

    // Decodes your encoded data to tree.
    TreeNode* helper(vector<int>& pre,int& pI,int minm,int maxm){
        if(pI>=pre.size()) return NULL;
        int key=pre[pI];
        if(key>minm and key<maxm){
            TreeNode* nn=new TreeNode(key);
            pI++;
            nn->left=helper(pre,pI,minm,key);
            nn->right=helper(pre,pI,key,maxm);
            return nn;
        }
        return NULL;
    }
    TreeNode* deserialize(string data) {
        vector<int> pre;
        data+=",";
        int i=0;
        string cs="";
        while(i<data.size()){
            if(data[i]==','){
                if(cs!="X")
                    pre.push_back(stoi(cs));
                cs="";
                i++;
            }
            else cs+=data[i++];
        }
        int pI=0;
        return helper(pre,pI,INT_MIN,INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;