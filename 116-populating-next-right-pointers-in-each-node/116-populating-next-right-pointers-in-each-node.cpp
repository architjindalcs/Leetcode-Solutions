/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* curr=root;
        Node* temp=curr;
        while(curr){
            Node* nn=new Node(0);
            Node* tail;
            tail=nn;
            while(curr){
                if(curr->left){
                    tail->next=curr->left;
                    tail=tail->next;
                }
                if(curr->right){
                    tail->next=curr->right;
                    tail=tail->next;
                }
                curr=curr->next;
            }
            curr=nn->next;
        }
        return temp;
    }
};