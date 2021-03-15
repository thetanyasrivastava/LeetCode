/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        
        //if key found, 3 cases arises
        if(root->val==key)
        {
            if(!root->left && !root->right)     //Case I : 0 child
                return NULL;
            
            if(!root->right)                    //Case II : 1 child
                return root->left;
            if(!root->left)
                return root->right;
            
            if(root->left && root->right)       //Case III : 2 child
            {
                TreeNode* temp = findMax(root->left);
                root->val = temp->val;
                root->left = deleteNode(root->left,temp->val);
            }
            
        }
        
        //if key not found,then search in left and right subtree
        else if(root->val < key)
            root->right = deleteNode(root->right,key);
        else
            root->left = deleteNode(root->left,key);
        
    return root;
    }
    
    TreeNode* findMax(TreeNode* root)       //to find max in left subtree
    {                                       //we can also find min in right subtree 
        if(!root)return NULL;               //and change accordingly in both func
        while(root->right!=NULL)
        {
            root=root->right;
        }
        
        return root;
    }
};
