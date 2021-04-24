/*
Napisati program koji omogućava unos pozitivnog broja n te pronalazi njegove parne cifre i formira novi broj u kojem su parne cifre zamijenjene cifrom '5'.
Dodatno program treba ispisati razliku unesenog i broja koji se dobije nakon zamjene.
*/
#include<iostream>
using namespace std;

int zamijeniBroj(int);
int main()
{
	int n;
	do
	{
		cout << "Unesite n: ";
		cin >> n;

	} while (n<0);

	int noviBroj = zamijeniBroj(n);
	cout << "Novi broj: " << noviBroj << endl;
	cout << "Razlika je: " << abs(n - noviBroj) << endl;


	return 0;
}
int zamijeniBroj(int n)
{
	int noviBroj = 0;
	int cifra;
	int brojac = 0;

	while (n>0)
	{
		cifra = n % 10;

		if (cifra%2==0)
		{
			noviBroj = noviBroj + 5 * pow(10.0, brojac);
			brojac++;
			n /= 10;
		}
		else
		{
			noviBroj = noviBroj + cifra * pow(10.0, brojac);
			brojac++;
			n /= 10;
		}
	}
	return noviBroj;
}