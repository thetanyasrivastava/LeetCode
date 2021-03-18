/*

The structure of a BST node is as follows:

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
void countNodes(Node* root,int l,int h, int &count);
int getCount(Node *root, int l, int h)
{
  // your code goes here  
  int count = 0;
  countNodes(root,l,h,count);
  return count;
}
void countNodes(Node* root,int l,int h, int &count)
{
    if(!root)
        return;
    
    if(root->data >=l && root->data <=h)
        count++;
    
    if(root->data > l)
        countNodes(root->left,l,h,count);
    
    if(root->data < h)
        countNodes(root->right,l,h,count);
}
