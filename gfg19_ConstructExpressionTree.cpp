/*struct et
{
	char value;
	et* left, *right;
};*/

//function to construct expression tree
et* constructET(char postfix[],int &curr,int n);
et* constructTree(char postfix[])
{
//code here
    int n=strlen(postfix);
    if(n==0) return NULL;
    int curr=n-1;
    et* root = constructET(postfix,curr,n);
    
    return root;
}

et* constructET(char postfix[],int &curr,int n)
{
    if(curr<0)
        return NULL;
    et* root=new et(postfix[curr]);
    curr--;
    
    if((root->value=='+') || (root->value=='-') || (root->value=='*') || (root->value=='/') || (root->value=='^'))
    {
        root->right=constructET(postfix,curr,n);
        root->left=constructET(postfix,curr,n);
    }
    return root;
}
