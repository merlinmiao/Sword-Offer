//镜像打印一棵树

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

//镜像倒置一棵树
void MirrorTree(binary_tree_node * &tree){
	if (tree == NULL) {
		return;
	}
	if (tree->left_child == NULL && tree->right_child == NULL) {
		return;
	}
	binary_tree_node * pTemp = tree->left_child;
	tree->left_child = tree->right_child;
	tree->right_child = pTemp;
	if (tree->left_child) {
		MirrorTree(tree->left_child);
	}
	if (tree->right_child) {
		MirrorTree(tree->right_child);
	}
}


int main() {
	int a[]={8,6,10,5,7,9,11};
	int len= sizeof(a)/sizeof(int);
	binary_tree_node * tree;
	createTree(tree,a,0,len);
	PrePrint(tree,0);
	cout<<endl;
	MirrorTree(tree);
	PrePrint(tree,0);
	return 0;
}