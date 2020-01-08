#include <iostream>
using namespace std;

struct wezel{
  string tekst="";
  wezel *nast=NULL;
};

wezel *podaj()
{
  string tekst;
  wezel *poczatek=NULL;
  wezel *wez=NULL;
  while(cin >> tekst && tekst!="0")
  {
    wezel *nowy=new wezel;
    nowy->tekst=tekst;
    if(wez==NULL)
    {
      poczatek=nowy;
      wez=nowy;
    }
    else
    {
      wez->nast=nowy;
      wez=wez->nast;
    }
  }
  return poczatek;
}

void print(wezel *start)
{
  if(start==NULL)
  {
    cout << "Lista pusta." << endl;
    return;
  }
  while(start!=NULL)
  {
    cout << start->tekst << " ";
    start=start->nast;
  }
  cout << endl;
}

int main()
{
  wezel *lista=NULL;
  lista=podaj();
  print(lista);
	return 0;
}
