//合并两个递增链表：面试常考
//有序表的归并
//1->3->5->7
//2->4->6->8

//思路：同时比较两个链表的头指针即可

//注意鲁棒性：
//1、输入指针为 NULL 或者链表只有一个头结点


#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(LinkList)

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode * next;
} LinkList;

int cnt=0;

int main() {
	LinkList * CreateList(LinkList * head,ElemType a[],int n);
	void DispLink(LinkList * head);
	LinkList * MergeList(LinkList * L1,LinkList * L2);
	LinkList *head1,*head2,*p1,*p2,*result;
	head1 = (LinkList *)malloc(LEN);
	head2 = (LinkList *)malloc(LEN);
	ElemType a[]={1,3,5,7};
	ElemType b[]={2,4,6,8};
	int len = sizeof(a)/sizeof(ElemType);
	p1=CreateList(head1,a,len);
	p2=CreateList(head2,b,len);
	DispLink(p1);
	DispLink(p2);
	result=MergeList(p1,p2);
	if (result==NULL) {
		printf("输入有误或者原链表为空!");
	}else {
		int j=0;
		while (result!=NULL) {
			printf("\n合并链表的第%d结点的值为:%d",++j,result->data);
			result=result->next;
		}
	}
	return 0;
}

//尾插法实现链表
LinkList * CreateList(LinkList * head,ElemType a[],int n){
	LinkList *p,*r;
	int i;
	r=head;
	r->data=a[0];
	for(i=1;i<n;i++){
		p=(LinkList *)malloc(LEN);
		p->data=a[i];
		r->next=p;
		r=p;
	}
	r->next=NULL;
	return head;
}

//打印链表
void DispLink(LinkList * head){
	LinkList * p;
	int count=0;
	printf("第%d次调用!\n",++cnt);
	if (head==NULL) {
		printf("链表为空或者不存在！");
	}else{
		p=head;
		while (p!=NULL) {
			printf("链表第%d个结点的值是:%d\n",++count,p->data);
			p=p->next;
		}
	}
}

//实现反转链表

LinkList * MergeList(LinkList * L1,LinkList * L2){
	if(L1==NULL){
		return L2;
	}else if(L2==NULL){
		return L1;
	};
	LinkList *p_new=NULL;
	if(L1->data<L2->data){
		p_new=L1;
		p_new->next=MergeList(L1->next,L2);
	}else{
		p_new=L2;
		p_new->next=MergeList(L1,L2->next);
	}
	return p_new;
}
