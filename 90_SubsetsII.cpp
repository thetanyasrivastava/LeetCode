class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        vector<int> op={};
        solve(nums,op,res);
       
        return res;
    }
    
    void solve(vector<int> nums,vector<int> &op,vector<vector<int>> &res){
        if(nums.size()==0)
        {
            //res.push_back(op);
            if(s.find(op) == s.end())
            {
                res.push_back(op);
                s.insert(op);   
            }    
            return;
        }
        
        vector<int> op1=op;
        vector<int> op2=op;
        
        op2.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        
        solve(nums,op1,res);
        solve(nums,op2,res);
    }
               
  
               
};
