#include<bits/stdc++.h>
#include"myll.h"
using namespace std;
node* symmdiffll(node *start1,node *start2)
{
  node *p,*q;
  p=start1;
  q=start2;
  node *start3;
  start3=getnode();
  start3=NULL;
  while(p!=NULL&&q!=NULL)
  {
    if(p->info>q->info)
    {
      insbeg(&start3,q->info);
      q=q->next;
    }
    else if(p->info<q->info)
    {
      insbeg(&start3,p->info);
      p=p->next;
    }
    else 
    {
      //insbeg(&start3,q->info);
      p=p->next;
      q=q->next;
    }
  }
  while(p!=NULL)
  {
    insbeg(&start3,p->info);
    p=p->next;
  }
   while(q!=NULL)
  {
    insbeg(&start3,q->info);
    q=q->next;
  }
  return start3;
}
int main ()
{
   node *start1=NULL;
  node *start2=NULL;
  insbeg(&start1,'z');
  insbeg(&start1,'n');
  insbeg(&start1,'m');
  insbeg(&start1,'b');
  insbeg(&start1,'a');
  insbeg(&start2,'z');
  insbeg(&start2,'w');
  insbeg(&start2,'f');
  insbeg(&start2,'e');
  insbeg(&start2,'a');  
  traverse(start1); cout <<" ";
  cout <<"\n"; 
  traverse(start2); cout <<" ";
  cout <<"\n";
  node *z=symmdiffll(start1,start2);
  traverse(z); cout <<"\n";
  node *r=reverse(z);
  traverse(r);
  return 0;
}