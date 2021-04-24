
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
