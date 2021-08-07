class Solution {
public:
    //Method -1 Recursion
    //T.C. = (n * (2^n)) S.C. = (n * (2^n))
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        
        vector<int> op={};
        solve(nums,op,res);
        
        return res;
    }
    
    void solve(vector<int> nums, vector<int> &op,vector<vector<int>> &res)
    {
         if(nums.size()==0)
         {
             res.push_back(op);
             return;
         }
            
        vector<int> op1=op;
        vector<int> op2=op;
        
        op2.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        //nums.erase(nums.begin());
        
        solve(nums,op1,res);
        solve(nums,op2,res);
    }
    
     /*//Method - 2 Iterative
    //T.C. = (n * (2^n)) S.C. = (n * (2^n))
    vector<vector<int>> subsets(vector<int>& nums) {
    
        int n=nums.size();
        vector<vector<int>> res;
        res.push_back({});
        
        for(int i=0;i<n;i++)
        {
            int sz=res.size();
            for(int j=0;j<sz;j++)
            {
                vector<int> temp=res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        
        return res;
    }*/
        
};
