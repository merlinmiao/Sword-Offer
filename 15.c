//输入一个链表，输出该链表的倒数第 K 个结点，链表只能遍历一次
//思路：用两个指针均指向头结点，一个指针从头结点开始先走 k-1步，第二个指针保持不动；
//从第 K步开始，两个指针同时走，两个指针距离始终保持在 K-1步，当第一个指针到达链表的尾部时，
//第二个指针正好是倒数第 k 个结点。

//注意鲁棒性：
//1、头指针为空
//2、链表个数少于 K
//3、K=0

#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(LinkList)

int cnt=0;

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode * next;
} LinkList;

int main() {
	LinkList * CreateList (LinkList * head,ElemType a[],int n);
	void DispLink(LinkList *head);
	LinkList * FindTheK(LinkList * L,int k);
	LinkList * head,*p,*r;
	ElemType a[]={1,2,3,4,5,6,7,8,9};
	int len=sizeof(a)/sizeof(ElemType);
	head=(LinkList *)malloc(LEN);
	p=CreateList(head,a,len);
	DispLink(p);
	int k=3;
	r=FindTheK(p,k);
	if (r!=NULL) {
		printf("倒数第%d个结点对应的值为%d",k,r->data);
	}else{
		printf("输入有误或者您要找的值不存在！");
	}
	return 0;
}

//尾插法建表

LinkList * CreateList (LinkList * head,ElemType a[],int n){
	LinkList *p,*r;
	int i;
	r=head;
	for(i=0;i<n;i++){
		p=(LinkList *)malloc(LEN);
		p->data=a[i];
		r->next=p;
		r=p;
	}
	r->next=NULL;
	return head;
}

//打印链表
void DispLink(LinkList *head){
	int i;
	int count=0;
	printf("\n链表第%d次调用\n",++cnt);
	LinkList *p=head->next;
	while(p!=NULL){
		printf("链表第%d个值是:%d\n",++count,p->data);
		p=p->next;
	}
}


//找到倒数第 k 个结点，并打印其值
LinkList * FindTheK(LinkList * L,int k){
	int i;
	LinkList *p1,*p2;
	p1=p2=L;
	//验证鲁棒性1，3
	if (L==NULL || k==0) {
		p2=NULL;
	}
	for(i=0;i<k-1;++i){
		//验证鲁棒性2
		if(p1->next!=NULL){
			p1=p1->next;
		}else{
			p2=NULL;
		}
	}
	while (p1->next!=NULL) {
		p1=p1->next;
		p2=p2->next;
	}
	return p2;
}