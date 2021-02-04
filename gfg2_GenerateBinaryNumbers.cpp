/*
Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.
*/


#include<bits/stdc++.h>
using namespace std;
							//Function to print all binary numbers upto n
vector<string> generate(int N)
{
	
	vector<string> res;
	if(N==0)
	return res;
	queue<string> q;
	q.push("1");
	for(int i=0;i<N;i++)
	{
	    string curr = q.front();
	    q.pop();
	    res.push_back(curr);
	    q.push(curr + "0");
	    q.push(curr + "1");
	}
	return res;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>> n;
		vector<string> ans = generate(n);
		for(auto it:ans) 
			cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
