/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
   // Your Code Here
   vector<int> res;
    if(!root)
        return res;
    
    map<int,int> m;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    
    while(!q.empty())
    {
        pair<Node*,int> p = q.front();
        q.pop();
        
        Node* temp=p.first;
        int hd=p.second;
        
        
        m[hd]=temp->data;
            
        if(temp->left)
            q.push({temp->left,hd-1});
        if(temp->right)
            q.push({temp->right,hd+1});
    }
    for(auto it:m)
    {
        res.push_back(it.second);
    }
    
    return res;
}
