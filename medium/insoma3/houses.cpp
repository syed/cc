#include<iostream>
#include<vector>

using namespace std;
//int vals[100000];

typedef struct  TreeStruct {
	int data ;
	int count ;
	struct TreeStruct *left,*right;
} Tree;

Tree * create_node ( int data )
{
	Tree *node = new Tree();
	node->left=NULL;
	node->right=NULL;
	node->count=0;
	node->data=data;
	return node;
}

void update_count(Tree *root)
{
	if(root==NULL)
		return;
	else
	{
		root->count++;
		update_count(root->left);
		update_count(root->right);
	}
}

void tree_insert(Tree *root ,int  num )
{

	//cout<<"got "<<num<<endl;
	if( root->data<num) //right tree
	{
	//	cout<<"going right"<<endl;
		if(root->right==NULL)
		{
			root->right=create_node(num);
			return;
		}
		else
		{
			tree_insert(root->right,num);
		}
	}
	else
	{
		//cout<<"going left"<<endl;
		if(root->left==NULL)
		{
			root->left=create_node(num);
			root->count++;
			update_count(root->right);
			return;
		}
		else
		{
			root->count++;
			update_count(root->right);
			tree_insert(root->left,num);
		}
	}
	return ;
}

int getCount(Tree* root)
{
	if(root==NULL)
		return 0;

	int count ;

	count=root->count;
	count+=getCount(root->left);
	count+=getCount(root->right);
	return count;
}


int main()
{
	int n,num ;
	Tree *root ;
	
	cin>>num;
	cin>>n;
	root = create_node(n);//fist element 
	num--;

	while(num--)
	{
		int val;
		cin>>val;
		tree_insert(root,val);
	}
	cout<<getCount(root)<<endl;
}

