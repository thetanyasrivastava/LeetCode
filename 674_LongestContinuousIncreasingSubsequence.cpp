class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count=1;
        int max_count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1]) 
                count++;
            else
                count=1;
            max_count=max(max_count,count);
        }
        return max_count;
    }
};
