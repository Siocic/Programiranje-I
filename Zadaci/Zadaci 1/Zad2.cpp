/*
Napisati program u kojem je potrebno unijeti odabrani broj cifara počevši od cifre najveće težinske vrijednosti, 
pa od njih sastaviti i napisati prirodni broj. Unos cifara se prekida kada se unese broj manji od 0, ukoliko korisnik unese cifru veću od 9, ispisati poruku da cifra nije validna, ali se unos ne prekida.

(Obavezno koristiti barem jednu korisnički definisanu funkciju)

Ispis neka bude oblika:
Upisi cifru: 2
Upisi cifru: 8
Upisi cifru: 72
Cifra nije validna
Upisi cifru: -1
Broj sastavljen od zadanih cifara je 28.
*/
#include<iostream>
using namespace std;
int sastavi(int, int&);
int main()
{
	int broj, rez = 0;
	do
	{
		cout << "Upisi cifru: ";
		cin >> broj;
		if (broj > 9)
		{
			cout << "Cifra nije validna." << endl;
		}
		else if (broj > 0)
		{
			sastavi(broj, rez);
		}
	} while (broj >= 0);

	cout << "Broj sastavljen od zadanih cifara " << rez << endl;
	system("pause>0");
	return 0;
}
int sastavi(int broj, int& rez)
{
	return rez = rez * 10 + broj;
}