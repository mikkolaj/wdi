#include <iostream>
using namespace std;

struct node{
  int w=-1;
  node *next=NULL;
};

bool nalezy(node *start, int szuk)
{
  while(start!=NULL)
  {
    if(start->w==szuk)
      return true;
    start=start->next;
  }
  return false;
}

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
  if(!nalezy(start, el))
  {
    node *r=new node;
    r->w=el;
    r->next=start;
    start=r;
  }
}

void remove(node *&start, int szuk)
{
  if(start==NULL)
    return;
  node *prev=NULL, *r=start;
  while(r!=NULL && r->w!=szuk)
  {
    prev=r;
    r=r->next;
  }
  if(r==NULL)
    return;
  if(prev!=NULL)
  {
    prev->next=r->next;
  }
  else
  {
    start=start->next;
  }
  delete r;
}

int main()
{
  node *f=NULL;
  //f->w=2;
  //f->next=new node;
  //f->next->w=7;
  //print(f);
  for(int i=0; i<1; i++)
    dodaj(f, i);
  print(f);
  remove(f, 0);
  print(f);
	return 0;
}
