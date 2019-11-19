#include <iostream>
using namespace std;

struct ulamek 
{
  int l;  // calkowity
  int m; // N+
};

void wsppodst(ulamek &a, ulamek &b)
{
  if(b.m!=a.m)
  {
    int bmc=b.m;
    b.m*=a.m;
    b.l*=a.m;
    a.l*=bmc;
    a.m*=bmc;
  }
}

void skroc(ulamek &a)
{
  if(a.l!=0)
  {
    int lc = abs(a.l);
    int mc = a.m;
    while(mc!=lc) //NWW
    {
      if(lc>mc)
        lc-=mc;
      else
        mc-=lc;
    }
    a.l/=mc;
    a.m/=mc;
  }
}

ulamek dodaj(ulamek a, ulamek b)
{
  wsppodst(a, b);
  ulamek c;
  c.l=a.l+b.l;
  c.m=a.m;
  skroc(c);
  return c;
}

ulamek odejmij(ulamek a, ulamek b)
{
  b.l=-b.l;
  return dodaj(a, b);
}

ulamek pomnoz(ulamek a, ulamek b)
{
  ulamek c;
  c.l=a.l*b.l;
  c.m=a.m*b.m;
  skroc(c);
  return c;
}

ulamek podziel(ulamek a, ulamek b)
{
  int temp=b.l;
  b.l=b.m;
  b.m=temp;
  return pomnoz(a, b);
}

ulamek podaj()
{
  ulamek a;
  cout << "Podaj licznik: ";
  cin >> a.l;
  cout << "Podaj mianownik: ";
  cin >> a.m;
  return a;
}

ulamek potega(ulamek a, int n)
{
  ulamek ac=a;
  if(n==0)
  {
    a.l=1;
    a.m=1;
    return a;
  }
  while(n>1)
  {
    a=pomnoz(a, ac);
    n--;
  }
  return a;
}

void wypisz(ulamek a)
{
  if(a.l==0)
    cout << 0;
  else if(a.m=1)
    cout << a.l; 
  else
    cout << a.l << "/" << a.m;
}

int main()
{
  ulamek xd, elo;
  xd.l=1;
  xd.m=1;
  elo.l=1;
  elo.m=1;
  wypisz(xd);
  cout << " ";
  wypisz(elo);
  cout << endl;
  wypisz(dodaj(xd, elo));
  cout << endl;
  cout << -4/2 << endl;
  wypisz(potega(elo, 4));
  cout << endl;
  elo.l=11;
  elo.m=22;
  skroc(elo);
  wypisz(elo);
  return 0;
}
