#include <iostream>
#include <cmath>

using namespace std;
const int N = 5;


int pary(int tab1[], int tab2[]){
	int pary=0;
	int k=pow(2, N);	
	for(int i=1; i<k; i++)
  {
	  int ic=i, sumai=0;
    int liczniki=0, paryi=0;
    
	  while(ic!=0)
    {
			if(ic%2==1)
      {
				sumai+=tab1[liczniki];
				paryi++;
			}
			ic/=2;
			liczniki++;
		}
		
		for(int j=1; j<k; j++)
    {
      int jc=j, sumaj=0;
      int licznikj=0, paryj=0; 
         
			while(jc!=0)
      {
				if(jc%2==1)
        {
					sumaj+=tab2[licznikj];
					paryj++;
				}
				jc/=2;
				licznikj++;
			}
			
			if(sumai==sumaj && paryi==paryj && paryj>pary)
				pary=paryj;
		}
	}	
	return pary;
}

int main(){
	int tab1[5]={1,4,40,7,700};
	int tab2[5]={2,2,50,8,500};
	cout << pary(tab1, tab2) << endl;
	return 0;
}
