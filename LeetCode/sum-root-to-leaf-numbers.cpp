#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 



struct TreeNode* newNode(int data)
{
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = node->right = NULL;
    return node;
}
 
void pathPrint(int number,TreeNode *root,vector<int> & allNumbers)
{
	if(root==NULL)
	{
		return;
	}
	
	if(root->left==NULL && root->right==NULL)
	{
		number*=10;
		number+=root->val;
		allNumbers.push_back(number);
		return;
	}	
	pathPrint(number*10+root->val,root->left,allNumbers);
	pathPrint(number*10+root->val,root->right,allNumbers);
	
}
int sumNumbers(TreeNode *root) 
{
	vector<int> allNumbers;
	int sum=0;
	if(!root)
		return 0;

	if(!root->left && !root->right)
		return root->val;

	if(root ->left)
		pathPrint(root->val,root->left,allNumbers);
	if(root->right)
		pathPrint(root->val,root->right,allNumbers);
	
	for(vector<int>::iterator it=allNumbers.begin();it!=allNumbers.end();it++)
	{
		sum+=*it;
		//cout<<*it<<"\t";
	}
	//cout<<endl;
	return sum;
}

int main()
{
    TreeNode* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
	printf("%d\n",sumNumbers(root));
	return 0;
}
