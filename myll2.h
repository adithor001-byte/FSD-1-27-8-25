#include<iostream>
using namespace std;
struct node
{
  int info;
  struct node *next;
};
node *getnode()
{
  node *p;
  p=(node *)malloc(sizeof(struct node));
  return p; 
}
  void traverse(node *start)
  {
    node *p;
    p=start;
    while (p!=NULL)
    {
     cout <<(p->info) <<" ";
     p=p->next;
    }
  }
 void insbeg(node **start,int x)
  {
    node *p;
    p=getnode();
    p->info=x;
    p->next=*start;
    *start=p;
  }
  void  insafter(node **q,int x)
 {
   node *p;
   p=getnode();
   node *r;
   p->info=x;
   r=(*q)->next;
   (*q)->next=p;
   p->next=r;
}
void insend(node **start,int x)
{
  node *p;
  node *q;
  q=*start;
  p=getnode();
  p->info=x;
  p->next=NULL;
  while(q->next!=NULL)
  {
    q=q->next;
  }
  q->next=p;
}
node*  reverse(node *start)
  {
    node  *p=NULL;
    node *c=start;
    node *n;
    n=c->next;
    while(c!=NULL)
    {
      c->next=p;
      p=c;
      c=n;
      if(n!=NULL)
        n=n->next;
      start=p;  
    }
    return start;
  }