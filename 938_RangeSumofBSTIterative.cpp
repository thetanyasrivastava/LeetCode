int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* temp = s.top();
            s.pop();
            if(temp)
            {
                if(temp->val>=low && temp->val<=high)
                    sum+=temp->val;
                if(temp->val>low)
                    s.push(temp->left);
                if(temp->val< high)
                    s.push(temp->right);
            }
        }
        return sum;
  }

/* using queue
int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
           if(temp){
                if(temp->val>=low && temp->val<=high)
                    sum+=temp->val;
                if(temp->val>low)
                    q.push(temp->left);
                if(temp->val< high)
                    q.push(temp->right);
           }
        }
        return sum;
  }
  

*/
