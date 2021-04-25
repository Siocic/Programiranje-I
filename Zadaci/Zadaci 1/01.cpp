
#include<iostream>
using namespace std;

char odabir();
float proracun(int);
int main()
{
	float x;
	

	cout << "Unesite realan broj: ";
	cin >> x;

	cout << "Rezultat je: " << proracun(x) << endl;

	return 0;
}
char odabir()
{
	char izbor;

	do
	{
		cout << "Unesite s - sinus i c - cosinus: ";
		cin >> izbor;

	} while (izbor!='s' && izbor!='c');

	return izbor;
}
float proracun(int x)
{
	float rezulutat = 1;

	if (odabir()=='s')
	{
		for (int i = 1; i < x; i++)
		{
			rezulutat += i / (sin(x/ i)+x);
		}
		return rezulutat;
	}
	else
	{
		for (int i = 1; i < x; i++)
		{
			rezulutat += i / (cos(x / i) + x);
		}
		return rezulutat;
	}

}
