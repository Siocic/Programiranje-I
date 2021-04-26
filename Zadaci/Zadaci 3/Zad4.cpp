#include<iostream>
using namespace std;


void Rekurzija(int* niz, int brojac, int n, int faktorijel);
void Ispis(int* niz, int brojac, int n);

int main()
{
	srand(time(NULL));

	int n;
	do
	{
		cout << "Unesite zeljenu vrijednost velicine niza: ";
		cin >> n;
	} while (n <= 0);

	int* niz = new int[n];


	Rekurzija(niz, 0, n, 1);//faktorijel=1 
	Ispis(niz, 0, n);

	delete[]niz;
	niz = nullptr;

	system("pause>0");
	return 0;
}

void Rekurzija(int* niz, int brojac, int n, int faktorijel)
{
	if (brojac == n || faktorijel < 0)
		return;
	*(niz + brojac) = faktorijel;//faktorijel = 1;
	faktorijel *= brojac + 2; // racuna faktorijel za 1=1*(0+2)=2 ()->zagrada element po redu
	//faktorijel=faktorijel*(brojac+2) 2=2*(1+2)=6->3! 6=6*(2+2)=24->4 24=24*(3+2)=120
	
	Rekurzija(niz, brojac + 1, n, faktorijel);
}

void Ispis(int* niz, int brojac, int n)
{
	if (brojac == n)
		return;
	cout << brojac + 1 << "! -----> " << *(niz + brojac) << endl;
	Ispis(niz, brojac + 1, n);
}
