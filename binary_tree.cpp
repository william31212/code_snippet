#include <bits/stdc++.h>

using namespace std;

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* rootPtr;//to store address of root node

BstNode* GetNewNode(int data)
{
	BstNode* newNode = new BstNode();
	newNode->data = data;// to store data
	newNode->left = newNode->right = NULL;//left & right is empty
	return newNode;
}

BstNode* Insert(BstNode *root,int data)//void寫法: 原本傳pointer進去就要一個*,因此再傳pointer的address還要多一個*
{
	if (root == NULL)//void寫法: rootPtr is empty,so get a new node
	{
		root = GetNewNode(data);
		return root;
	}
	else if (data <= root->data)
	{
		root->left = Insert(root->left,data);
	}
	else
	{
		root->right = Insert(root->right,data);
	}

	return root;
}

BstNode* dfs(BstNode *root)
{
	if (root == NULL)
	{
		return root;
	} 
	else 
	{
		cout << root->data;
		dfs(root->left);
		dfs(root->right);
	}
	
	
}

bool search(BstNode* root,int data)
{
	if (root == NULL)
		return false;
	else if (root->data == data)
		return true;
	else if (data <= root->data)
		return search(root->left,data);
	else
		return search(root->right,data);
}



int main()
{
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif


	BstNode* root_main = NULL;
	root_main = Insert(root_main,15);//return pointer store in root
	root_main = Insert(root_main,10);
	root_main = Insert(root_main,20);
	root_main = Insert(root_main,25);
	root_main = Insert(root_main,8);
	root_main = Insert(root_main,12);
	int number;
	
	dfs(root_main);

	
	return 0;

}