#include <iostream>
using namespace std;

struct node{
  int w=0;
  int ile=0;
  node *next=NULL;
};

const int N=10;

void print(node *start)
{
  if(start==NULL)
  {
    cout << "Lista pusta." << endl;
    return;
  }
  while(start!=NULL)
  {
    for(int i=0; i<start->ile; i++)
      cout << start->w << " ";
    start=start->next;
  }
  cout << endl;
}

void init(node *&tab)
{
  tab=new node;
  tab->ile=N;
}

int value(node *tab, int n)
{
  int i=0;
  while(tab!=NULL)
  {
    int ic=0;
    while(ic<tab->ile)
    {
      if(i==n)
        return tab->w;
      i++;
      ic++;
    }
    tab=tab->next;
  }
  if(i==n)
    return tab->w;
}

void set(node *&wez, int n, int val)
{
  int i=0;
  node *prev=NULL;
  node *tab=wez;
  node *nowy=new node;
  nowy->w=val;
  nowy->ile=1;
  if(n==0)  // uogólniæ ten warunek do pocz¹tku ka¿dego fragmentu
  {
    if(tab->w==val)
    {
      return;
    }
    if(tab->ile==1)
    {
      if(tab->next->w!=val)
      {
        tab->w=val;
      }
      else
      {
        tab->next->ile++;
        nowy=tab->next;
        delete tab;
        wez=nowy;
      }
      delete nowy;
      return;
    }
    else
    {
      tab->ile--;
      nowy->next=tab;
      wez=nowy;
    }
    return;
  }
  while(tab!=NULL)
  {
    int ic=0;
    while(ic<tab->ile && i<=n)
    {
      if(i==n)
      {
        if(ic==0)
        {
          if(tab->w!=val)
          {
          if(tab->ile==1)
          {
            prev->next=nowy;
            nowy->next=tab->next;
            delete tab;
          }
          else
          {
            tab->ile--;
            prev->next=nowy;
            nowy->next=tab;
          }
          }
          return;
        }
        if(ic==n)
        {
          if(tab->w!=val)
          {
          if(tab->ile!=1)
          {
          tab->ile--;
          tab->next=nowy;
          }
          else
          {
            tab->w=val;
            delete nowy;
          }
          }
          return;
        }
        if(ic==tab->ile-1)
        {
          
        }


        {
          if(n==7)
            cout << tab->ile << endl;
          /*if(tab->ile==1)     // napisaæ wstawianie na pocz¹tek fragmentu
          {
            nowy->next=tab->next;
            delete tab;
            tab=nowy;
          }*/
          node *prawa=new node;
          prawa->w=tab->w;
          prawa->ile=tab->ile-ic-1;
          prawa->next=tab->next;
          tab->ile=ic;
          tab->next=nowy;
          nowy->next=prawa;
        }
        return;
      }
      i++;
      ic++;
    }
    prev=tab;
    tab=tab->next;
  }
}

int main()
{
  node *f=NULL;
  init(f);
  //set(f, 9, 70);
  //set(f, 0, 5);
  set(f, 5, 4);
  set(f, 1, 1);
  //set(f, 7, 55);
  //cout << value(f, 69);
  print(f);
	return 0;
}
