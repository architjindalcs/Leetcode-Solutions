// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



 // } Driver Code Ends
/* Node structure

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
       if(!head or !(head->next)) return;
       // Your Code here
       int odd=1;
       Node* curr=head->next;
       Node* prev=head;
       bool rm=false;
       while(curr){
           if(rm){
               odd++;
               Node* currNext=curr->next;
               prev->next=currNext;
               curr->next=head;
               head=curr;
               curr=currNext;
           }
           else{
               curr=curr->next;
               prev=prev->next;
           }
           rm=!(rm);
       }
       // [odd = 4] even-3
       curr=head;
       prev=NULL;
       while(odd--){
           Node* temp=curr->next;
           curr->next=prev;
           prev=curr;
           curr=temp;
       }
       head->next=curr;
       
    //   return prev;
    }
};


// { Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends