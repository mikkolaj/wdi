#include <iostream>
#include <cstdlib>
#include <ctime>
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

void rozdziel(node *&start, node *tab[])
{
  while(start!=NULL)
  {
    int val=start->w%10;
    node *r=start;
    start=start->next;
    r->next=tab[val];
    tab[val]=r;
  }
}

node *scalliste(node *tab[])
{
  node *odp=new node;
  node *wyn=odp;
  for(int i=0; i<10; i++)
  {
    while(tab[i]!=NULL)
    {
      wyn->next=tab[i];
      tab[i]=tab[i]->next;
      wyn=wyn->next;
    }
  }
  wyn=odp;
  odp=odp->next;
  delete wyn;
  return odp;
}

const int N=10;

int main()
{
  node *f1=NULL;
  for(int i=0; i<N; i++)
    dodaj(f1, rand()%100+1);
  node *tab[10];
  for(int i=0; i<10; i++)
    tab[i]=NULL;
  print(f1);
  rozdziel(f1, tab);
  node *scalona=scalliste(tab);
  print(scalona);
  return 0;
}
