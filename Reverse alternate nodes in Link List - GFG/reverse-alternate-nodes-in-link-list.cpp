// { Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


 // } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node* reverse(Node* head){
        if(!head) return NULL;
        Node* prev=NULL;
        Node* curr=head;
        while(curr){
            Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    void rearrange(struct Node *head)
    {
        if(!head or !(head->next)) return;
        //4->1->5->4 REV 4->5->1->4
        //add code here
        Node* nhead=NULL;
        Node* ntail=NULL;
        
        Node* prev=head;
        Node* curr=head->next;
        bool rm=true;
        while(curr){
            if(rm){
                if(!nhead){
                    nhead=ntail=curr;
                }
                else{
                    ntail->next=curr;
                    ntail=curr;
    
                }
                prev->next=curr->next;
                curr=curr->next;
            }
            else{
                curr=curr->next;
                prev=prev->next;
            }
            rm=!rm;
        }
        ntail->next=NULL;
        
        //4->1->5->4
        
        prev->next=reverse(nhead);
    }
};



// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}
  // } Driver Code Ends