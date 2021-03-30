class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if(n==0) return ans;
        
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
            m[nums[i]]++;
        
        for(auto it:m)
        {
            if(it.second>1)
                ans.push_back(it.first);    
        }
        return ans;
    }
};
