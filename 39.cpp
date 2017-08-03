//求二叉树的深度
//深度，即从根节点到最后一个叶节点形成的最长的一条路径的深度

#include <iostream>

using namespace std;

struct binary_tree_node{
	int data;
	binary_tree_node * left_child;
	binary_tree_node * right_child;	
};

//创建一颗树
void createTree(binary_tree_node * &tree,int a[],int i,int len){
	if(i>=len){
		return;
	}
	tree = new binary_tree_node();
	tree->data=a[i];
	tree->left_child = tree->right_child = NULL;
	createTree(tree->left_child,a,2*i+1,len);
	createTree(tree->right_child,a,2*i+2,len);	
}

//打印一颗树
void PrePrint(binary_tree_node * tree,int i){
	if (tree == NULL) {
		return;
	}
	//控制输出
	if(i==0){
		cout << tree->data ; 
	} else {
		cout << ','<< tree->data ; 
	}
	i++;
	PrePrint(tree->left_child,i);  
	PrePrint(tree->right_child,i); 
}

//判断二叉树的深度
int TreeDepth(binary_tree_node * tree){
	//递归结束条件，也是鲁棒性条件
	if (tree == NULL) {
		return 0;
	}
	int nLeft = TreeDepth(tree->left_child);
	cout<<'L'<<nLeft<<endl;
	int nRight = TreeDepth(tree->right_child);
	cout<<'R'<<nRight<<endl;
	return (nLeft > nRight) ? (nLeft+1) : (nRight+1);
}

//判断平衡二叉树

int main() {
	int a[]={8,6,10,5,7,9,11,3,2};
	int len= sizeof(a)/sizeof(int);
	binary_tree_node * tree;
	createTree(tree,a,0,len);
	PrePrint(tree,0);
	cout<<endl;
	cout<<TreeDepth(tree);
	return 0;
}