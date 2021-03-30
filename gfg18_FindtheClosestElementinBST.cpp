/*The Node structure is

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

// Return the minimum absolute difference between any tree node and the integer K
class Solution
{
    public:
    int minDiff(Node *root, int K)
    {
        //Your code here
        if(!root) return INT_MAX;
        
        if(root->data == K) return 0;
        
        if(K > root->data)
            return min((K - root->data), minDiff(root->right,K));
        
        return min((root->data - K), minDiff(root->left,K));
    }
};
