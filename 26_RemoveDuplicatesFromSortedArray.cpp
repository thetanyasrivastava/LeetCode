class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int nextNonDuplicate = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[nextNonDuplicate]!=nums[i])
            {
                nextNonDuplicate++;
                nums[nextNonDuplicate]=nums[i];
            }
        }
        return nextNonDuplicate+1;
}
};
