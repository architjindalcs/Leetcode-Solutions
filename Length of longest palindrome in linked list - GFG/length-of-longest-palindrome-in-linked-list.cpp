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

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends


/* The Node is defined 
  /* Link list Node
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

/*The function below returns an int denoting
the length of the longest palindrome list. */
int maxL(Node* n1,Node* n2){
    int cnt=0;
    while(n1 and n2 and n1->data==n2->data){
        cnt++;
        n1=n1->next;
        n2=n2->next;
    }
    return cnt;
}
int maxPalindrome(Node *head)
{
    int ans=1;
    if(!head) return 0;
    if(!(head->next)) return 1;
    Node* curr=head;
    Node* prev=NULL;
    //Your code here
    int maxm=1;
    while(curr){
        Node* next=curr->next;
        curr->next=prev;
        int even=2*maxL(curr,next);
        int odd=1+2*maxL(prev,next);
        maxm=max(maxm,max(even,odd));
        prev=curr;
        curr=next;
    }
    return maxm;
}