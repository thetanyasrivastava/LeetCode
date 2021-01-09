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
    ListNode* reverseList(ListNode* head) {
        ListNode *temp=head, *ptr=NULL, *curr=NULL;
        
        while(temp!=NULL)
        {
            ptr=temp;
            temp=temp->next;
            ptr->next=curr;
            curr=ptr;
            
        }
        return curr;
    }
};
