/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        int cnt=1;
        ListNode* nn=new ListNode(0);
        nn->next=head;
        ListNode* prev=nn;
        ListNode* temp=head;
        while(cnt<k){
            prev=prev->next;
            temp=temp->next;
            cnt++;
        }
        ListNode* p1=prev;
        ListNode* c1=temp;
        
        
        
        ListNode* p2=nn;
        ListNode* c2=head;
        while(temp->next){
            p2=p2->next;
            c2=c2->next;
            temp=temp->next;
        }
        if(c1==c2) return head;
        /*
        
         1,2, 3,4
           c1 c2
         p1 p2
        */
        
        
        if(c1==p2 or c2==p1){
            if(c2==p1) {
                swap(c1,c2);
                swap(p1,p2);
            }
            ListNode* c2Next=c2->next;
            p1->next=c2;
            c2->next=c1;
            c1->next=c2Next;
             return nn->next;
        }
       
        /*
           1, 2, 3, 4, 5, 6
           p1 c1    p2 c2
            
        */
        ListNode* c1Next=c1->next;
        ListNode* c2Next=c2->next;
        p1->next=c2;
        p2->next=c1;
        c2->next=c1Next;
        c1->next=c2Next;
        
        return nn->next;
    }
};