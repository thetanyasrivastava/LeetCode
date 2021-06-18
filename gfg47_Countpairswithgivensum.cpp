https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            /*//MEthod -1 
            vector<int> res;
            unordered_map<int,int> m1,m2,m3;
            for(int i=0;i<n1;i++) m1[A[i]]++;
            for(int i=0;i<n2;i++) m2[B[i]]++;
            for(int i=0;i<n3;i++) m3[C[i]]++;
            
            for(int i=0;i<n1;i++)
            {
                if(m1[A[i]] && m2[A[i]] && m3[A[i]])
                {
                    res.push_back(A[i]);
                    m1[A[i]]=0;
                }
            }
            return res;*/
            
            //Method- 2 (Two Pointers)
            vector<int> ans;
            int i=0,j=0,k=0;
            while(i<n1 && j<n2 && k<n3)
            {
                if(A[i]==B[j] && B[j]==C[k]){
                    ans.push_back(A[i]);
                    i++; j++; k++;
                }
                else if(A[i]<B[j])
                    i++;
                else if(B[j]<C[k])
                    j++;
                else
                    k++;
                int x=A[i-1];
                while(A[i]==x) i++;
                
                int y=B[j-1];
                while(B[j]==y) j++;
                
                int z=C[k-1];
                while(C[k]==z) k++;
                
            }
            return ans;
        }

};
