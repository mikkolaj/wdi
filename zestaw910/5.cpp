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

void dodajnode(node *&start, node *&nowy)
{
  if(start==NULL)
  {
    start=nowy;
    nowy=nowy->next;
    start->next=NULL;
    return;
  }
  node *r=nowy;
  nowy=nowy->next;
  r->next=start;
  start=r;
}

void rozdziel(node *&start, node *tab[])
{
  while(start!=NULL)
    dodajnode(tab[start->w%10], start);
}

node *scalliste(node *tab[])
{
  int i=0;
  node *wyn=NULL;
  node *last=NULL;
  while(i<10)
  {
    while(tab[i]==NULL)
      i++;           
    if(wyn==NULL)
    {
      wyn=tab[i];
      last=tab[i];
    }
    else
    {
      node *r=last;
      while(r->next!=NULL)
        r=r->next;
      r->next=tab[i];
      last=r->next;
    }
    i++;
  }
  return wyn;
}

const int N=100;

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
