/* A binary tree node

struct Node                                   //Left View of Binary Tree
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


vector<int> leftView(Node *root)
{
   // Your code here
    vector<int> v;
    if(!root)
        return v;
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty())
   {
       int size=q.size();
       int count=0;
       while(size>0)
       {
           Node* temp = q.front();
            if(count==0)
                v.push_back(temp->data);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            
            q.pop();
            size--;
            count++;
       }
   }
   return v;
}
