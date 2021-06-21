//GFG - https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      /*  int count=0;
        int element=0;
        
        for(int num : nums)
        {
            if(count==0)
                element=num;
            
            if(num==element)
                count += 1;
            else
                count -= 1;
        }
        
        return element;*/
        
        //Method - 4 T.C. = O(n)  S.C. = O(1)
        int count=0;
        int element=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
                element=nums[i];
            if(element==nums[i])
                count+=1;
            else
                count-=1;
        }
        return element;
    }
};
