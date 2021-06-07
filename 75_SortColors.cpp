//T.C. = O(N)
//S.C. = O(1)


class Solution {
public:
    /*void sortColors(vector<int>& nums) {
        int lo=0;
        int mid=0;
        int hi=nums.size()-1;
        int temp;
        
        while(mid<=hi)
        {   
            if(nums[mid]==0)
            {             //if the element is 0
                    temp=nums[lo];
                    nums[lo]=nums[mid];
                    nums[mid]=temp;
                    lo++;
                    mid++;
                
            }
            else if(nums[mid]==1)
            {
                mid++;            //if the element is 1
            }
           else if(nums[mid]==2)
            {                                 //if the element is 2
                    temp=nums[mid];           
                    nums[mid]=nums[hi];
                    nums[hi]=temp;
                    hi--;
            }
        }
     }*/
    
    void sortColors(vector<int>& nums) {
        
        int lo=0,mid=0,hi=nums.size()-1;
        
        while(mid<=hi)
        {
            if(nums[mid]==0)
                swap(nums[lo++],nums[mid++]);
            else if(nums[mid]==1)
                mid++;
            else
                swap(nums[mid],nums[hi--]);
        }
    }
};
