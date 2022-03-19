// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    Node* merge(Node* r1,Node* r2){
        if(!r1 and !r2) return NULL;
        if(!r1) return r2;
        if(!r2) return r1;
        if(r1->data<=r2->data){
            r1->next=merge(r1->next,r2);
            return r1;
        }
        r2->next=merge(r1,r2->next);
        return r2;
    }
    Node* getMid(Node* head,Node*& ans){
        //1,2,[3],4,5 -> 1,2,[3],4
        /*
        1,2,3,4
        s s s
        f   f   f
          f   f
          
          1,2,3
          s s
              f
        */
        Node* s=head;
        Node* f=head;
        while(f and f->next){
            if(!ans) ans=s;
            else ans=ans->next;
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(!head or !(head->next)) return head;
        Node* pptr=NULL;
        Node* mid=getMid(head,pptr);
        Node* l1=head;
        Node* l2=mid;
        pptr->next=NULL;  //left list has equal or less number of elements..
        
        return merge(mergeSort(l1),mergeSort(l2));
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends