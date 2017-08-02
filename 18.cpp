//输入两颗二叉树，A,B，判断B 是否是 A 的子树

#include <iostream>

using namespace std;
//定义树的结点
struct binary_tree_node  
{  
	int data;  
	binary_tree_node* left_child;  
	binary_tree_node* right_child;  
}; 

//遍历子树代码
bool DoesTree1HasTree2(binary_tree_node *Tree1,binary_tree_node *Tree2){
//	树 B 为空，必为 A 的子树，所以返回 true,同时也是递归终点
	if (Tree2 == NULL ) {
		return true;
	}
	if(Tree1 == NULL){
		return false;
	}
	if (Tree1->data != Tree2->data) {
		return false;
	}
	return DoesTree1HasTree2(Tree1->left_child,Tree2->left_child) && DoesTree1HasTree2(Tree1->right_child,Tree2->right_child)
}

//代码
bool HasSubtree(binary_tree_node *Tree1,binary_tree_node *Tree2){
	bool result = false;
	if (Tree1 != NULL && Tree2 != NULL) {
		//正好 A 的根结点和 B 的根节点值相等
		if(Tree1->data == Tree2->data){
			//继续判断他们的子结点是否相等
			result = DoesTree1HasTree2(Tree1,Tree2);
		}
		//不相等，那么就遍历 A 的左右子树，都要遍历，不能遗忘一个
		if (!result) {
			result = HasSubtree(Tree1->left_child,Tree2);
		}
		if (!result) {
			result = HasSubtree(Tree1->right_child,Tree2);
		}
	}
	return result;
}

int main(int argc, char *argv[]) {
	
}