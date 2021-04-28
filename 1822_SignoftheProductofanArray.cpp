class Solution {
public:
    int arraySign(vector<int>& nums) {
        /*
        //Method -1
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                return 0;
            if(nums[i]>0)
                nums[i]=1;
            else if(nums[i]<0)
                nums[i]=-1;
        }
        int product=1;
        for(int i=0;i<n;i++)
        {
            product *= nums[i];
        }
        return product;
        */
        
        //Method-2
        int count_neg=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                return 0;
            
            if(nums[i]<0)
                count_neg++;
        }
        
        if(count_neg % 2 == 0)
            return 1;
        
        return -1;
        
    }
};
