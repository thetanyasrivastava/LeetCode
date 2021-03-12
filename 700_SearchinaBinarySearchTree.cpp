//Method - 1 
/* TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return NULL;
        
        //create a node to return
        TreeNode* curr = new TreeNode();
        
        //if root->val!=root,search in left and right subtree
        //otherwise this would be the required node and we would return it
        if(val < root->val)
            curr = searchBST(root->left,val);
        else if(val > root->val)
            curr = searchBST(root->right,val);
        else
            curr = root;
        
        return curr;
        }
        */
        
        
//Method - 2
/* TreeNode* searchBST(TreeNode* root, int val) {
 while(root!=NULL && root->val!=val)
        {
            root=(root->val>val)?root->left:root->right;
        }
        
        return root;
    
    }
    */
    
//Method - 3
/* TreeNode* searchBST(TreeNode* root, int val) {  
   if(!root || root->val==val)
            return root;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                TreeNode* curr= q.front();q.pop();
                if(curr->val==val)
                    return curr;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        return NULL;
       
    }
    */
