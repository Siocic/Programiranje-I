/*
Napisati program koji korisniku omogućava unos realnog broja x, cijelog broja m i odabir funkcije za proračun datog izraza.
Korisnik bira funkciju unosom sljedećih karaktera 's' (sin), 'c' (cos), 'q' (sqrt), 'p' (pow).
U slučaju da korisnik unese karakter koji ne odgovara niti jednoj od predefinisanih vrijednosti ispisati odgovarajuću poruku i ponoviti odabir.
Funkciji pow postavite broj 2 za drugi parametar.
*/
#include<iostream>
using namespace std;

char odabir();
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
char odabir()
{
	char izbor;
	do
	{
		cout << "Unesite s - sinus, c - cosinus, q - sqrt, p - pow: ";
		cin >> izbor;
		if (izbor != 's' && izbor != 'c' && izbor != 'q' && izbor != 'p')
		{
			cout << "Pogresan unos." << endl;
		}

	} while (izbor!='s' && izbor!='c' && izbor!='q' && izbor!='p');

	return izbor;
}
float rezultat(float x, int m)
{
	int rez = 0;
	switch (odabir())
	{
	  case 's':
	  {
		  for (int i = 1; i <= m; i++)
		  {
			  rez += i / (sin(x / i) + x);
		  }
		  return rez;
	  }
	  break;
	  case 'c':
	  {
		  for (int i = 1; i <= m; i++)
		  {
			  rez += i / (cos(x / i) + x);
		  }
		  return rez;
	  }
	  break;
	  case 'q':
	  {
		  for (int i = 1; i <=m; i++)
		  {
			  rez += i / (sqrt(x / i) + x);
		  }
		  return rez;
	  }
	  break;
	  case 'p':
	  {
		  for (int i = 1; i <=m; i++)
		  {
			  rez += i / (pow(x / i, 2) + x);
		  }
		  return rez;
	  }
	  break;
	  default:
	  {
		  cout << "Unos nije validan." << endl;
	  }
	}
}
