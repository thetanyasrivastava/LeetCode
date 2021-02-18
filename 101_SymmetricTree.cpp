//Recursive

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       if(!root) return true;
        return mirror(root->left , root->right);
    }
    
    bool mirror(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        if(root1->val != root2->val) return false;
        
        return mirror(root1->left, root2->right) &&
            mirror(root1->right, root2->left);
                  
    }
    
};

//Iterative

bool isSymmetric(TreeNode* root)
    {
        if(!root)return true;
        if(!root->left && !root->right) return true;
        
        queue<TreeNode*>q;
        q.push(root);
        
        if(root->left && root->right)
        {
            q.push(root->left);
            q.push(root->right);
            q.pop();
        }
        else if(root->left || root->right)
            return false;
        
        while(!q.empty())
        {
            TreeNode* leftNode = q.front(); q.pop();
            TreeNode* rightNode = q.front(); q.pop();
            
            if(leftNode->val != rightNode->val)
                return false;
            
            
            if(leftNode->left && rightNode->right)
            {
                q.push(leftNode->left);
                q.push(rightNode->right);
            }
            else if(leftNode->left || rightNode->right)
                return false;
            
            
             if(leftNode->right && rightNode->left)
            {
                q.push(leftNode->right);
                q.push(rightNode->left);
            }
            else if(leftNode->right || rightNode->left)
                return false;
        }
        return true;
    }
    

