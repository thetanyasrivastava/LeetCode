/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
                                                                                  //Clone a Linked List with next and random pointer - Optimal Approach
class Solution {
public:
    Node* copyRandomList(Node* head) {
    
        Node* iter=head;
        Node* front=head;
        
        //first step: make copy of each node & link them together side-by-side in single list
        
        while(iter!=NULL)
        {
            front=iter->next;
            Node* copy= new Node(iter->val);
            iter->next=copy;
            copy->next=front;
            iter=front;
        }
        
        //second step: assign random pinters for copy nodes
        
        iter=head;
        while(iter!=NULL)
        {
            if(iter->random!=NULL)
            {
                iter->next->random=iter->random->next;
               
            }
             iter=iter->next->next;
        }
        
        
        //third step : restore original list and extract the copy list
         iter=head;
        Node *pseudohead=new Node(0);
        Node *copy=pseudohead;
        
        while(iter!=NULL)
        {
            front=iter->next->next;
            
            //extract the copy
            copy->next=iter->next;
            
            //restore the original list
            iter->next=front;
            
            copy=copy->next;
            iter=iter->next;
        }
        
        return pseudohead->next;
        
    }
};
