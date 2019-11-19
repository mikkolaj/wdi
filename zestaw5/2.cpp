#include <iostream>
using namespace std;

struct ulamek 
{
  int l;  // ca³kowity
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
    while(mc!=lc)
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

bool porownaj(ulamek a, ulamek b)
{
  if(a.l==b.l && a.m==b.m)
    return true;
  return false;
}

void wczytrown(ulamek &a, ulamek &b, ulamek &c)
{
  cout << "Wspolczynnik przy x: " << endl;
  a=podaj();
  cout << "Wspolczynnik przy y: " << endl;
  b=podaj();
  cout << "Wyraz wolny: " << endl;
  c=podaj();
}

void rozwiaz(ulamek a, ulamek b, ulamek c, ulamek d, ulamek e, ulamek f)
{
  ulamek wg=odejmij(pomnoz(a,e), pomnoz(b,d));
  ulamek wx=odejmij(pomnoz(c,e), pomnoz(b,f));
  ulamek wy=odejmij(pomnoz(a,f), pomnoz(c,d));
  if(porownaj(wx, wy) && porownaj(wy, wg) && wx.l==0)
  {
    cout << "Niesk. wiele rozwiazan" << endl;
  }
  else if(wg.l==0 && (wx.l!=0 || wy.l!=0))
  {
    cout << "Nie ma rozwiazan" << endl;
  }
  else
  {
    cout << "x to: ";
    wypisz(podziel(wx, wg));
    cout << endl;
    cout << "y to: ";
    wypisz(podziel(wy, wg));
    cout << endl;
  }
}

int main()
{
  ulamek a, b, c, d, e, f;
  cout << "Rownanie 1:" << endl;
  wczytrown(a, b, c);
  cout << "Rownanie 2:" << endl;
  wczytrown(d, e, f);
  rozwiaz(a, b, c, d, e, f);
  return 0;
}
