//Sliding Window approach

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int wS=0,maxL=0;
        unordered_map<int,int> basket;
        
        for(int wE=0;wE<tree.size();wE++)
        {
            basket[tree[wE]]++;
            
            while(basket.size()>2)
            {
                basket[tree[wS]]--;
                if(basket[tree[wS]]==0)
                    basket.erase(tree[wS]);
                
                wS++;
            }
            maxL= max(maxL, wE-wS+1);
            
        }
        return maxL;
    }
};
