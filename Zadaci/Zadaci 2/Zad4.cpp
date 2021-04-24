/*
Svaki paran broj se može prikazati kao suma dva prosta broja (tkz. Goldbachovo pravilo).
Napisati program koji će najprije učitati dva prirodna broja n1 i n2 (n2 > n1).
Zatim prikazati sve parne brojeve u intervalu od n1 do n2 kao sumu dva prosta broja.
(U glavnom programu samo unijeti navedena dva prirodna broja i pozvati funkciju koja obavlja zadani posao.)
*/
#include<iostream>
using namespace std;

int unosBroja();
bool prostBroj(int);
void goldbach(int);
void ispis(int, int);
int main()
{
	srand(time(0));
	int n1, n2;
	n1 = unosBroja();
	n2 = unosBroja();

	ispis(n1, n2);

	return 0;
}
int unosBroja()
{
	int broj;
	broj = rand() % 1000 + 10;
	return broj;
}
bool prostBroj(int x)
{
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	if (x == 1)
	{
		return false;
	}
	return true;
}
void goldbach(int broj)
{
	for (int i = broj / 2, j = broj / 2; i <= broj; i++, j--)//
	{
		if (prostBroj(i) && prostBroj(j))
		{
			cout << broj << " = " << i << " + " << j << endl;
			break;//moze a i ne mora

		}
	}
}
void ispis(int n1, int n2)
{
	if (n1 % 2 != 0)
	{
		n1++;
	}
	if (n1>n2)
	{
		int temp = n1;
		n1 = n2;
		n2 = temp;
	}
	for (int i = n1; i < n2; i += 2)
	{
		goldbach(i);
	}
}