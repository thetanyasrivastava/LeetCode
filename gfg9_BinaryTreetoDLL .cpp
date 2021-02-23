/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
void convert(Node* root,Node* &head,Node* &tail);
Node * bToDLL(Node *root)
{
    // your code here
    if(!root) return NULL;
    Node *head=NULL;
    Node *tail=NULL;
    convert(root,head,tail);
    return head;
}
void convert(Node* root,Node* &head,Node* &tail)
{
    if(!root) return;
    convert(root->left,head,tail);
    if(head==NULL)
        head=root;
    
    else
    {
        root->left=tail;
        tail->right=root;
    }
    
    tail=root;
    
    convert(root->right,head,tail);
    
}
