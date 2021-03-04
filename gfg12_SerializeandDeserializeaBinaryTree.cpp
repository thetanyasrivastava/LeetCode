/*A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/*this  function serializes 
the binary tree and stores 
it in the vector A*/


class Solution{

public:    

vector<int> serialize(Node *root) {
    //Your code here
    vector<int> v;
    if(!root)
        return v;
    serial(root,v);
    return v;
}

 void serial(Node* root, vector<int> &v)
    {
        if(root==NULL)
        {
            v.push_back(-1);
            return;
        }
        
        v.push_back(root->data);
        serial(root->left,v);
        serial(root->right,v);
        
    }
/*this function deserializes
 the serialized vector A*/
Node * deSerialize(vector<int> &A)
{
   //Your code here
   if(A.size()==0)
    return NULL;
    
   int curr=0;
   Node* root = deserial(A,curr);
   return root;
}

Node* deserial(vector<int> &A, int &curr)
{
    if(A[curr]==-1)
    {
        curr++;
        return NULL;
    }
    
    Node* root= new Node(A[curr]);
    curr++;
    root->left=deserial(A,curr);
    root->right=deserial(A,curr);
    
    return root;
}

};
