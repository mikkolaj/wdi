#include <iostream>
using namespace std;

struct node{
  int w=-1;
  node *next=NULL;
};

void print(node *start)
{
  if(start==NULL)
  {
    cout << "Lista pusta." << endl;
    return;
  }
  while(start!=NULL)
  {
    cout << start->w << " ";
    start=start->next;
  }
  cout << endl;
}

void dodaj(node *&start, int el)
{
  if(start==NULL)
  {
    start = new node;
    start->w=el;
    return;
  }
  node *r=start;
  while(r->next!=NULL)
  {
    r=r->next;
  }
  r->next=new node;
  r->next->w=el;
}

node *scal(node *start1, node *start2)
{
  if(start1==NULL)
    return start2;
  if(start2==NULL)
    return start1;
  node *wyn=new node;
  node *wynpr=wyn;
  while(start1!=NULL && start2!=NULL)
  {
    if(start1->w<start2->w)
    {
      wyn->next=start1;
      start1=start1->next;
    }
    else
    {
      wyn->next=start2;
      start2=start2->next;
    }
    wyn=wyn->next;
  }
  node *temp;
  if(start1==NULL)
    start1=start2;
  wyn->next=start1;
  temp=wynpr;
  wynpr=wynpr->next;
  delete temp;
  return wynpr;
}

int main()
{
  node *f1=NULL;
  node *f2=NULL;
  int tab1[5]={1, 5, 7, 34, 34};
  int tab2[3]={3, 5, 9};
  for(int i=0; i<5; i++)
  {
    dodaj(f1, tab1[i]);
  }
  for(int i=0; i<3; i++)
  {
    dodaj(f2, tab2[i]);
  }
  node *wynik=scal(f1, f2);
  print(wynik);
  return 0;
}
