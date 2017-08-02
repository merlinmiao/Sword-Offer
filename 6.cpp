//给出前序遍历序列{1,2,4,7,3,5,6,8}
//中序遍历序列{4,7,2,1,5,3,8,6}
//重建二叉树

#include <iostream>  
  
using namespace std;  
  
//定义树的结点
struct binary_tree_node  
{  
	int data;  
	binary_tree_node* left_child;  
	binary_tree_node* right_child;  
};  
  
//创建一棵树
void create_tree(binary_tree_node * &tree, int a[], int len, int index)  
{  
	if (index >= len)  
		return;  
	tree = new binary_tree_node();  
	tree->data = a[index];  
	tree->left_child = NULL;  
	tree->right_child = NULL;  
	create_tree(tree->left_child, a, len, 2 * index + 1);  
	create_tree(tree->right_child, a, len, 2 * index + 2);  
}  
  
//前序遍历打印一棵树
void PrePrint(binary_tree_node *p,int i)  
{  
	if (p == NULL )  
		return;  
	//控制输出
	if(i==0){
		cout << p->data ; 
	} else {
		cout << ','<< p->data ; 
	}
	i++;
	PrePrint(p->left_child,i);  
	PrePrint(p->right_child,i);  
}  

//中序遍历打印一颗树
void MidPrint(binary_tree_node *p)  
{  
	if (p == NULL )  
		return;  
	//控制输出
	MidPrint(p->left_child);  
	cout << p->data << ' '; 
	MidPrint(p->right_child);  
} 

//后序遍历打印一颗树
void HouPrint(binary_tree_node *p)  
{  
	if (p == NULL )  
		return;  
	//控制输出
	HouPrint(p->left_child);
	HouPrint(p->right_child);    
	cout << p->data << ' '; 
}  
 



//分别对前序遍历和中序遍历收尾使用指针进行遍历
binary_tree_node * ConstructCore(int *startPre,int *endPre,int *startMid,int *endMid){
//	前序遍历的第一个数为树的根节点
//	创建树的根节点
	binary_tree_node *tree = new binary_tree_node();
	int treeValue=startPre[0];
	tree->data=treeValue;
	tree->left_child = NULL;  
	tree->right_child = NULL;  
	
	//树构建完成条件
	if(startPre  == endPre){
		if(startMid == endMid && *startPre == *startMid){
			return tree;
		}else{
			cout<<"Invalid input!"<<endl;
			return NULL;
		}
	}
//	在中序遍历中找根节点
	int *rootMid = startMid;
	while(rootMid<=endMid && *rootMid !=treeValue){
		++rootMid;
	}
	//鲁棒性验证,前序遍历与中序遍历无法匹配
	if(rootMid==endMid && *rootMid !=treeValue){
		cout<<"Invalid input!"<<endl;
		return NULL;
	}
	
	int leftTreeLength = rootMid - startMid;
	if (leftTreeLength>0) {
//		构建左子树
		tree->left_child = ConstructCore(startPre+1, startPre+leftTreeLength, startMid, rootMid-1);
	}
	//判断条件表示当左子树的长度小于前序遍历除首节点外的元素长度时，表明还有右子树
	if (leftTreeLength<endPre-startPre) {
	//		构建右子树
		tree->right_child = ConstructCore(startPre+leftTreeLength+1, endPre, rootMid+1,endMid);
	}
	return tree;
	
}

binary_tree_node * Construct(int *Pre,int*Mid,int length){
	if(Pre == NULL || Mid == NULL || length <=0){
		return NULL;
	}
	return ConstructCore(Pre, Pre+length-1,Mid,Mid+length-1 );
}
  
int main()  
{  
//	int p[7] = { 0, 1, 2, 3, 4, 5, 6 };  
	binary_tree_node *tree;  
//	create_tree(tree, p, 7, 0);  
	int a[]={1,2,4,7,3,5,6,8};
	int b[]={4,7,2,1,5,3,8,6};
	int length=sizeof(a)/sizeof(int);
	tree=Construct(a,b,length);
	PrePrint(tree,0);
	cout<<endl;
	MidPrint(tree); 
	cout<<endl;
	HouPrint(tree);   
	return 0;  
}  