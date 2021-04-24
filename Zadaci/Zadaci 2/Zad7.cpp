/*
Napisati program koji će omogućiti korisniku unos broja n (uz uslov 10 <= n <= 1000).
Zatim simulirati unos n slučajnih vrijednosti. Simuliranje unosa ostvariti funkcijom rand() % 1000 + 1.
Izračunati statističke podatke u kojem procentu se od n generisanih slučajnih vrijednosti pojavljuje prost broj.
Npr. Ako je generisano 10 brojeva (n = 10): 5,7,4,13,17,20,25,23,30,45, u ovom uzorku od 10 brojeva postoji 5 prostih brojeva pa je procenat prostih brojeva u ovom slučaju 50%.
(Napomena: Po želji kreirati dodatne funkcije da se olakša rješavanje zadatka.)
*/
#include<iostream>
using namespace std;

int simulacija();
bool prostBroj(int);
int procenatBrojeva(int);
int main()
{
	srand(time(0));
	int n;
	do
	{
		cout << "Unesite n: ";
		cin >> n;

	} while (n <= 10 || n >= 1000);

	cout << "Procenat prostih brojeva je " << procenatBrojeva(n) << " % " << endl;


	return 0;
}
int simulacija()
{
	int broj;
	broj = rand() & 1000 + 1;
	return broj;
}
bool prostBroj(int broj)
{
	for (int i = 2; i <= broj; i++)
	{
		if (i % 2 == 0)
		{
			return false;
		}
	}
	return true;
}
int procenatBrojeva(int broj)
{
	int brojac = 0;
	int procenat = 0;
	int noviBroj;
	for (int i = 0; i < broj; i++)
	{
		noviBroj = simulacija();
		//cout << noviBroj;//mozemo i ovako ispisati samo nema potrebe za uslovima ispod
		if (prostBroj(noviBroj))
		{
			cout << noviBroj << " je prost ";
		}
		else
		{
			cout << noviBroj << " nije prost ";
		}
		// << ((prostBroj(noviBroj)) ? " je prost" : " nije prost");
		cout << endl;
		if (prostBroj(noviBroj))
		{
			brojac++;
		}
	}
	procenat = (100 * brojac) / broj;
	return procenat;
}