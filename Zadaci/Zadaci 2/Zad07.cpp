
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
