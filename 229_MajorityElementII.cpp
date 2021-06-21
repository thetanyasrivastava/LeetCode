//GFG - https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       /* int sz=nums.size();
        int num1=-1, num2=-1, count1=0, count2=0, i;
        
        for(i=0;i<sz;i++)
        {
            if(nums[i]==num1)
                count1++;
            else if(nums[i]==num2)
                count2++;
            else if(count1==0)
            {
                num1=nums[i];
                count1++;
            }
            
            else if(count2==0)
            {
                num2=nums[i];
                count2++;
            }
            
            else
            {
                count1--;
                count2--;
            }
        }
        
        vector<int> ans;
        count1=0, count2=0;
        
        for(i=0;i<sz;i++)
        {
            if(nums[i]==num1)
                count1++;
            
            else if(nums[i]==num2)
                count2++;
        }
        
        if(count1>(sz/3))
            ans.push_back(num1);
        
        if(count2>(sz/3))
            ans.push_back(num2);
        
        return ans;*/
        
        
        
        //Method -3
        //T.C. = O(n)+O(n) =O(n) S.C. = O(1)
        int num1=-1,num2=-1,c1=0,c2=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==num1)
                c1++;
            else if(nums[i]==num2)
                c2++;
            else if(c1==0)
            {
                num1=nums[i];
                c1++;
            }
            else if(c2==0)
            {
                num2=nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        //for verification if num1 and num2 exist more than n/3 times
        
        vector<int> res;
        c1=0,c2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==num1)
                c1++;
            else if(nums[i]==num2)
                c2++;
        }
        
        if(c1>(n/3))
            res.push_back(num1);
        if(c2>(n/3))
            res.push_back(num2);
        
        return res;
    }
};
