
#include<iostream>
#include<cmath>
using namespace std;

bool prostBroj(int);
int obrniBroj(int);
int brojPalindrom(int);
bool provjeraBroja(int broj);
int main()
{
	//srand(time(0));/*broj=rand()%999+100,*/
	int broj;

	do
	{
		cout << "Unesite broj veci od 100: ";
		cin >> broj;

		if (provjeraBroja(broj))
		{
			cout << "Broj " << broj << " je prost i palindrom " << endl;
		}
		else if (prostBroj(broj))
		{
			cout << "Broj " << broj << " je samo prost. " << endl;
		}
		else if (brojPalindrom(broj))
		{
			cout << "Broj " << broj << " je samo palindrom. " << endl;
		}
		else
		{
			cout << "Broj nije ni prost ni palindrom. " << endl;
		}
	} while (broj<100);


	return 0;
}
bool prostBroj(int broj)
{
	for (int i = 2; i <= broj / 2; i++)
	{
		if (broj % i == 0)
		{
			return false;
		}

	}
	return true;
}
int obrniBroj(int broj)
{
	int noviBroj = 0;
	while (broj > 0)
	{
		noviBroj = noviBroj * 10 + broj % 10;
		broj /= 10;
	}
	return noviBroj;

}
int brojPalindrom(int broj)
{
	return broj == obrniBroj(broj);
}
bool provjeraBroja(int broj)
{
	return prostBroj(broj) && brojPalindrom(broj);
}
