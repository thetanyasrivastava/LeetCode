/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

// The given root is the root of the Binary Tree
// Return the root of the generated BST
void inorderTraversal(Node *root,vector<int> &v);
void convertBST(Node* root,vector<int> &v,int &i);
Node *binaryTreeToBST (Node *root)
{
    //Your code goes here
    vector<int> v;
    int i=0;
    inorderTraversal(root,v);
    sort(v.begin(),v.end());
    convertBST(root,v,i);
    
    return root;
}
void inorderTraversal(Node *root,vector<int> &v)
{
    if(!root) return;
    inorderTraversal(root->left,v);
    v.push_back(root->data);
    inorderTraversal(root->right,v);
}
void convertBST(Node* root,vector<int> &v,int &i)
{
    if(!root) return;
    convertBST(root->left,v,i);
    root->data = v[i++];
    convertBST(root->right,v,i);
    
}
