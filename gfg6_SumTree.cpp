/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
int sumTree(Node* root,bool &flag);

bool isSumTree(Node* root)
{
     // Your code here
     bool flag=true;
     sumTree(root,flag);
     return flag;
}
int sumTree(Node* root,bool &flag)
{
    if(!root) return 0;
    if(!root->left && !root->right)
        return root->data;
    
    int lSum=sumTree(root->left,flag);
    int rSum=sumTree(root->right,flag);
    
    if(root->data != (lSum+rSum))
        flag=false;
    
    return root->data + lSum + rSum;
}
