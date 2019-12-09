#include <iostream>
using namespace std;

struct node{
  int w=0;
  node *next=NULL;
};

const int N=100;

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

void init(node *&tab)
{
  tab=new node;
  node *r=tab;
  for(int i=0; i<N-1; i++)
  {
    node *nowy=new node;
    r->next=nowy;
    r=r->next;
  }
}

int value(node *tab, int n)
{
  int i;
  for(i=0; tab->next!=NULL; i++)
  {
    if(i==n)
      return tab->w;
    tab=tab->next;
  }
  if(i==n)
    return tab->w;
  return -1;
}

void set(node *&tab, int n, int value)
{
  int i;
  node *p=tab;
  for(i=0; p->next!=NULL; i++)
  {
    if(i==n)
    {
      p->w=value;
      return;
    }
    p=p->next;
  }
  if(i==n)
    p->w=value;
}

int main()
{
  node *f=NULL;
  init(f);
  set(f, 99, 70);
  set(f, 0, 5);
  set(f, 25, 4);
  print(f);
  cout << value(f, 99);
	return 0;
}
