class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        /*vector<int> res;
        unordered_set<int> s;
        int n1=nums1.size(); int n2=nums2.size();
        for(int i=0;i<n1;i++)
            s.insert(nums1[i]);
        
        for(int i=0;i<n2;i++)
        {
            if(s.find(nums2[i])!=s.end())
            {
                res.push_back(nums2[i]);
                s.erase(nums2[i]);  //to avoid duplicates-erasing a no. used from the set
                                    //or vector<bool> vis of all no.s
            }
        }
        return res;*/
        
       vector<int> res;
        unordered_set<int> s;
        
        int n1=nums1.size(); 
        int n2=nums2.size();
        
         vector<bool> vis(1000,false);
        
        for(int i=0;i<n1;i++)
            s.insert(nums1[i]);
            //s[nums1[i]]++;
        
        for(int i=0;i<n2;i++)
        {
            if(s.find(nums2[i])!=s.end() && !vis[nums2[i]])
            {
                res.push_back(nums2[i]);
                vis[nums2[i]]=true;

            }
        }
        return res;
    }
      
      
};
