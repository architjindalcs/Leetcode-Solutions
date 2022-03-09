// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    unordered_map<int,int> m;
    Node* helper(int pre[],int& pI,int n,int st,int end){
        if(st>end) return NULL;
        if(pI>=n) return NULL;
        Node* nn=new Node(pre[pI++]);
        if(st==end) return nn;
        int idx=m[nn->data];
        nn->left=helper(pre,pI,n,st,idx-1);
        nn->right=helper(pre,pI,n,idx+1,end);
        return nn;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        for(int i=0;i<n;i++){
            m[in[i]]=i;
        }
        int pI=0;
        return helper(pre,pI,n,0,n-1);
        // Code here
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends