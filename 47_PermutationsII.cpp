class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int len=nums.size();
        solve(0,len,nums,res);
        return res;
    }
    
    void solve(int pos,int len,vector<int> &nums,vector<vector<int>> &res)
    {
        if(pos==len-1)
        {
            if(s.find(nums)==s.end())
            {
                s.insert(nums);
                res.push_back(nums);
            }
            return;
        }
        
        for(int i=pos;i<len;i++)
        {
            swap(nums[pos],nums[i]);
            solve(pos+1,len,nums,res);
            swap(nums[pos],nums[i]);
        }
    }
};
