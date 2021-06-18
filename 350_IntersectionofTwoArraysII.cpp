class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       /* MEthod -1 
       //T.C. = O(n) S.C.=O(n)
       unordered_map<int,int> m;
        vector<int> res;
        
        
        for(int i=0;i<nums1.size();i++)
            m[nums1[i]]++;
        
        for(int i=0;i<nums2.size();i++)
        {
           if(m[nums2[i]]>0)
           {
               m[nums2[i]]--;
               res.push_back(nums2[i]);
           }
        }
        
        
        return res;*/
        
        //Method -2 - Two pointers + sort 
        //T.C. = O(nlogn) S.C.=O(1)
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        while(i<n1 && j<n2)
        {
            if(nums1[i]==nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j])
                i++;
            else
                j++;
        }
        return res;
    }
};
