class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int wS=0,sum=0;
        int minS=INT_MAX;
        
        for(int wE=0;wE<nums.size();wE++)
        {
            sum+=nums[wE];
            while(sum>=s)
            {
                minS=min(minS,wE-wS+1);
                sum-=nums[wS];
                wS++;
            }
        }
        return minS==INT_MAX?0:minS;
    }
};
