class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*METHOD - 1 (Reverse Sorting)
        
        int i = m-1, j = n-1, k = m+n-1;
        while(i>=0 &&j >=0)
        {
            if(nums1[i]>nums2[j])
                nums1[k--]=nums1[i--];
            else
                nums1[k--]=nums2[j--];
        }
        while(i>=0)
            nums1[k--] = nums1[i--];
        while(j>=0)
            nums1[k--] = nums2[j--];
    }*/
        
        //Method - 2
       vector<int> ans;
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }
            
            while(i<m)
            {
                ans.push_back(nums1[i++]);
            }
            while(j<n)
            {
                ans.push_back(nums2[j++]);
            }
            
            for(int k=0;k<m+n;k++)
                nums1[k]=ans[k];
        
    }
};
