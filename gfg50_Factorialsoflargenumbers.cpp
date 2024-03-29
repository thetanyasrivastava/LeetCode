//https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> number;
        number.push_back(1);
        for(int i=2;i<=N;i++)
        {
            multiply(i,number);
        }
        
        reverse(number.begin(),number.end());
        return number;
     }
     
     void multiply(int n,vector<int> &number)
     {
         int carry=0;
         for(int i=0;i<number.size();i++)
         {
             int num=n*number[i];
             number[i]=(num+carry)%10;
             carry=(num+carry)/10;
         }
         while(carry)
         {
             number.push_back(carry%10);
             carry/=10;
         }
         
     }
};
