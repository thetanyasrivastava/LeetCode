class Solution {
public:
    int romanToInt(string s) {
        if(s.empty()) return 0;
        unordered_map<char,int> T ={{'I',1},
                                    {'V',5},
                                    {'X',10},
                                    {'L',50},
                                    {'C',100},
                                    {'D',500},
                                    {'M',1000}};
        int total=0;
        for(int i=0;i<s.length();i++)
        {
            int left = T[s[i]];
            int right = T[s[i+1]];
            if(right)
               {
                   if(left >= right )
                        total += left;
                   else
                   {
                       total += (right - left);
                       i++;
                   }
               }
            else
                total += left;
        }
        return total;
    }
};
