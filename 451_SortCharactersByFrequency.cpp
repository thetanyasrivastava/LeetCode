class Solution {
public:
    string frequencySort(string s) {
        string s2;
        if(s.length()==0)
            return s2;
        
        priority_queue<pair<int,int>> maxH;
        unordered_map<char,int> mp;
        
        for(int i=0;s[i]!='\0';i++)
        {
            mp[s[i]]++;
        }
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            maxH.push({it->second, it->first});
        }
        
        while(!maxH.empty())
        {
            int freq=maxH.top().first;
            while(freq>0)
            {
               freq--;
              s2.push_back(maxH.top().second);
            }
            
            maxH.pop();
        }
        return s2;
    }
};
