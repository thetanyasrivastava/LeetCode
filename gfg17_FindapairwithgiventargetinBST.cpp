/*Complete the function below
Node is as follows
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

class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
    if(!root) return 1;
    stack<Node*> s1,s2;
    pushElement(root,s1,true);
    pushElement(root,s2,false);
    
    while(!s1.empty() && !s2.empty() && s1.top()->data < s2.top()->data)
    {
        int x=s1.top()->data;
        int y=s2.top()->data;
        
        if(x+y==target) return 1;
        if(x+y<target)
        {
            Node* temp=s1.top();
            s1.pop();
            pushElement(temp->right,s1,true);
        }
        else
        {
            Node* temp=s2.top();
            s2.pop();
            pushElement(temp->left,s2,false);
        }
    }
    return 0;
    }
    
    void pushElement(Node* root,stack<Node*> &s,bool direction)
    {
        if(direction)
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }
        }
        else
        {
            while(root)
            {
                s.push(root);
                root=root->right;
            }
        }
    }
};
