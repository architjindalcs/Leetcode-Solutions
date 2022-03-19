// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        if(!head or k==0) return head;
        int len=0;
        Node* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        k=k%len;
        if(!k) return head;
        //1,2,3,4,5  -> k=3   -> 4,5, [1,2,3]
        
        int cnt=1;
        Node* prev=head;
        Node* curr=head->next;
        while(cnt!=k){
            curr=curr->next;
            prev=prev->next;
            cnt++;
        }
        Node* ans=prev->next;
        prev->next=NULL;
        while(curr->next) curr=curr->next;
        curr->next=head;
        return ans;
    }
};
    


// { Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}
  // } Driver Code Ends