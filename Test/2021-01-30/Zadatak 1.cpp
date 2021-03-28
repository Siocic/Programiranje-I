
#include<iostream>
using namespace std;

char odabir();
void izracunaj(int);

int main()
{
	float x;
	
	cout << "Unesite x: ";
	cin >> x;

	izracunaj(x);

	return 0;
	system("pause>0");
}
char odabir()
{
	char a;
	do
	{
		cout << "Unesite s za sinus a c cosinus da izracunamo izraz: ";
		cin >> a;
		if (a!='s' && a!='c')
		{
			cout << "Pogresan unos. Molimo Vas unesite ponovo." << endl;
		}

	} while (a!='s' && a!='c');

	return a;
}
void izracunaj(int x)
{
	float rez = 1;
	if (odabir() == 's')
	{
		for (int i = 1; i < x; i++)
		{
			rez += i / (sin(x / i) + x);

		}
	}
	else
	{
		for (int i = 1; i < x; i++)
		{
			rez += i / (cos(x / i) + x);

		}
	}
	
	cout << "Rezultat je: " << rez << endl;
}