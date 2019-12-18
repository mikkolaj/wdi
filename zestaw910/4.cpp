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

void odwroc(node *&start)
{
  if(start==NULL)
    return;
  node *tyl=NULL;
  node *pom;
  while(start!=NULL)
  {
    pom=start->next;
    start->next=tyl;
    tyl=start;
    start=pom;
  }
  start=tyl;
}

int main()
{
  node *f1=NULL;
  int tab1[5]={1, 5, 7, 34, 34};
  for(int i=0; i<5; i++)
    dodaj(f1, tab1[i]);
  node *wyn=new node;
  odwroc(f1);
  print(f1);
  return 0;
}
