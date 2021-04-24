/*
Poštujući sve faze programiranja napisati program koji omogućava unos prirodnog broja n preko tastature te izračunava sumu:
*/
#include<iostream>
using namespace std;
float suma(int);
int main()
{
	int n;
	do
	{
		cout << "Unesite n: ";
		cin >> n;	
		if (n<1)
		{
			cout << "Broj nije prirodan." << endl;
		}
	} while (n<1);

	cout << "Suma je: " << suma(n) << endl;	

	return 0;
}
float suma(int n)
{
	float suma = 0;
	for (int i = 1; i <= n; i++)
	{
		suma += 1 / pow(2 * i + 1, 2);
	}
	return suma;
}
