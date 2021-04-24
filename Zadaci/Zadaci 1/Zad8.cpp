/*
Poštujući sve faze procesa programiranja, napisati program koji učitava prirodni broj n veći od 10 i prirodan broj X. 
Program treba izračunati i ispisati vrijednost S izračunatu prema.
S=3!-6!+9!-...+(-1)*n+1*(3n)!
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n, X;
			

	do
	{
		cout << "Unesite broj A: ";
		cin >> n;
		cout << "Unesite broj B: ";
		cin >> X;

	} while (n <= 10 && X < 1);

	double S = 0;
	for (int i = 0; i < n; i++)
	{
		S += pow(-1, i) * i / pow(X, i);
	}

	cout << S;
	return 0;
}