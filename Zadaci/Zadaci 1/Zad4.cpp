/*
Poštujući sve faze procesa programiranja, napisati program koji korisniku omogućava unos cijelog broja N, te izračunava vrijednost sume faktorijela neparnih brojeva u intervalu [1, N]. 
Suma faktorijela prikazana je sljedećom formulom: S = 1! + 3! + 5! + ... + N!
*/
#include<iostream>
using namespace std;

int faktorijel(int);
int sumaFaktorijela(int);
int main()
{
	int N;

	cout << "Unesite broj N: ";
	cin >> N;

	cout << "Suma faktorijela neparnih brojeva je: " << sumaFaktorijela(N) << endl;

	return 0;
}
int faktorijel(int N)
{
	int faktorijel = 1;
	for (int i = 1; i <= N; i++)
	{
		faktorijel *= i;
	}
	return faktorijel;
}
int sumaFaktorijela(int N)
{
	int suma = 0;
	for (int i = 1; i <=N; i+=2)
	{
		suma += faktorijel(i);
	}
	return suma;
}