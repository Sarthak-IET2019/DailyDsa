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

 // 1    2
class Solution {
public:
    ListNode* merge(ListNode* head1,ListNode* head2){

        if(head1==NULL or head2==NULL) return (head1==NULL)?head2:head1;


        ListNode* dummy = new ListNode(0);
        ListNode*current=dummy;


        while(head1!=NULL and head2!=NULL){
          if(head1->val<head2->val){
              current->next=head1;
              head1=head1->next;
          }

          else {
            current->next=head2;
            head2=head2->next;
          }

          current=current->next;
        }

        if(head1!=NULL or head2!=NULL) current->next= (head1!=NULL)?head1:head2;

        return dummy->next;



    } 


    ListNode* findmid(ListNode * head){

      ListNode *slow,*fast;
      slow=head;
      fast=head;

      while(fast->next!=NULL and fast->next->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
      }

      return slow;
    }


    ListNode* solve(ListNode* head){

      if(head==NULL or head->next==NULL) return head;

      ListNode * mid =findmid(head);
      ListNode * nextmid=mid->next;
      // cout<<nextmid->val<<" "<<mid->val<<endl;
      mid->next=NULL;

      auto l=solve(head);
      auto r=solve(nextmid);
      return merge(l,r);
      // return NULL;
    }


    ListNode* sortList(ListNode* head) {

      if(head==NULL or head->next==NULL) return head;

      // ListNode *end=head;

      // while(end->next!=NULL) end=end->next;
      return solve(head);
      // return findmid(head);
      // merge(head);
      // cout<<head->val<<endl;
      // return head;
        
    }
};