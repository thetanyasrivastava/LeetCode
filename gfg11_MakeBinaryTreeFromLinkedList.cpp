/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

/*You are required to complete this method*/
TreeNode* getNewNode(int x);
void convert(Node *head, TreeNode *&root) {
    
    // Your code here
    vector<TreeNode*> v;
    Node *temp=head;
    while(temp!=NULL)
    {
        TreeNode* curr = getNewNode(temp->data);
        v.push_back(curr);
        temp=temp->next;
    }
    
    int n=v.size();
    for(int i=0;i<n/2;i++)
    {
        if((2*i+1) < n)
            v[i]->left = v[2*i+1];
        
        if((2*i+2) < n)
            v[i]->right = v[2*i+2];
    }
    root=v[0];
}

TreeNode* getNewNode(int x)
{
    TreeNode* node=new TreeNode(x);
    
    node->left=NULL;
    node->right=NULL;
    
    return node;
}
