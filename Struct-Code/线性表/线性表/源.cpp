void Insert(ListNode *head, int x)
{// ��Ϊ��ͷ��㣬��Ա���������밴�Լ���ʵ������޸�
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