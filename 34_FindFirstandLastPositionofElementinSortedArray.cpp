class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       
        int index1=BS(nums,target,true);
        int index2=BS(nums,target,false);
        vector<int> ans;
        ans.push_back(index1);
        ans.push_back(index2);
        return ans;
        
    }
    int BS(vector<int>&nums, int target, bool order)
    {
         int low=0, high=nums.size()-1;
        int res = -1;
        int mid;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            if(target==nums[mid])
            {
                res=mid;
                if(order)
                    high=mid-1;
                else
                    low=mid+1;
            }
            /*if(target==nums[mid] && order==true )
            {
                res = mid;
                high = mid-1;
            }
            else if(target==nums[mid] && order==false)
            {
                res = mid;
                low=mid+1;
            }*/
            else if(target<nums[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        
        return res;
        
    }
    
    /*
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=BS(nums,target,true);
        int j=BS(nums,target,false);
        vector<int> res;
        res.push_back(i);
        res.push_back(j);
        return res;
    }
    int BS(vector<int>& nums,int target,bool order)
    {
        int low=0;
        int high=nums.size()-1;
        
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(target==nums[mid])
            {
                ans=mid;
                if(order)
                    high=mid-1;
                else
                    low=mid+1;
            }
            else if(target<nums[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        return ans;
        
    }
    
};
    */
};
