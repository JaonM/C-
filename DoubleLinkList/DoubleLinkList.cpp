#include <stdio.h>
#include "DoubleLinkList.h"
#include <malloc.h>

/*根据位置返回指向改节点的指针*/
DoubleLNode* GetElem_DL(DoubleLinkList L, int position) {
	DoubleLNode *p = L->next;
	int j = 0;
	while (p&&j < position) {
		p = p->next;
		j++;
	}
	if (!p || j > position) {
		return 0;	//未找到该元素
	}
	return p;
}

/*在第i个元素之前插入e*/
int ListInser_DL(DoubleLinkList L, int i, ElemType e) {
	DoubleLNode *p;
	if (!(p = GetElem_DL(L, i))) {
		return 0;				//没找到插入位置的元素
	}

	//创建新节点
	DoubleLNode *s;
	if (!(s = (DoubleLinkList)malloc(sizeof(DoubleLNode))) {
		return 0;			//创建未成功
	}

	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return 1;
}

/*删除第i个元素*/
int ListDelete_DL(DoubleLinkList L, int i) {
	DoubleLNode *p;
	if (!(p = GetElem_DL(L, i))) {
		return 0;			//未找到改节点
	}
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);		// 释放p节点
	return 1;
}