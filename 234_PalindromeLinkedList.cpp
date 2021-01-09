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
    bool isPalindrome(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=head;
        slow=reversenode(slow);
        
        while(slow!=NULL)
        {
            if(slow->val!=fast->val)
                return false;
            
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
    
    ListNode* reversenode(ListNode* head)
    {
        ListNode *temp=head,*ptr=NULL,*curr=NULL;
        
        while(temp!=NULL)
        {
            ptr=temp;
            temp=temp->next;
            ptr->next=curr;
            curr=ptr;
        }
        //head=curr;
        
        return curr;
    }/*
    ListNode* reversenode(ListNode* head)
    {
        ListNode *prevNode=NULL;
        
        while(head!=NULL)
        {
            ListNode *nextNode=head->next;
            head->next=prevNode;
            prevNode=head;
            head=nextNode;
        }
        return prevNode;
    }*/
};
