class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cmax=nums[0];
        int cmin=nums[0];
        int pmax=nums[0];
        int pmin=nums[0];
        int ans=nums[0];
        int maxi=nums[0];
        int minm=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            maxi = max ( pmax*nums[i], pmin*nums[i] );
            minm = min ( pmax*nums[i], pmin*nums[i] );
            
            cmax = max ( maxi , nums[i] );
            cmin = min ( minm , nums[i] );
            ans = max ( ans , cmax );
            pmax = cmax;
            pmin = cmin;
        }
        return ans;
    }
};
