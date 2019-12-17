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

void scal(node *&wyn, node *start1, node *start2)
{
  if(start1==NULL)
  {
    wyn->next=start2;
    return;
  }
  if(start2==NULL)
  {
    wyn->next=start1;
    return;
  }
  node *temp=new node;
  if(start1->w<start2->w)
  {
    temp->w=start1->w;
    wyn->next=temp;
    temp=start1;
    start1=start1->next;
    delete temp;
    scal(wyn->next, start1, start2);
  }
  else
  {
    temp->w=start2->w;
    wyn->next=temp;
    temp=start2;
    start2=start2->next;
    delete temp;
    scal(wyn->next, start1, start2);
  }
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
  node *wyn=new node;
  scal(wyn, f1, f2);
  node *temp=wyn;
  wyn=wyn->next;
  delete temp;
  print(wyn);
  return 0;
}
