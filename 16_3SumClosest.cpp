class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int diff=INT_MAX;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            int lo=i+1, hi=n-1;
            
            while(lo<hi)
            {
                int sum=nums[i]+nums[lo]+nums[hi];
                if(abs(sum-target) < abs(diff))
                    diff=target-sum;
                
                if(sum<target)
                    lo++;
                else 
                    hi--;
                
           }
            if(diff==0)
                    break;
       }
        return target-diff;
    }
};
