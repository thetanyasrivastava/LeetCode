class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        if(nums.size()==0)
            return ans;
        
        int a=0,b=0;
        long res=0;
        for(int i=0;i<nums.size();i++)
        {
            res ^= nums[i];
        }
        
       res = res & ~(res-1);
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] & res)
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        ans.push_back(a);
        ans.push_back(b);
        
        return ans;
    }
};
