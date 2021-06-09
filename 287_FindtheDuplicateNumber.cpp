class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       
        /*Method -1
        
        T.C. = O(nlogn)  S.C. = O(1)
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
                return nums[i];
        }
        return 0;*/
        
        /*
        MEthod -2
        
        T.C. = O(n)  S.C. = O(n)
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] >1)
                return nums[i];
        }
        return 0;*/
        
        //Method - 3
        
        //   T.C. = O(n)  S.C. = O(1)
        int slow=nums[0];
        int fast=nums[0];
        
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        while(slow!=fast);
        
        fast=nums[0];
        
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
        
    }
};
