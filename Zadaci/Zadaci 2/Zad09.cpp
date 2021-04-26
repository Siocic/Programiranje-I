
#include<iostream>
using namespace std;

float rezultat(float, int);
int main()
{
	float x;
	int m;

	cout << "Unesite realan broj: ";
	cin >> x;
	cout << "Unesite cijeli broj: ";
	cin >> m;

	cout << "Rezultat je: " << rezultat(x, m) << endl;

	
	
	return 0;

}
float rezultat(float x, int m)
{
	float rez = 1;
	char izbor;
	do
	{
		cout << "Unesite s - (sin), c - (cos), q - (sqrt), p - (pow): ";
		cin >> izbor;
		if (izbor != 's' && izbor != 'c' && izbor != 'q' && izbor != 'p')
		{
			cout << "Pogresan unos. Molimo Vas unesite ponovo " << endl;
		}

	} while (izbor!='s' && izbor!='c' && izbor!='q' && izbor!='p');

	switch (izbor)
	{
		case 's':
		{
			for (int i = 1; i <= m; i++)
			{
				rez += (sin(x) + i);
			}
			return rez;
		}
		break;
		case 'c':
		{
			for (int i = 1; i <= m; i++)
			{
				rez += (cos(x) + i);
			}
			return rez;
		}
		break;
		case 'q':
		{
			for (int i = 1; i <= m; i++)
			{
				rez += (sqrt(x) + i);
			}
			return rez;
		}
		break;
		case 'p':
		{
			for (int i = 1; i <= m; i++)
			{
				rez += (pow(x, 3) + i);
			}
			return rez;
		}
		break;
		default:
		{
			cout << "Greska!" << endl;
		}
	}
}
