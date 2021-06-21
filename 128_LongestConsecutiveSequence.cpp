//GFG - https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*Method -1
        T.C. = O(nlogn) S.C. = O(1)
        
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        int res=1;
        int curr=1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1] + 1)
                curr++;
            else if( nums[i]==nums[i-1])
                //or curr=curr;
                continue;
            else
            {
                res=max(res,curr);
                curr=1;
            }
        }
        
        res=max(res,curr);
        return res;*/
        
      /* //Method - 2 Set(Hashing)
        //T.C. = O(n) S.C. = O(n)  
        int n=nums.size();
        if(n==0)
            return 0;
        unordered_set<int> s;
        int curr=1,res=1;
        for(int i=0;i<n;i++)
            s.insert(nums[i]);
        
        for(int i=0;i<n;i++)
        {
           // curr=1;
            if(s.find(nums[i]-1) == s.end())
            {
                curr=1;
                while(s.find(nums[i] + curr) != s.end())
                    curr++;
                res=max(res,curr);
            }
            
        }
        return res;*/
        
        //Method - 3 Priority Queue
        //T.C. = O(n) S.C. = O(n)  
        int min;    //store minm value of PQ
        int count=1; //count the no. of consecutive values
        int max_count=0; //store maxm no. of consecutive values
        
        priority_queue<int,vector<int>,greater<int>> minHeap(nums.begin(),nums.end());
            //initialising a min heap
        
        for(int i=0;i<nums.size();i++)
        {
            min=minHeap.top();  //storing the minm value of PQ
            minHeap.pop();       //deleting the minm value of PQ
                
            if(min+1 == minHeap.top())  //if new minm is 1+ previous min, inc. count
                count++;
            else if(min!=minHeap.top()) //if newminmis not same as prev min,restart count
                count=1;
            
            max_count=max(max_count,count);
        }
        return max_count;
        
    }
};
