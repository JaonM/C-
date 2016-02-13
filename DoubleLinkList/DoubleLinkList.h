
typedef struct {
	int value;
}ElemType;

typedef struct {
	ElemType value;
	DoubleLNode *prior;
	DoubleLNode *next;
}DoubleLNode,*DoubleLinkList;

