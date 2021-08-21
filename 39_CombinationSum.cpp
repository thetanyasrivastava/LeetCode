class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty())
            return res;
        
        vector<int> currcombi;
        int sum=0;          //sum and &sum works both
        solve(0,sum,target,currcombi,res,candidates);
        return res;
    }
    
    void solve(int i,int &sum,int target,vector<int> &currcombi,vector<vector<int>> &res,vector<int> &candidates)
       {
           if(sum==target)
           {
               res.push_back(currcombi);
               return;
           }

           if(i==candidates.size() || sum>target)
               return;
           
           sum+=candidates[i];
           currcombi.push_back(candidates[i]);
           solve(i,sum,target,currcombi,res,candidates);
           
           sum-=candidates[i];
           currcombi.pop_back();
           solve(i+1,sum,target,currcombi,res,candidates);
           
       }
};
