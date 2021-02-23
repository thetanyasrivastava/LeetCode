https://practice.geeksforgeeks.org/problems/leaves-to-dll/1



/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
// return the head of the DLL and remove those node from the tree as well.
Node * convert(Node* root,Node* &head,Node* &tail);
Node * convertToDLL(Node *root){
    // add code here.
    if(!root) return NULL;
    Node *head=NULL;
    Node *tail=NULL;
    convert(root,head,tail);
    return head;
}
Node * convert(Node* root,Node* &head,Node* &tail)
{
    if(!root) return NULL;
    
   if(!root->left && !root->right)
    {
        if(head==NULL)
        head=root;
    
    else
    {
        root->left=tail;
        tail->right=root;
    }
    
    tail=root;
    return NULL;
    }
    root->left=convert(root->left,head,tail);
    root->right=convert(root->right,head,tail);
    return root;
}
    
