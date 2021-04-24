/*
Omogučiti unos dva broja X i Y iz intervala od 10 do 5000.
Kreirati program koji će pronaći i ispisati sve brojeve od X do Y (uključujući granične vrijednosti) za koje važi da je obrnuti broj djeljiv sa njegovom sumom cifara. 
Za olakšanje rješenja zadataka napraviri funkcije za obrtanje poretka cifara i za sumu cifara. 
Npr. Za broj 144 vrijedi da mu je suma cifara 9 i da je broj koji se dobije nakon što se njegove cifre obrnu 441, djeljiv sa 9.
Definišite vrijednosti intervala [X, Y]: 11 150 Brojevi koji ispunjuju dati uslov: 18 20 21 24 27
*/
#include<iostream>
using namespace std;

int obrniBroj(int);
int sumaCifri(int);
int main()
{
	int X, Y;

	do
	{
		cout << "X = ";
		cin >> X;
		cout << "Y = ";
		cin >> Y;

	} while (X<10 || X>5000 || Y<10 || Y>5000);
	if (X>Y)
	{
		int temp = X;
		X = Y;
		Y = temp;
	}
	cout << "Brojevi koji ispunjuvaju uslov su: ";
	for (int i = X; i <= Y; i++)
	{
		if (obrniBroj(i) % sumaCifri(i) == 0)
		{
			cout << i << " ";
		}
	}


	return 0;
}
int obrniBroj(int broj)
{
	int noviBroj = 0;
	while (broj>0)
	{
		int cifra= broj % 10;
		noviBroj = noviBroj * 10 + cifra;
		broj /= 10;
	}

	return noviBroj;
}
int sumaCifri(int broj)
{
	int suma = 0;
	while (broj>0)
	{
		suma += broj % 10;
		broj /= 10;
	}
	return suma;
}