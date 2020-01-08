#include <iostream>
using namespace std;

struct node{
  int w=-1;
  node *next=NULL;
};

struct wezel{
  int w=-1;
  wezel *nast=NULL;
  wezel *ost=NULL;
};

struct interval{
  int beg=0;
  int end=0;
  interval *next=NULL;
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

void addend(node *&start, int v)
{
  if(start==NULL)
  {
    start=new node;
    start->w=v;
  }
  else
  {
    node *pom=start;
    while(pom->next!=NULL)
    {
      pom=pom->next;
    }
    pom->next=new node;
    pom->next->w=v;
  }
}

void addnode(node *&start, node *dod)
{
  if(start==NULL)
    start=dod;
  else
  {
    node *pom=start;
    while(pom->next!=NULL)
      pom=pom->next;  
    pom->next=dod;
  }
}

node *last(node *start)
{
  if(start==NULL)
    return start;
  while(start->next!=NULL)
    start=start->next;
  return start;
}

void pop(node *&start)
{
  if(start==NULL)
    return;
  else if(start->next==NULL)
  {
    delete start;
    start=NULL;
  }
  else
  {
    node *prev=start, *cur=start->next;
    while(cur->next!=NULL)
    {
      prev=cur;
      cur=cur->next;
    }
    prev->next=NULL;
    delete cur;
  } 
}

void codrugi(node *&start)
{
  node *wart=new node;
  wart->next=start;
  node *prev=wart, *cur=start;
  while(cur!=NULL)
  {
    cur=cur->next;
    delete prev->next;
    prev->next=cur;
    if(cur!=NULL)
    {
      prev=prev->next;
      cur=cur->next;
    }
  }
  start=wart->next;
  delete wart;
}

void incr(node *&start)
{
  node *prev=start, *cur=start->next;
  while(prev->next!=NULL)
  {
    prev=prev->next;
  }
  prev->w++;
  if(prev->w==10)
  {
    prev=start;
    while(1)
    {
      if(prev->w==10)
      {
        start=new node;
        start->next=prev;
        prev->w=0;
        start->w=1;
        break;
      }
      else if(cur->w==10)
      {
        cur->w=0;
        prev->w++;
        if(prev->w<10)
          break;
        else
        {
          prev=start;
          cur=start->next;
        }
      }
      else
      {
        prev=prev->next;
        cur=cur->next;
      }
    }
  }
}

node *sum(node *start1, node *start2)
{
  int licznik1=1, licznik2=1, carry=0;
  node *pom1=start1, *pom2=start2;
  node *wyn=NULL;
  while(pom1->next!=NULL)
  {
    pom1=pom1->next;
    licznik1++;
  }
  while(pom2->next!=NULL)
  {
    pom2=pom2->next;
    licznik2++;
  }
  while(licznik1>0 && licznik2>0)
  {
    node *nowy=new node;
    nowy->w=(pom1->w+pom2->w+carry)%10;
    carry=(pom1->w+pom2->w+carry)/10;
    if(wyn==NULL)
    {
      wyn=nowy;
    }
    else
    {
      nowy->next=wyn;
      wyn=nowy;
    }
    licznik1--;
    licznik2--;
    pom1=start1;
    pom2=start2;
    for(int i=1; i<=licznik1; i++)
      pom1=pom1->next;
    for(int j=1; j<=licznik2; j++)
      pom2=pom2->next;
  }
  if(licznik1==0)
  {
    licznik1=licznik2;
    start1=start2;
    pom1=pom2;
  }
  while(licznik1>0)
  {
    node *nowy=new node;
    nowy->w=(pom1->w+carry)%10;
    carry=(pom1->w+carry)/10;
    licznik1--;
    nowy->next=wyn;
    wyn=nowy;
    pom1=start1;
    for(int i=1; i<=licznik1; i++)
      pom1=pom1->next;
  }
  if(carry>0)
  {
    node *nowy=new node;
    nowy->w=carry;
    nowy->next=wyn;
    wyn=nowy;
  }
  return wyn;
}

node *sumwart(node *start1, node *start2)
{
  int licznik1=1, licznik2=1, carry=0;
  node *pom1=new node, *pom2=new node;
  pom1->w=pom2->w=0;
  pom1->next=start1;
  pom2->next=start2;
  start1=pom1;
  start2=pom2;
  node *wyn=NULL;
  while(pom1->next!=NULL)
  {
    pom1=pom1->next;
    licznik1++;
  }
  while(pom2->next!=NULL)
  {
    pom2=pom2->next;
    licznik2++;
  }
  while(licznik1>0 || licznik2>0 || carry>0)
  {
    node *nowy=new node;
    nowy->w=(pom1->w+pom2->w+carry)%10;
    carry=(pom1->w+pom2->w+carry)/10;
    if(wyn==NULL)
    {
      wyn=nowy;
    }
    else
    {
      nowy->next=wyn;
      wyn=nowy;
    }
    licznik1--;
    licznik2--;
    pom1=start1;
    pom2=start2;
    for(int i=1; i<=licznik1; i++)
      pom1=pom1->next;
    for(int j=1; j<=licznik2; j++)
      pom2=pom2->next;
    
  }
  delete pom1;
  delete pom2;
  return wyn;
}

void deladdkey(node *&start, int key)
{
  if(start==NULL)
  {
    start=new node;
    start->w=key;
  }
  else
  {
    node *wart=new node;
    wart->next=start;
    node *prev=wart;
    node *next=start;
    while(next->next!=NULL)
    {
      if(next->w==key)
      {
        node *pom=next;
        prev->next=next->next;
        delete pom;
        start=wart->next;
        delete wart;
        return;
      }
      prev=prev->next;
      next=next->next;
    }
    if(next->w==key)
    {
      prev->next=NULL;
      delete next;
    }
    else
    {
      next->next=new node;
      next->next->w=key;
    }
    start=wart->next;
    delete wart;
  }
}

void delsmaller(node *lista)
{
  if(lista==NULL)
    return;
  node *next=lista->next;
  while(next!=NULL)
  {
    while(next->w < lista->w)
    {
      node *pom=next;
      next=next->next;
      lista->next=next;
      delete pom;
      if(next==NULL)
        return;
    }
    lista=lista->next;
    next=next->next;
  }
}

void delmod(node *&lista)
{
  if(lista==NULL || lista->next==NULL)
    return;
  while(lista->next->w%lista->w==0)
  {
    node *pom=lista;
    lista=lista->next;
    delete pom;
    if(lista->next==NULL)
      return;
  }
  node *next=lista->next;
  node *prev=lista;
  while(next->next!=NULL)
  {
    while(next->next->w%next->w==0)
    {
      node *pom=next;
      next=next->next;
      prev->next=next;
      delete pom;
      if(next==NULL)
        return;
    }
    prev=prev->next;
    next=next->next;
  }
}

void deltri(node *&lista)
{
  if(lista==NULL)
    return;
  node *cur, *prev=new node;
  prev->next=lista;
  lista=prev;
  cur=lista->next;
  while(cur!=NULL)
  {
    int wc=cur->w, licz1=0, licz2=0;
    while(wc!=0)
    {
      if(wc%3==1)
        licz1++;
      else if(wc%3==2)
        licz2++;
      wc/=3;
    }
    if(licz1>licz2)
    {
      node *pom=cur;
      cur=cur->next;
      prev->next=cur;
      delete pom;
    }
    else
    {
      prev=prev->next;
      cur=cur->next;
    }
  }
  prev=lista;
  lista=lista->next;
  delete prev;
}

void moveeven(node *&start)
{
  if(start==NULL || start->next==NULL)
    return;
  node *prev=start, *cur=start->next;
  while(cur!=NULL)
  {
    int licznik=0, wc=cur->w;
    while(wc!=0)
    {
      if(wc%8==5)
        licznik++;
      wc/=8;
    }
    if(licznik%2==0 || licznik!=0)
    {
      prev->next=cur->next;
      cur->next=start;
      start=cur;
      cur=prev->next;
    }
    else
    {
      prev=prev->next;
      cur=cur->next;
    }
  }
}

void delodd(wezel *&lista)
{
  if(lista==NULL)
    return;
  wezel *cur=new wezel;
  cur->nast=lista;
  lista->ost=cur;
  cur=cur->nast;
  while(cur!=NULL)
  {
    int wc=cur->w, licznik=0;
    while(wc!=0)
    {
      if(wc%2==1)
        licznik++;
      wc/=2;
    }
    if(licznik%2==1)
    {
      cur->ost->nast=cur->nast;
      cur->nast->ost=cur->ost;
      cur=cur->nast;
      delete cur->ost;
    }
    else
    {
      cur=cur->nast;
    }
  }
  delete lista->ost;
  lista->ost=NULL;
}

void uniq(node *&lista)
{
  if(lista==NULL)
    return;
  node *cur=lista->next, *prev=lista;
  while(cur!=NULL)
  {
    node *prev2=prev;
    while(cur!=NULL)
    {
      if(cur->w==prev->w)
      {
        prev2->next=cur->next;
        delete cur;
        cur=prev2->next;
      }
      else
      {
        prev2=prev2->next;
        cur=cur->next;
      }
    }
    if(prev->next!=NULL)
    {
      cur=prev->next->next;
      prev=prev->next;
    }
  }
}

int delrep(node *&lista)
{
  if(lista==NULL)
    return 0;
  node *cur=lista->next, *prev=lista;
  int licznik=0;
  while(cur!=NULL)
  {
    if(cur->w==prev->w)
    {
      prev->next=cur->next;
      delete cur;
      cur=prev->next;
      licznik++;
    }
    else
    {
      prev=prev->next;
      cur=cur->next;
    }
  }
  return licznik;
}

void rocketstove(interval *&lista)
{
  if(lista==NULL)
    return;
  interval *prev=lista;
  while(prev!=NULL)
  {
    interval *prev2=prev;
    interval *cur=prev->next;
    while(cur!=NULL)
    {
      if(cur->beg >= prev->beg && cur->beg <= prev->end && cur->end >= prev->end)
      {
        prev->end=cur->end;
      }
      else if(cur->end >= prev->beg && cur->end <= prev->end && cur->beg <= prev->end)
      {
        prev->beg=cur->beg;
      }
      else if(cur->beg <= prev->beg && cur->end >= prev->end)
      {
        prev->beg=cur->beg;
        prev->end=cur->end;
      }
      else if(cur->beg >= prev->beg && cur->end <= prev->end)
      {
      }
      else
      {
        prev2=prev2->next;
        cur=cur->next;
        continue;
      }
      prev2->next=cur->next;
      delete cur;
      cur=prev2->next;
    }
    prev=prev->next;
  }
}

void printnowy(interval *f){
	cout << "PRINT:" << endl;
	while(f != NULL){
		cout << "[" << f->beg << ", " << f->end << "]" << "    ";
		f = f->next;
	}
	cout << endl;
}

void addLast(interval *&f, int start, int end){
	interval *nowy = new interval;
	nowy->beg = start;
	nowy->end = end;
	nowy->next = NULL;
	if(f == NULL){
		f = nowy;
		return;
	}
	else {
		interval *r = f;
		while(r->next != NULL){
			r = r->next;
		}		
		r->next = nowy;
	}
}

void delincr(node *&lista)
{
  if(lista==NULL)
    return;
  node *beg=new node, *end=lista;
  beg->next=lista;
  lista=beg;
  node *bfirst=NULL, *alast=NULL;
  int max=0;
  bool usuwac=false;
  while(beg->next!=NULL)
  {
    int licznik=1;
    node *tmp=beg;
    beg=beg->next;
    end=beg->next;
    while(end != NULL && end->w > beg->w)
    {
      licznik++;
      beg=beg->next;
      end=end->next;
    }
    if(licznik == max)
      usuwac=false;
    if(licznik > max)
    {
      usuwac=true;
      bfirst=tmp;
      alast=end;
      max=licznik;
    }
  }
  if(usuwac && bfirst!=NULL)
  {
    beg=bfirst->next;
    bfirst->next=alast;
    while(beg!=alast)
    {
      end=beg;
      beg=beg->next;
      delete end;
    }
  }
  bfirst=lista;
  lista=lista->next;
  delete bfirst;
}

bool iscycle(node *lista)
{
  if(lista==NULL)
    return false;
  node *slw=lista, *fst=lista->next;
  while(fst!=NULL)
  {
    if(fst==slw)
      return true;
    slw=slw->next;
    if(fst->next != NULL)
      fst=fst->next->next;
    else
      return false;
  }
  return false;
}

int cyclelen(node *lista)
{
  node *slw=lista, *fst=lista->next;
  int licznik=0;
  bool licz=false;
  while(fst!=slw)
  {
    slw=slw->next;
    fst=fst->next->next;
  }
  do
  {
    slw=slw->next;
    licznik++;
  }
  while(slw!=fst);
  return licznik;
}

int befcycle(node *lista)
{
  node *slw=lista, *fst=lista->next, *first=lista;
  int licznik=0;
  bool licz=false;
  while(fst!=slw)
  {
    slw=slw->next;
    fst=fst->next->next;
  }
  while(1)
  {
    do
    {
      if(slw==first)
        return licznik;
      slw=slw->next;
    }
    while(slw!=fst);
    licznik++;
    first=first->next;
  }
}

node *ptrbefcycle(node *lista)
{
  node *slw=lista, *fst=lista->next, *first=lista, *before=NULL;
  int licznik=0;
  bool licz=false;
  while(fst!=slw)
  {
    slw=slw->next;
    fst=fst->next->next;
  }
  while(1)
  {
    do
    {
      if(slw==first)
        return before;
      slw=slw->next;
    }
    while(slw!=fst);
    licznik++;
    before=first;
    first=first->next;
  }
}

int main()
{
  node *lista=NULL;
  addend(lista, 7);
  addend(lista, 8);
  addend(lista, 7);
  addend(lista, 7);
  node *srodek=new node;
  srodek->w=69;
  addnode(lista, srodek);
  addend(lista, 7);
  addend(lista, 5);
  last(lista)->next=srodek;
  cout << ptrbefcycle(lista)->w;
  //print(lista);
	return 0;
}
