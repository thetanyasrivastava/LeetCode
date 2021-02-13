//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
vector<int> topView(struct Node *root)
{
    //Your code here
    vector<int> res;
    if(!root)
        return res;
    
    map<int,int> m;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    
    while(!q.empty())
    {
        pair<Node*,int> p = q.front();
        q.pop();
        
        Node* temp=p.first;
        int hd=p.second;
        
        if(m.find(hd)==m.end())
            m[hd]=temp->data;
            
        if(temp->left)
            q.push(make_pair(temp->left,hd-1));
        if(temp->right)
            q.push(make_pair(temp->right,hd+1));
    }
    for(auto it:m)
    {
        res.push_back(it.second);
    }
    
    return res;
}
