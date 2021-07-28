class Solution {
public:
    string intToRoman(int num) {
      vector<pair<int,string>> v={{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},
                                    {50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},                                               {900,"CM"},{1000,"M"}};
        
        string res="";
        for(auto it=v.rbegin();  it!=v.rend() && num!=0;  it++)
        {
                //get the frequency of symbols required starting from the largest & going to                    //the least
            
            int freq=num/it->first;
            num=num%it->first;
            
            //update num for the next iteration so that we can get the freq. of second                      //highest symbol & so on
            
            while(freq)
            {
                //res.append(it->second);
                res+=it->second;       //append the symbol as many times as freq. and dec. it
                freq--;                 
            }
        }
        return res;     //return the result obtained
    }
};
