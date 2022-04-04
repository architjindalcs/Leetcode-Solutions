class TrieNode{
    public:
    TrieNode* left;
    TrieNode* right;
    TrieNode(){
        left=NULL;
        right=NULL;
    }
};
class Solution {
public:
    void insert(TrieNode* root,int num){
        TrieNode* temp=root;
        for(int i=31;i>=0;i--){
            int bit=(num&(1<<i))>0;
            if(!bit){
                //move to left
                if(temp->left) temp=temp->left;
                else{
                    temp->left=new TrieNode();
                    temp=temp->left;
                }
            }
            else{
                //move to right
                if(temp->right) temp=temp->right;
                else{
                    temp->right=new TrieNode();
                    temp=temp->right;
                }
            }
        }
    }
    int gm(TrieNode* root,int num){
        int sum=0;
        TrieNode* temp=root;
        for(int i=31;i>=0;i--){
            int bit=(num&(1<<i)) > 0;
            if(bit){
                //bit is set, i must check temp->left as it was for zero..
                if(temp->left){
                    sum+=(1<<i);
                    temp=temp->left;
                }
                else temp=temp->right;
            }
            else{
                if(temp->right){
                    sum+=(1<<i);
                    temp=temp->right;
                }
                else temp=temp->left;
            }
        }
        return sum;
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root=new TrieNode();
        insert(root,nums[0]);
        int ans=0;
        for(int i=1;i<nums.size();i++){
            ans=max(ans,gm(root,nums[i]));
            insert(root,nums[i]);
        }
        return ans;
    }
};