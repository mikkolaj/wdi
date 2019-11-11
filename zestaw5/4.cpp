#include <iostream>
using namespace std;

int maxa=4;

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

int licz(ulamek t[])
{
  int la=0, lg=0;
  int dla, dlg;
  ulamek roz, ilo;
  roz=odejmij(t[1], t[0]);
  dla=2;
  ilo=podziel(t[1], t[0]);
  dlg=2;
  for(int i=2; i<maxa; i++)
  {
    if(porownaj(roz, odejmij(t[i], t[i-1])))
    {
      if(dla==2)
        la++;
      dla++;
    }
    else
    {
      dla=2;
      roz=odejmij(t[i], t[i-1]);
    }
    if(porownaj(ilo, podziel(t[i], t[i-1])))
    {
      if(dlg==2)
        lg++;
      dlg++;
    }
    else
    {
      dlg=2;
      ilo=podziel(t[i], t[i-1]);
    }
  }
  cout << la << endl << lg << endl;
  if(la<lg)
    return -1;
  else if(la>lg)
    return 1;
  else
    return 0;
}

int main()
{
	ulamek t[maxa];
	for(int i=0; i<maxa; i++)
	{
	  t[i]=podaj();
  }
	cout << licz(t);
	return 0;
}
