#include <stdio.h>
#include <alloc.h>
#define M 20
#define MAX 100
typedef struct node
{
  int vex;
  int length;
  struct node *next;
}JD;
typedef struct tnode
{
  int vexdata;
  int in;
  struct node *link;
}TD;

int loc_vertex(TD g[], int vex, int n)//²éÕÒÖµÎªvexµÄ¶¥µãÐòºÅ
{
  int i, j;
  for (i = 1;i <= n;i++)
    if (g[i].vexdata == vex)
      return(i);
  return(0);
}
int crt_linklist(TD g[])//´´½¨ÁÚ½Ó±í
{
  int n, e, i, j, k, vt, vh, length;//n¸ö¶¥µã£¬eÌõ±ß£¬lengthÈ¨Öµ
  JD *p;
  printf("Input and the number of node,arc:");
  scanf("%d,%d", &n, &e);
  for (i = 1;i <= n;i++)//ÊäÈë¶¥µã
  {
    printf("g[%d].vexdata=", i);
    scanf("%d", &g[i].vexdata);
    g[i].in = 0;
    g[i].link = NULL;
  }
  for (k = 1;k <= e;k++)//ÊäÈë±ß
  {
    printf("Vt,Vh,length:");
    scanf("%d,%d,%d", &vt, &vh, &length);
    i = loc_vertex(g, vt, n);
    j = loc_vertex(g, vh, n);
    p = (JD *)malloc(sizeof(JD));
    p->vex = j;
    p->length = length;
    p->next = g[i].link;
    g[i].link = p;
  }
  return(n);
}

void cal_in(TD g[], int n)//¼ÆËãÈë¶È
{
  int i, k;
  JD *p;
  for (i = 1;i <= n;i++)
  {
    p = g[i].link;
    while (p != NULL)
    {
      k = p->vex;
      g[k].in++;
      p = p->next;
    }
  }
}

int dut(TD g[], int vt, int vh)//·µ»ØÈ¨Öµ£¬¼´³ÖÐøÊ±¼ä
{
  JD *p;
  p = g[vt].link;
  while (p != NULL)
  {
    if (p->vex == vh)
      return(p->length);
    else
      p = p->next;
  }
  return(MAX);
}

int toporder(TD g[], int n, int ve[], int top2[], int *t2)//ÍØÆËÅÅÐò,t2±£´æÄæÍØÆËÐòÁÐÖÐ¶¥µã¸öÊý
{
  int top1[M];
  int m, k, j, top;
  JD *p;
  top = 0; m = 0;
  for (j = 1;j <= n;j++)
    ve[j] = 0;
  /************************************ÅÅÐò*/
  for (j = 1;j <= n;j++)
    if (g[j].in == 0)//Èë¶ÈÎª0µÄ¶¥µãÈëÕ»
    {
      top1[top] = j;
      top++;
    }
  while (top > 0)
  {
    j = top1[--top];
    top2[*t2] = j;
    (*t2)++;
    m++;
    p = g[j].link;
    while (p != NULL)
    {
      k = p->vex;
      g[k].in--;
      if (g[k].in == 0)
        top1[top++] = k;
      /*****************************************Çóve*/
      if (ve[j] + dut(g, j, k) > ve[k])
        ve[k] = ve[j] + dut(g, j, k);
      p = p->next;
    }
  }
  if (m < n)  return(0);
  else     return(1);
}

void critical_path(TD g[], int n)
{
  int i, t2 = 0, j, k, ee, el;
  char tag;
  JD *p;
  int ve[M], vl[M], top2[M];
  i = toporder(g, n, ve, top2, &t2);
  if (!i)
    printf("Has a cycle!");
  else/***************Çóvl*/
  {
    for (i = 1;i <= n;i++)
      vl[i] = MAX;
    vl[n] = ve[n];
    while (t2 > 0)
    {
      j = top2[--t2];
      p = g[j].link;
      while (p != NULL)
      {
        k = p->vex;
        if (vl[k] - dut(g, j, k) < vl[j])
          vl[j] = vl[k] - dut(g, j, k);
        p = p->next;
      }
    }
    for (j = 1;j <= n;j++)//Çó¹Ø¼ü»î¶¯
    {
      p = g[j].link;
      while (p != NULL)
      {
        k = p->vex;
        ee = ve[j];
        el = vl[k] - dut(g, j, k);
        if (ee == el)
          tag = '*';
        else
          tag = ' ';
        printf("Vt=%d,Vh=%d,Length=%d,ee=%d,el=%d,%c\n", j, k, dut(g, j, k), ee, el, tag);
        p = p->next;
      }
    }
  }
}

void main()
{
  int n;
  TD g[M];
  n = crt_linklist(g);
  cal_in(g, n);
  critical_path(g, n);
}