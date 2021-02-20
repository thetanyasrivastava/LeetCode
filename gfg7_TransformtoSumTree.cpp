/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


// Convert a given tree to a tree where every node contains sum of values of
// nodes in left and right subtrees in the original tree
int sumTree(Node *node);
void toSumTree(Node *node)
{
    // Your code here
    sumTree(node);

}
int sumTree(Node *node)
{
     if(!node) return 0;
    int lSum=sumTree(node->left);
    int rSum=sumTree(node->right);
    int val=lSum+rSum+node->data;
    node->data=lSum+rSum;
    return val;
    
}
