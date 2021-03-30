/*A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return true if the given tree is a BST, else return false
class Solution
{
    public:
    bool isBST(Node* root) 
    {
        // Your code here
        return validate(root,INT_MIN,INT_MAX);
    }
    bool validate(Node* root,int l,int r)
    {
        if(!root) return true;
        if(root->data<l || root->data>r)
            return false;
        if(l>r) 
             return false;
    
        return ( validate(root->left,l,root->data-1) && validate(root->right,root->data+1,r) );
    }
    
};
