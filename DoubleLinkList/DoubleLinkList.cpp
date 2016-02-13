#include <stdio.h>
#include "DoubleLinkList.h"
#include <malloc.h>

/*����λ�÷���ָ��Ľڵ��ָ��*/
DoubleLNode* GetElem_DL(DoubleLinkList L, int position) {
	DoubleLNode *p = L->next;
	int j = 0;
	while (p&&j < position) {
		p = p->next;
		j++;
	}
	if (!p || j > position) {
		return 0;	//δ�ҵ���Ԫ��
	}
	return p;
}

/*�ڵ�i��Ԫ��֮ǰ����e*/
int ListInser_DL(DoubleLinkList L, int i, ElemType e) {
	DoubleLNode *p;
	if (!(p = GetElem_DL(L, i))) {
		return 0;				//û�ҵ�����λ�õ�Ԫ��
	}

	//�����½ڵ�
	DoubleLNode *s;
	if (!(s = (DoubleLinkList)malloc(sizeof(DoubleLNode))) {
		return 0;			//����δ�ɹ�
	}

	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return 1;
}

/*ɾ����i��Ԫ��*/
int ListDelete_DL(DoubleLinkList L, int i) {
	DoubleLNode *p;
	if (!(p = GetElem_DL(L, i))) {
		return 0;			//δ�ҵ��Ľڵ�
	}
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);		// �ͷ�p�ڵ�
	return 1;
}