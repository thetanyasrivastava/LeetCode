class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        
        for(int i=2;i<n;i++)    //starting from 2 cos each triangle must have 3 sides
        {
            int val=nums[i];    //longest side till now
            int start=0, end=i-1;
            
            while(start<end)    //check for pair of sides with sum more than val
            {
                if(nums[start] + nums[end] > val)
                {
                    ans+=end-start; // add all the sides between start and end
                    end--;          //decreament end to check upto start+1
                }
                else
                    start++;    //increament start to increase the sum
            }
        }
        return ans;
    }
};


/*Condition : For being a triangle, The Sum of any two sides must be greater than the third side. So we just need to find the two pairs which are greater than the longest side i.e., i.
    
Approach : We sort the array first. We consider nums[i] (starting from the index 2) as our third side and try to find all the pairs which have sum greater than it( only on the left side of i as all elements are smaller than i). This will give us all the possible triangle with nums[i] as the longest side.
    
 Here, we use Two pointers method to find all the pairs on the left side of it.
    
    if(nums[start]+nums[end]>nums[i])
        then we can add all the sided between end and start. Because it is sorted so definitely, nums[start+1], nums[start+2],..... nums[end-1] are all greater than nums[start] and all forms valid traingles with nums[end] and nums[i]. */

