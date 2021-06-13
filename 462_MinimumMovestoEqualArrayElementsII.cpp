class Solution {
public:
    int minMoves2(vector<int>& nums) {
       //Time Complexity : O(N log N)
        /* 
        If we observe, once we sort the array,the minimum moves to make all array elements equal is by moving up, i.e. by increasing the number from left end and decreasing the element by right end until all the elements become equal.
        
        */
        /*
        //Method - 1//
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        int mid=(n-1)/2;
        for(int i=0;i<n;i++)
        {
            count += abs(nums[i]-nums[mid]);
        }
        return count;*/
        
        //Method-2
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0,right=n-1;
        int moves=0;
        
        while(left<right)
        {
            moves += abs(nums[right--] - nums[left++]);
        }
        return moves;
    }
};
