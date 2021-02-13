class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(!root)
            return v;
        queue<TreeNode*> q;
        q.push(root);
       
        while(!q.empty())
        {
            int size=q.size();     //to identify the level of the corresponding queue
            int count=0;
            
            while(size>0)
            {
                TreeNode* temp=q.front();
                     
                if(count==0)                     // to identify first element
                    v.push_back(temp->val);
                
                if(temp->right)
                    q.push(temp->right);
                if(temp->left)
                    q.push(temp->left);
                
                size--;
                q.pop();
                count++;
            }
        }
        return v;
  }
};


//c++
//bfs
//queue
//level-order-traversal
