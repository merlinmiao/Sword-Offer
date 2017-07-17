//输入一个链表的头结点，从尾到头打印每个结点的值
//不容许改变输入的情况下
//使用栈配合输出


#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(LinkList)


int cnt=0;
typedef int ElemType;
//定义一个单链表
typedef struct  LNode{
	ElemType data;
	struct LNode * next;
} LinkList;




int main() {
	LinkList * CreateList(LinkList * head, ElemType a[],int n);
	void DispLink(LinkList *head);
	void CtrlStack(LinkList * L,int n);
	LinkList * head,*p;
	ElemType a[]={1,2,3,4,5};
	head=(LinkList *)malloc(LEN);
	int len=sizeof(a)/sizeof(ElemType);
	p=CreateList(head,a,len);
	DispLink(p);
	CtrlStack(p,len);
	return 0;
}

//尾插法建表
LinkList * CreateList(LinkList * head, ElemType a[],int n){
	int i;
	LinkList *s,*r;
	r=head;
	for(i=0;i<n;i++){
		s=(LinkList *)malloc(LEN);
		s->data=a[i];
		r->next=s;
		r=s;
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

//初始化一个链栈,即用头插法建栈
//执行进栈，出栈操作

void CtrlStack(LinkList * L,int n){
	int i;
	LinkList *s,*p,*r;
	//初始化一个栈
	s=(LinkList *)malloc(LEN);
	s->next=NULL;
	//进栈
	r=L->next;
	for(i=0;i<n;i++){
		p=(LinkList *)malloc(LEN);
		p->data=r->data;
		r=r->next;
		p->next=s->next;
		s->next=p;	
	}
	//出栈,即打印 栈 S 的值
	DispLink(s);
}