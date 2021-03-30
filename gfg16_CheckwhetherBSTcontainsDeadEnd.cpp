/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
void check(Node* root,int l,int r,bool &flag);
bool isDeadEnd(Node *root)
{
    //Your code here
    bool flag=false;
    check(root,INT_MIN,INT_MAX,flag);
    return flag;
}
void check(Node* root,int l,int r,bool &flag)
{
    if(!root) return;
    if(flag) return;
    
    if((!root->left) && (!root->right))
    {
        if(l==r || r==1)
        {
            flag = true;
            return;
        }
    }
    
    check(root->left,l,root->data-1,flag);
    check(root->right,root->data+1,r,flag);
}
