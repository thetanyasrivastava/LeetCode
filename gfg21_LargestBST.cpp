/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST

struct bst{
    bool isBST;
    int size;
    int minm;
    int maxm;
};
bst largest(Node* root);
int largestBst(Node *root)
{
	//Your code here
	bst b= largest(root);
	return b.size;
}

bst largest(Node* root)
{
    if(!root)
    {
        bst b = {true,0,INT_MAX,INT_MIN};
        return b;
    }
    
    bst l = largest(root->left);
    bst r = largest(root->right);
    
    if(l.isBST && r.isBST && r.minm > root->data &&l.maxm < root->data )
    {
        bst b = {true, 1 + l.size + r.size, min(root->data,l.minm), max(root->data, r.maxm)};
        return b;
    }
    
    bst b = {false, max(l.size,r.size),-1,-1};
    return b;
    
}
