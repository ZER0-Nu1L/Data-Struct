void Insert(ListNode *head, int x)
{// 设为有头结点，成员和类型名请按自己的实际情况修改
	ListNode *p, *q;
	p = head->next;
	q = head;
	while (p != NULL && p->data < x)
	{
		q = p;
		p = p->next;
	}
	p = (ListNode *)malloc(sizeof(ListNode));
	p->data = x;
	p->next = q->next;
	q->next = p;
}