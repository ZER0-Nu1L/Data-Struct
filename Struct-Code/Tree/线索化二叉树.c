TBinTree  zxxsh(TBinTree bt)
{
	TBinTree p, pr, s[M], t;
	int i = 0;
	t = (TBinTree)malloc(sizeof(TBinTreeNode));
	t->lt = 0; t->rt = 1;   t->rc = t;
	if (bt == NULL)       t->lc = t;
	else
	{
		t->lc = bt;  pr = t;   p = bt;
		do {
			while (p != NULL)
			{
				s[i++] = p;  p = p->lc;
			}
			if (i > 0)
			{
				p = s[--i];
				printf("%c  ", p->data);
				if (p->lc == NULL)
				{
					p->lt = 1;  p->lc = pr;
				}
				if (pr->rc == NULL)
				{
					pr->rt = 1; pr->rc = p;
				}
				pr = p;    p = p->rc;
			}
		} while (i > 0 || p != NULL);
		pr->rc = t; pr->rt = 1;  t->rc = pr;
	}
	return(t);
}

