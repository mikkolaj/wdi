#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int maxa=25;
int tab[maxa];

void quicksort(int tab[], int l, int p)
{
  if(p<=l)
    return;
  int pivot=tab[l], i=l, j=p;
  while(1)
  {
    while(tab[i]<pivot)
      i++;
    while(tab[j]>pivot)
      j--;
    if(i<=j)
    {
      int temp=tab[i];
      tab[i]=tab[j];
      tab[j]=temp;
      i++;
      j--;
    }
    else
      break;
  }
  if(j>l)
    quicksort(tab, l, j);
  if(i<p)
    quicksort(tab, i, p);
  
}

int main()
{
	srand(time(NULL));
	for(int i=0; i<maxa; i++)
	{
	  tab[i]=rand()%100+1;
	  cout << tab[i] << ' ';
  }
  cout << endl;
  quicksort(tab, 0, maxa-1);
  for(int i=0; i<maxa; i++)
	{
	  cout << tab[i] << ' ';
  }
  cout << endl;
	return 0;
}
