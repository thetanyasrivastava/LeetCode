class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        
       
        int c=candies.size();
        unordered_set <int> s;
        for(int i=0;i<c;i++)
            s.insert(candies[i]);
        
        int d=s.size();
      
        if(d>=c/2)
            return c/2;
        else
            return d;
    }
    
};
