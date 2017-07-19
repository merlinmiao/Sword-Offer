//反转链表
//思路：调整一个节点，需要找到该结点前后的结点，因此使用3个指针同时运转

//注意鲁棒性：
//1、输入指针为 NULL 或者链表只有一个头结点
//2、反转后链表断裂

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
	LinkList * ReverseList(LinkList * L);
	LinkList *head,*p,*result;
	head = (LinkList *)malloc(LEN);
	ElemType a[]={1,2,3,4,5};
	int len = sizeof(a)/sizeof(ElemType);
	p=CreateList(head,a,len);
	DispLink(p);
	result=ReverseList(p);
	if (result==NULL) {
		printf("输入有误或者原链表为空!");
	}else {
		printf("\n反转链表的头结点的值为:%d",result->data);
		int j=0;
		while (result!=NULL) {
			printf("\n反转链表的第%d结点的值为:%d",++j,result->data);
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
void DispLink(LinkList * head){
	LinkList * p;
	int count=0;
	printf("第%d次调用!\n",++cnt);
	if (head==NULL) {
		printf("链表为空或者不存在！");
	}else{
		p=head->next;
		while (p!=NULL) {
			printf("链表第%d个结点的值是:%d\n",++count,p->data);
			p=p->next;
		}
	}
}

//实现反转链表

LinkList * ReverseList(LinkList * L){
	LinkList *p,*p_pre,*p_reverse;
	p_reverse=NULL;
	p_pre=NULL;
	p=L;
	while (p!=NULL) {
		LinkList * p_next=p->next;
		if(p_next==NULL){
			p_reverse=p;
		}
		p->next=p_pre;
		p_pre=p;
		p=p_next;
	}
	return p_reverse;
}
