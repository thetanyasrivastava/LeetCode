https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1



/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/
 Node* lca(Node* root, int a,int b);
 int Dis(Node* root,int var,int d);
 
int findDist(Node* root, int a, int b) {
    // Your code here
    if(!root) return 0;
    Node* LCA = lca(root,a,b);
    if(!LCA) return 0;
    int dis=Dis(LCA,a,0)+Dis(LCA,b,0);
    return dis;
}
Node* lca(Node* root,int a,int b)
{
    if(!root || root->data==a || root->data==b) return root;
    Node *l = lca(root->left,a,b);
    Node *r = lca(root->right,a,b);
    
    if(l&&r) return root;
    if(l) return l;
    if(r) return r;
    
    return NULL;
}

int Dis(Node *root,int var,int d)
{
    if(!root) return 0;
    if(root->data == var) return d;
    
    int l = Dis(root->left,var,d+1);
    if(l==0)
        return Dis(root->right,var,d+1);
    
    return l;
}
