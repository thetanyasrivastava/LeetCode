class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        
       /* Method-2
       unordered_map<int,int> m;           //ordered map too can be used
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto x: m)
        {
            if(x.second >=2)
                return true;
        }
        return false;*/
        
    
        /* Method-1
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;*/
        
        //Method-3
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i]) == m.end())      //element not found, so element inserted
                m[nums[i]]++;
            else                                //element found and hence more than two
                return true;
        }
        return false;
    }
};
