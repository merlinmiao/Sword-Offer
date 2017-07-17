//在 O(1)时间内删除链表结点
//给定头结点和当前要删除的结点
//思路：按往常的方式，需要从头遍历至要删除结点的前一结点，
//然后改变指针域来删除结点，但是这样显然不是 O(1)
//可以根据要删除的结点得到他的下一个结点，然后将下一个结点的值给他，删除下一个结点。
//如果当前结点值为尾结点，同样需要从头遍历删除
#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(LinkList)

typedef int ElemType;
//定义一个单链表
typedef struct  LNode{
	ElemType data;
	struct LNode * next;
} LinkList;


int main() {
	DelListNode(LinkList * L,LinkList * p);
	DelListNode(L,p);
	return 0;
}

void DelListNode(LinkList * L,LinkList * p){
	//提高代码鲁棒性
	if(!L || !p)
		return
	if(L->next!=NULL){
		//P 非头非尾结点
		LinkList * pNext=p-next;
		p->data=pNext->data;
		p->next=pNext->next;
		free(pNext);
	}
	else if (L==p){
		//P为头结点
		free(L);
	}else{
		//p 为尾结点
		LinkList * s=L
		while(s->next!=p){
			s=s->next;
		}
		s->next=NULL;
		free(p);
	}
}